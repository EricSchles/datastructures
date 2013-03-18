#include <iostream>
#include <stdio.h>
#include <ctime>
using namespace std;

int main()
{

  //declared constants
  int sum( 0 );
  //int n = 10;
  //int n = 100;
  int n = 1000;
  //int n = 10000;
  //int n = 100000;
  clock_t t1;
  t1 = clock();
  printf ("Calculating fragment #1...\n");
  for(int i = 0; i < n; i++)
    for( int j = 0; j < i * i; j++)
      if( j % i == 0 )
	for( int k = 0; k < j; k++)
	  sum++;
  t1 = clock() - t1;
  printf ("It took me %ld clicks (%f seconds) for fragment #1.\n",t1,((float)t1)/CLOCKS_PER_SEC);


  return 0;
}
