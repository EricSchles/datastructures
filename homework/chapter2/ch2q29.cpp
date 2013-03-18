#include <iostream>
#include <cmath>
#include <vector>
using namespace std;



void & Sieve(int n)
{

  vector<int> table(n);

  table.at(0) = 0;
  table.at(1) = 1;
  for(int i = 2; i < table.size( ); i++)
    table.at(i);

  squareRoot = sqrt(n);

  cout << " 1 ";
  count = 1;
  for(int i = 2; i < squareRoot;i++)
    {
      if( table[i] != -1)
	{
	  cout << table[i];
	  
	  for(int j = i; j < n; j*=count )
	    {
	      table[j] = -1;
	      count++;
	    }
	}
    }


} 


int main()
{

  Sieve(5);





  return 0;
}
