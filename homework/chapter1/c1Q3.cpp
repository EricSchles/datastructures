#include <iostream>
using namespace std;

int main()
{

  int a = 5; 
  int b = 7;  

  int & x = a;
  
  bool things;
  things = ( ( & *a ) == a);

  cout <<endl<< things <<endl;
  return 0;
}
