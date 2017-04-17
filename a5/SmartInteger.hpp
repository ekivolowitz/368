#include <ostream>
#include <limits>

class SmartInteger
{
public:
	SmartInteger();
	SmartInteger(int n);
	int getValue() const;
    friend std::ostream& operator<< (std::ostream& os, const SmartInteger& n);
    bool operator< (const SmartInteger& n) const;
    bool operator> (const SmartInteger& n) const;
    bool operator<= (const SmartInteger& n) const;
    bool operator>= (const SmartInteger& n) const;
    bool operator== (const SmartInteger& n) const;
    bool operator!= (const SmartInteger& n) const;
    SmartInteger operator+ (const SmartInteger& n);
    SmartInteger operator- (const SmartInteger& n);
    SmartInteger operator* (const SmartInteger& n);
    SmartInteger &operator+= (const SmartInteger& n);
    SmartInteger &operator-= (const SmartInteger& n); 
    SmartInteger &operator*= (const SmartInteger& n);
    SmartInteger operator-();
    SmartInteger &operator++(); 
    SmartInteger &operator--();

private:
	int num;
};
