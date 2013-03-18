#include <iostream>
using namespace std;

//part a
template<class Comparable>
class less
{
public:
  
  //assumes Comparable has operator<
  
  bool operator() ( Comparable lhs, comparable rhs)
  {
    return lhs < rhs;
  }


private:
};

//part b
//assumes operator< is defined for Comparable
template< class Comparable>
const Comparable & findMax( const vector<Comparable> & a)
{
  return findMax( a, less);

}
//Assumes operator< is defined for Object
template <class Object, class Comparator>
const Comparable & findMax( const vector<Object> & a, Comparator isLessThan)
{

  int maxIndex = 0;

  int size = a.size( ); //compiler complains
  for( int i = 1; i < size; i++)
    if( isLessThan( a[ maxIndex ], a[ i ] )
      maxIndex = i;

  return a[ maxIndex ];

}

//part c
template <class Object, class Comparator>
const Comparable & findMax( const vector<Object> & a, Comparator isLessThan = less)
{

  int maxIndex = 0;

  int size = a.size( ); //compiler complains
  for( int i = 1; i < size; i++)
    if( isLessThan( a[ maxIndex ], a[ i ] )
      maxIndex = i;

  return a[ maxIndex ];

}
  //Yes you can give it a default parameter, yay!!



int main()
{

  vector<int> arr;
  less lessThan;
  arr.push_back(5);
  arr.push_back(9);

  findMax(arr,lessThan);


  return 0;
}
