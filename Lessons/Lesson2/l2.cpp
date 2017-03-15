//Streams
//	Are a linear queue reading data.

//cout <- character output to console.
// << is called a stream insertion operator and sends data to the stream.
// << works with strings, ints, doubles, etc. 
// << can be chained. For example cout << "Hello" << " World" << endl;

// cin >> where_you_want_to_put_the_string
// >> is the stream extraction operator which receives data from the stream and stores it in a variable. 

//if you cin >> notAnInteger

#include <iostream>
int main()
{
	ifstream inFile("students.txt");
	inFile >> myString;
	getline(inFile, myString);
	
	ofstream outFile("outputfile.txt");
	outFile << whatever << endl;

	if(inFile.is_open()) // or outFile.is_open()
	{
		//will run this code if the file is opened successfully.
	}

	if(std::cin.fail()) //useful when you're reading in integers, but you enter a string. If you enter a double, this won't catch it.
	{
		cout << "There was a failure" << std::endl;

	}

	return 0;
}
