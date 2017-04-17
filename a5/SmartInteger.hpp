#include <ostream>
#include <limits>

class SmartInteger
{
public:
	SmartInteger();
	SmartInteger(int n);
	int getValue() const;
    friend std::ostream& operator<< (std::ostream& os, const SmartInteger& n);
    bool operator< (const SmartInteger& n);
    bool operator> (const SmartInteger& n);
    bool operator<= (const SmartInteger& n);
    bool operator>= (const SmartInteger& n);
    bool operator== (const SmartInteger& n);
    bool operator!= (const SmartInteger& n);
    SmartInteger operator+ (const SmartInteger& n);
    SmartInteger operator- (const SmartInteger& n);
    SmartInteger operator* (const SmartInteger& n);
    void operator+= (const SmartInteger& n);
    void operator-= (const SmartInteger& n); 
    void operator*= (const SmartInteger& n);
    SmartInteger operator-();
    void operator++(); 
    void operator--();

private:
	int num;
};
