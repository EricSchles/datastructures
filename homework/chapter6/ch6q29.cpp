#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
using namespace std;



void Sieve(int n)
{

  vector<double> table;

  for(double i = 0; i < n; i++)
    table.push_back(i);

  double squareRoot = sqrt(n);

  cout << " 1 ";
  int count = 1;
  for(double i = 2; i < squareRoot;i++)
    {
      
      if( table[i] != -1)
	{
	  cout << table[i] << " ";
	  int count = 1;
	  for(double j = i; j < n; j = i * count )
	    {
	      table[j] = -1;
	      count++;
	    }
	}
    }


} 


int main()
{

  clock_t t1,t2;
  t1 = clock();
  Sieve(10000);
  t2 = clock() - t1;

  cout <<"running time is: "<< (float)t2/CLOCKS_PER_SEC <<endl;

  return 0;
}
