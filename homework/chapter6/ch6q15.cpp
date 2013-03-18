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
  //int n = 1000;
  //int n = 10000;
  int n = 100000;
  clock_t t1;
  t1 = clock();
  printf ("Calculating fragment #1...\n");
  for(int i = 0; i < n; i++)
    sum++;
  t1 = clock() - t1;
  printf ("It took me %ld clicks (%f seconds) for fragment #1.\n",t1,((float)t1)/CLOCKS_PER_SEC);

  clock_t t2;
  t2 = clock();
  printf ("Calculating fragment #2...\n");
  for(int i = 0; i < n; i += 2)
    sum++;
  t2 = clock() - t2;
  printf ("It took me %ld clicks (%f seconds) for fragment #2.\n",t2,((float)t2)/CLOCKS_PER_SEC);

  clock_t t3;
  t3 = clock();
  printf ("Calculating fragment #3...\n");
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      sum++;
  t3 = clock() - t3;
  printf ("It took me %ld clicks (%f seconds) for fragment #3.\n",t3,((float)t3)/CLOCKS_PER_SEC);

  clock_t t4;
  t4 = clock();
  printf ("Calculating fragment #4...\n");
  for(int i = 0; i < n; i++)
    sum++;
  for(int j = 0; j < n; j++)
    sum++;
  t4 = clock() - t4;
  printf ("It took me %ld clicks (%f seconds) for fragment #4.\n",t4,((float)t4)/CLOCKS_PER_SEC);
  
  clock_t t5;
  t5 = clock();
  printf ("Calculating fragment #5...\n");
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n * n; j++)
      sum++;
  t5 = clock() - t5;
  printf ("It took me %ld clicks (%f seconds) for fragment #5.\n",t5,((float)t5)/CLOCKS_PER_SEC);
  
  clock_t t6;
  t6 = clock();
  printf ("Calculating fragment #6...\n");
  for(int i = 0; i < n; i++)
    for(int j = 0; j < i; j++)
      sum++;
  t6 = clock() - t6;
  printf ("It took me %ld clicks (%f seconds) for fragment #6.\n",t6,((float)t6)/CLOCKS_PER_SEC);
  
  clock_t t7;
  t7 = clock();
  printf ("Calculating fragment #7...\n");
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n * n; j++)
	for(int k = 0; k < j; k++)
	  sum++;
  t7 = clock() - t7;
  printf ("It took me %ld clicks (%f seconds) for fragment #7.\n",t7,((float)t7)/CLOCKS_PER_SEC);

  
  return 0;
}
