#include <iostream>
#include <vector>
using namespace std;

//assumes operator< for Comparable
template <class Comparable>
void insertionSort( vector<Comparable> & a)
{

  for(int p = 1; p < 3;p++)
    {
      Comparable tmp = a[ p ];
      int j;

      for( j = p; j > 0 && tmp < a[ j - 1 ]; j--)
	a[ j ] = a[ j - 1 ];
      a[ j ] = tmp;
    }

}

int main()
{

  vector<int> b;

  b.push_back(5);
  b.push_back(7);
  b.push_back(3);
  
  int size = b.size( );
  for(int i = 0; i < size; i++)
    cout << b.at(i) << " ";

  insertionSort(b);
  
  cout << "\nafter sorting\n";
  for(int i = 0; i < size; i++)
    cout << b.at(i)<< " ";




  return 0;
}
