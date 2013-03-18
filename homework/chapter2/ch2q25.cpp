#include <iostream>
#include <cmath>
using namespace std;

class INT
{
public:
  INT( int x )
    : data(x){ }
  INT( ) { }
  
  bool rangeCheck();


  INT operator=(INT rhs)
  {
    *this.data = rhs.data;
    return *this;
  }
  //binary operators
  INT operator+(INT lhs, INT rhs) 
  {
    bool range = false;
    *this.data = lhs.data + rhs.data;
    range = rangeCheck();
    if(range)
      {
	return;
      }
    return *this;
  }
  INT operator*(INT lhs, INT rhs) 
  {
    *this.data = lhs.data * rhs.data;
    return *this;
  }
  INT operator^(INT lhs, INT rhs)
  {
    *this.data = pow(lhs.data, rhs.data);
    return *this;
  }
  INT operator-(INT lhs, INT rhs) 
  {
    bool range = false;
    *this.data = lhs.data - rhs.data;
    range = rangeCheck();
    if(range)
      {
	return;
      }
    return *this;
  }

  INT operator/(INT lhs, INT rhs)
  {
    bool range = false;
    *this.data = lhs.data / rhs.data;
    range = rangeCheck();
    if(range)
      {
	return;
      }
    return *this;
  }
  
  INT operator-=(INT rhs)
  {
    bool range = false;
    *this = *this - rhs;
    range = rangeCheck();
    if(range)
      {
	return;
      }
    return *this;
  }

  INT operator*=(INT rhs)
  {
    *this = *this * rhs;
    return *this;
  }

  INT operator+=(INT rhs)
  {
    bool range = false;
    *this = *this + rhs;
    range = rangeCheck();
    if(range)
      {
	return;
      }
    return *this;
  }

  INT operator/=(INT rhs)
  {
    bool range = false;
    *this = *this / rhs;
    range = rangeCheck();
    if(range)
      {
	return;
      }
    return *this;
  }

  bool operator<(INT lhs, INT rhs) const
  {
    return lhs.data < lhs.data;
  }
  bool operator<=(INT lhs, INT rhs) const
  {
    return lhs.data <= rhs.data;
  }
  bool operator>=(INT lhs, INT rhs) const
  {
    return lhs.data >= rhs.data;
  }
  bool operator> (INT lhs, INT rhs) const
  {
    return lhs.data > rhs.data;
  }
  bool operator==(INT lhs, INT rhs) const
  {
    return lhs.data == rhs.data;
  }
  bool operator !=(INT lhs, INT rhs) const
  {
    return !(lhs == rhs);
  }
  
private:
  int data;

};

bool INT::rangeCheck()
{
  int max = pow(2,15);
  if( *this.data > max)
    {
      cout << "Out of range!!!";
      return true;
    }
  else
    return false;

}
