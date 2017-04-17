//http://stackoverflow.com/questions/199333/how-to-detect-integer-overflow-in-c-c
#include "SmartInteger.hpp"
#include <iostream>


SmartInteger::SmartInteger()
{
    num = 0;
}

SmartInteger::SmartInteger(int n)
{
    num = n;
}

int SmartInteger::getValue() const
{
    return num;
}


std::ostream& operator<<(std::ostream& os, const SmartInteger& n)
{
    os << n.getValue();
    return os;
}

bool SmartInteger::operator<(const SmartInteger& n) const
{
    if(getValue() < n.getValue()) return true;
    else return false;
}

bool SmartInteger::operator>(const SmartInteger& n) const
{
    if(getValue() > n.getValue()) return true;
    else return false;
}

bool SmartInteger::operator<=(const SmartInteger& n) const
{
    if(getValue() <= n.getValue()) return true;
    else return false;
}

bool SmartInteger::operator>=(const SmartInteger& n) const
{
    if(getValue() >= n.getValue()) return true;
    else return false;
}

bool SmartInteger::operator==(const SmartInteger& n) const
{
    if(getValue() == n.getValue()) return true;
    else return false;
}

bool SmartInteger::operator!=(const SmartInteger& n) const
{
    if(getValue() != n.getValue()) return true;
    else return false;
}

SmartInteger SmartInteger::operator+ (const SmartInteger& n)
{
    int max = std::numeric_limits<int>::max();
    int min = std::numeric_limits<int>::min(); 
   
    std::cout << num << " + " << n.getValue() << std::endl;

    //If LHS is max and RHS is +
    //This throws the exception properly.
    if(num == max && n.getValue() > 0) throw std::exception();

    //If LHS is min and RHS is -
    //This throws the exception properly.
    if(num == min && n.getValue() < 0) throw std::exception();

    //If RHS is max and LHS is +
    //This throws the exception properly.
    if(n.getValue() == max && num > 0) throw std::exception();

    //If RHS is min and LHS is -
    //This throws the exception properly.
    if(n.getValue() == min && num < 0) throw std::exception();

    //If LHS is + and RHS is + and the sum goes over max
    //This throws the exception properly.
    if((num > 0 && n.getValue() > 0) && (n.getValue() > (max - num))) throw std::exception();

    //If LHS is - and RHS is - and the sum goes below min
    //This throws the exception properly.
    if((num < 0 && n.getValue() < 0) && (num < (min - n.getValue()))) throw std::exception();



    SmartInteger x = (getValue() + n.getValue());
    return x; 
}

SmartInteger SmartInteger::operator- (const SmartInteger& n)
{
    int max = std::numeric_limits<int>::max();
    int min = std::numeric_limits<int>::min(); 
    if((n.getValue() > 0 || getValue() > 0) && (getValue() < max + n.getValue() || n.getValue() < max + getValue())) throw std::exception();
    else if((n.getValue() < 0 || getValue() < 0) && (getValue() > min - n.getValue()) || n.getValue() > min - getValue()) throw std::exception();

    SmartInteger x = (getValue() - n.getValue());
    return x;

}

SmartInteger SmartInteger::operator* (const SmartInteger& n)
{
    int max = std::numeric_limits<int>::max();
    int min = std::numeric_limits<int>::min();
    
    if (getValue() == -1 || n.getValue() == -1)
    {
        if((n.getValue() == min || getValue() == min)) throw std::exception();
    }
    else if (getValue() > (max / n.getValue())) throw std::exception();
    else if ((getValue() < min / n.getValue())) throw std::exception();
    
    SmartInteger x = getValue() * n.getValue();
    return x;
}

SmartInteger &SmartInteger::operator+= (const SmartInteger& n)
{
    try
    {
        SmartInteger l = (*this + n);
        num = l.getValue();
        return (*this);
    }
    catch(std::exception e)
    {
        throw e;
    }
}

SmartInteger &SmartInteger::operator-= (const SmartInteger &n)
{
    try
    {
        SmartInteger l = (*this - n);
        num = l.getValue();
        return (*this);
    }
    catch(std::exception e)
    {
        throw e;
    }
}

SmartInteger &SmartInteger::operator*= (const SmartInteger &n)
{
    try
    {
        SmartInteger l = (*this * n);
        num = l.getValue();
        return (*this);
    }
    catch(std::exception e)
    {
        std::cout <<"Nothing to see here folks" << std::endl;
    }
}

SmartInteger SmartInteger::operator-()
{
    try
    {
        SmartInteger l = -1;
        return (*this) * l;
    }
    catch(std::exception e)
    {
        throw e;
    }
}

SmartInteger &SmartInteger::operator++()
{
    try
    {
        SmartInteger l = (*this + 1);
        num = l.getValue();
        return *this;
    }
    catch(std::exception e)
    {
        throw e;
    }
}

SmartInteger &SmartInteger::operator--()
{
    try
    {
        SmartInteger l = (*this - 1);
        num = l.getValue();
        return *this;
    }
    catch(std::exception e)
    {
        throw e; 
    }
}
