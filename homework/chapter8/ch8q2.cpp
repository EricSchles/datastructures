#include <iostream>
using namespace std;

int s( int n )
{

  if( n < 0 )
    return 0;
  if( n == 1)
    return 1;
  else 
    return s( n - 1 ) + n;



}
