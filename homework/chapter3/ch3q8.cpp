#include <iostream>

using namespace std;

template <class Comparable>
void insertionSort( Comparable a[], int size)
{

  for(int p = 1; p < size; p++)
    {

      Comparable tmp = a[ p ];
      int j;
      
      for( j = p; j > 0 && tmp < a[ j - 1]; j--)
	a[ j ] = a[ j - 1 ];
      a[ j ] = tmp;
    }

}


int main()
{

  int SIZE = 10;

  int arr[SIZE];

  for(int i = 0; i < SIZE; i++)
    arr[i] = 4;

  arr[4] = 10;
  arr[5] = 7;
  arr[1] = 0;

  insertionSort( arr, SIZE);

  for( int j = 0; j < SIZE;j++)
    cout << arr[j] << " "; 

  return 0;
}
