#include <iostream>
#include <vector>
using namespace std;

void makeChange( const vector<int> & coins, int maxChange, vector<int> & coinsUsed, vector<int> & lastCoin)
{

  int size = coins.size( );
  
  int max = coins[0];
  for(int j = 0; j < size; j++)
    {
      if( coins[j] > max)
	    max = coins[j];
    }

  
  for(int i = 0; i < size; i++)
    {
      
      
      
    }


}

int choose( int n, int r );
int fact( int n );

int main()
{






 
  return 0;
}

int choose( int n, int r )
{
 
  return fact(n)/( fact(n-r)* fact(r) );

}

int fact( int n )
{
  if( n == 1)
    return 1;
  if( n == 0)
    return 1;
  return n*fact(n-1);
}
