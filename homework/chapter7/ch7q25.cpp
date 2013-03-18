#include <vector>
#include <iostream>
using namespace std;


//couldn't use equal_to because the compiler complained.
template<class Obj>
class Equal_to
{

public:
  Equal_to( Obj thing): data(thing) { }
  
  bool operator() (Obj x)
  {
    return x == data;
  }
private:
  Obj data;

};


template<class Object, class forwardItr, class Predicate>
forwardItr adjacent_find( forwardItr begin, forwardItr end, Predicate pred = equal<Object> )
{
  
  forwardItr itr1 = begin;
  forwardItr itr2 = begin;
  itr1++;
  while( itr1 != end )
    {
      if( pred(*itr1) && pred( *itr2) )
	{
	  return itr1;
	}
      itr1++;
      itr2++;
    }
}

int main()
{
  Equal_to<int> compare(5); //couldn't use equal_to because the compiler complained.
  vector<int> a;

  for(int i = 0; i < 15; i++)
    a.push_back(i);
  
  a.push_back(5);
  a.push_back(5);
  adjacent_find<int>(a.begin(),a.end(), compare);
  return 0;
}
