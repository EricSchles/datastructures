#include <iostream>
#include <vector>
using namespace std;

//part a
template <class object,class Comparator>
int countMatches( vector<object> & a, Comparator compare)
{

  int size = a.size( );
  int count = 0;
  for(int i = 0; i < size; i++)
    {
      if(compare(a[i]))
	count++;
    }

  return count;
}


//works fine.
//part b
//part c - assumes == operator defined for the object.
template <class object>
class EqualsZero
{

public:
  
  bool operator() (object check)
  {
    return check == 0;
  }


};

template<class compare>
class EqualsK
{
public:
  EqualsK(compare x = 0 ) 
 :x(k) { }
  
  bool operator() (compare input)
  {
    return input == k;
  }


private:
  compare k;
};


int main()
{

  EqualsZero<int> zero;
  EqualsK<int> one(5);
  vector<int> r;

  r.push_back(5);
  r.push_back(7);
  int COUNT = countMatches(r,zero);

  cout << COUNT << " is how many items in the array equal k";

  return 0;
}
