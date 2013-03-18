#include <iostream>

using namespace std;

template <class Comparable>
const Comparable & findMax( const vector<Comparable> & a)
{

  int maxIndex = 0;

  int size = a.size( ); //compiler complains
  for( int i = 1; i < size; i++)
    if( a[ maxIndex ] < a[ i ] )
      maxIndex = i;

  return a[ maxIndex ];

}
