#include <iostream>
using namespace std;

int gcd( const int a, const int b);


int main()
{
  int one = 35581;
  int two = 4196336;
  int result;

  result = gcd(one,two);

  cout << result;
  



  return 0;
}


int gcd( const int a, const int b)
{
  if( b == 0 )
    return a;
  else 
    return gcd( b, a % b);
}
