#include <iostream>

using namespace std;

//returns the smaller of two objects
template <class object>
object Min( object first, object second)
{
  object min = first;
  if( first > second)
    min = second;
  return min;
}

//returns the bigger of two objects
template <class object>
object Max(object first, object second)
{
  object max = first;
  if( first < second)
    max = second;
  return max;
}


int main()
{
  int a,b;

  a = 5;
  b = 6;

  cout << Max<int>(a,b) << "is the biggest\n";
  cout << Min<int>(a,b) <<" is the smallest\n";

  return 0;
}
