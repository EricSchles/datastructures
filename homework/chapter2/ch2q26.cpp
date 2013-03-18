#include <iostream>
#include <cmath>
using namespace std;



//unfinished!!!
// 0xff00 is 1111 1111 0000 0000
// 0x00ff is 0000 0000 1111 1111



class INT
{
public:
  
  INT( int x)
    : leading( x>>16 & 0xff00 ), trailing( x<<16 & 0x00ff ){ }
   
  INT( ) { }
  
  bool rangeCheck();


  INT operator=(int rhs)
  {
    *this.leading = rhs>>16 & 0xff00;
    *this.trailing = rhs<<16 & 0x00ff;
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
    bool lead = false;
    bool trail = false;
    lead = lhs.leading == rhs.leading;
    trail = lhs.trailing == lhs.trailing;
    return lead && trail;
  }
  bool operator !=(INT lhs, INT rhs) const
  {
    return !(lhs == rhs);
  }
  
private:
  //each are 16 bit numbers
  short leading;
  short trailing;
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
