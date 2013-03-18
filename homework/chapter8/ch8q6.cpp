#include <iostream>
using namespace std;


void fullgcd( const int a, const int b, int x, int y)
{

  int x1,y1;

  if( b == 0 )
    {
      x = 1;
      y = 0;

    }
  else
    {
      fullgcd( b, a % b, x1, y1);
      x = y1;
      y = x1 - ( a/b ) * y1;
    }

}

int inverse( const int a, const int b )
{

  int x, y;
  
  fullgcd( a, b, x, y);
  return x > 0 ? x : x + b;
}



int main()
{

  int one = 35581;
  int two = 1440;
  int result;
  result = inverse(35581,1440);
  cout << result;
 

  return 0;
}
