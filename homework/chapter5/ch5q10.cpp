#include <iostream>



class EqualsK
{
  EqualsK(int init = 0 )
    :init(k) { }
  
  bool operator() (int input)
  {
    return input == k;
  }


private:
  int k;
};
