#!/bin/bash

# Global constants
readonly DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
readonly CODE_DIR="/p/course/cs368-isung/public/tests/a1"
readonly NUM_TESTS=4

# Exits if the necessary files do not exist.
check_files_exist() {
    if [ ! -f "./a1.cpp" ]; then
        (>&2 echo "Error: could not find a1.cpp, exiting")
        exit 1
    fi
    if [ ! -d "./testfiles" ]; then
        (>&2 echo "Error: could not find testfiles/, exiting")
        exit 1
    fi

    local flag=0
    local i
    for ((i=0; i<NUM_TESTS; i++))
    do
        if [ ! -f "./testfiles/input$i"".txt" ]; then
            (>&2 echo "Error: could not find testfiles/input$i"".txt")
            flag=1
        fi
        if [ ! -f "./testfiles/soln$i"".txt" ]; then
            (>&2 echo "Error: could not find testfiles/soln$i"".txt")
            flag=1
        fi
    done
    if ((flag == 1)); then
        (>&2 echo "Please fix the above errors, exiting")
        exit 1
    fi
}

# Prints warnings if test files have been changed.
check_files_unchanged() {
    local cmp_msg
    local cmp_status
    cmp_msg=$(cmp "./test.sh" "$CODE_DIR/test.sh" 2>&1)
    cmp_status=$?
    if ((cmp_status != 0)); then
        (>&2 echo "Warning: $cmp_msg")
    fi

    local i
    for ((i=0; i<NUM_TESTS; i++))
    do
        cmp_msg=$(cmp "./testfiles/input$i"".txt" "$CODE_DIR/testfiles/input$i"".txt" 2>&1)
        cmp_status=$?
        if ((cmp_status != 0)); then
            (>&2 echo "Warning: $cmp_msg")
        fi
        cmp_msg=$(cmp "./testfiles/soln$i"".txt" "$CODE_DIR/testfiles/soln$i"".txt" 2>&1)
        cmp_status=$?
        if ((cmp_status != 0)); then
            (>&2 echo "Warning: $cmp_msg")
        fi
    done
}

# Greps through the code files, and exits if anything is wrong.
check_code_text() {
    local mutable_count=$(grep -ow "mutable" ./a1.cpp | wc -l)
    local volatile_count=$(grep -ow "volatile" ./a1.cpp | wc -l)
    local flag=0
    if ((mutable_count > 0)); then
        (>&2 echo "Error: there are more than 0 occurrences of the word \"mutable\" in a1.cpp")
        flag=1
    fi
    if ((volatile_count > 0)); then
        (>&2 echo "Error; there are more than 0 occurrences of the word \"volatile\" in a1.cpp")
        flag=1
    fi
    if ((flag == 1)); then
        (>&2 echo "Please fix the above errors, exiting")
        exit 1
    fi
}

# Runs the test case specified by the argument.
# @param $1: the integer corresponding to the test case
# @return 0 if the test passes, or 1 if it fails
run_test() {
    echo "Running test case $1..."
    local flag=0
    if [ ! -f ./testfiles/input"$1".txt ]; then
        (>&2 echo "Error: could not find file testfiles/input""$1"".txt")
        flag=1
    elif [ ! -f ./testfiles/soln"$1".txt ]; then
        (>&2 echo "Error: could not find file testfiles/soln""$1"".txt")
        flag=1
    else
        local exit_code
        local cmp_status
        ./test < ./testfiles/input"$1".txt > ./output.txt 2> ./error.txt
        exit_code=$?
        cmp ./output.txt ./testfiles/soln"$1".txt > /dev/null 2>&1
        cmp_status=$?
        if ((exit_code != 0)); then
            (>&2 echo "Error: your code exited with status $exit_code")
            flag=1
        fi
        if ((cmp_status != 0)); then
            (>&2 echo "Error: the following (incorrect) output was printed to stdout:")
            (>&2 cat ./output.txt)
            flag=1
        fi
        if [ -s ./error.txt ]; then
            (>&2 echo "Error: the following output was printed to stderr:")
            (>&2 cat ./error.txt)
            flag=1
        fi
        rm -rf ./output.txt ./error.txt
    fi

    return $flag
}

main() {
    cd "$DIR"

    if (($# > 0)); then
        (>&2 echo "Error: expected no arguments")
        (>&2 echo "USAGE: ./test.sh")
        exit 1
    fi

    check_files_exist

    check_files_unchanged

    check_code_text

    # Compile code into ./test
    local build_status
    g++ -std=c++11 ./a1.cpp -o ./test
    build_status=$?
    if ((build_status != 0)); then
        (>&2 echo "Error: could not compile a1.cpp, exiting")
        exit 1
    fi

    # Run tests
    local passed_test_count=0
    local i
    for ((i=0; i<NUM_TESTS; i++))
    do
        run_test "$i"
        local retval=$?
        if ((retval == 0)); then
            echo "Test $i passed"
            ((passed_test_count += 1))
        else
            echo "Test $i failed"
        fi
        echo
    done
    rm -rf ./test

    # Success (possibly)
    echo "$passed_test_count/$NUM_TESTS tests passed"
    if ((passed_test_count < NUM_TESTS)); then
        exit 1
    else
        return 0
    fi
}

main "$@"
