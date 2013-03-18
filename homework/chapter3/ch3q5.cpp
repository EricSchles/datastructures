#include <iostream>
#include <vector>
using namespace std;

template <class object>
object MIN(vector<object> &a)
{

  int size = a.size( );
  object min = a[0];
  for( int i = 0; i < size;i++)
    {
      if( a[i] < min)
	min = a[i];
    }
  return min;
  
}
 
template <class obj>
obj MAX( vector<obj> &a)
{
  int size = a.size( );
  obj max = a[0];
  for( int i = 0; i < size;i++)
    {
      if( max < a[i])
	max = a[i];
    }
  
  return max;
}


int main()
{

  vector<int> b;

 
  for(int i = 0; i < 50; i++)
    b.push_back(i);
  

  int max;
  int min;

  max = MAX<int>(b);
  cout << max <<" is the maximum element in vector b\n";
  min = MIN<int>(b);
  cout << min <<" is the minimum element in vector b\n";

  return 0;
}
