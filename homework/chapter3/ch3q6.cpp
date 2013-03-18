#include <iostream>
using namespace std;


class Greater
{
public:
  int data;

  bool operator<(Greater rhs)
  {
    return *this.data < rhs.data;
  }
  //assumes operator< already exists...
  bool operator>(Greater rhs)
  {
    return rhs.data < *this.data;
  }

};
