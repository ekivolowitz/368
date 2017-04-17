#include "SmartInteger.hpp"
#include <iostream>


int main() {
    /*
    std::cout << "Constructing n1 and n2..." << std::endl;
    SmartInteger n1(3);
    SmartInteger n2;
    std::cout << "n1.getValue() should be 3: " << n1.getValue() << std::endl;
    std::cout << "n2.getValue() should be 0: " << n2.getValue() << std::endl;
    std::cout << std::endl;
    
    // No need to implement custom copy assignment operator - this should just work
    std::cout << "Changing value of n2..." << std::endl;
    n2 = 3;
    std::cout << "n2.getValue() should be 3: " << n2.getValue() << std::endl;
    std::cout << std::endl;

    // No need to implement custom copy constructor - this should just work
    std::cout << "Constructing n3..." << std::endl;
    SmartInteger n3(n2);
    std::cout << "n3.getValue() should be 3: " << n3.getValue() << std::endl;
    std::cout << std::endl;
    // Add more code here!
*/

    SmartInteger min =  std::numeric_limits<int>::min();
    SmartInteger n1(2);
    SmartInteger t1 = 5;
    SmartInteger t2 = 6;
    SmartInteger n2(-3);
    
    std::cout << "n4 + n2 = " << min + n2 << std::endl;

/*
    
    bool result1 = t1 < t2;//True
    bool result2 = t1 > t2;//False
    
    bool result3 = t1 > t2;//False
    bool result4 = t1 < t2;//True

    bool result5 = t0 <= t1;//True
    bool result6 = t0 >= t1;//False
    bool result7 = t1 <= t1;//True
    
    bool result8 = t0 >= t1;//False
    bool result9 = t0 <= t1;//True
    bool result10 = t0 <= t0;//True

    SmartInteger max =  std::numeric_limits<int>::max();
    SmartInteger min =  std::numeric_limits<int>::min();
    std::cout << "T1 before: " << t1 << std::endl;
    t1 += t2;
    std::cout << "T1 after adding t2: " << t1 << std::endl;
    //t1 += s;
    //std::cout <<"T1 after trying to add max: " << t1 << std::endl;
    //std::cout <<"testing min underflow" <<std::endl; 
    //t1 -= min; 
    //std::cout <<"Testing for *= overflow" << std::endl;
    //t1 = t1 * max;
    
    //std::cout <<"Testing -SmartInteger t1. Output should be -5: "<<-min <<std::endl;
    std::cout << t1 << std::endl;
    --t1;
    std::cout << t1 << std::endl;
  */  
    return 0;
}
