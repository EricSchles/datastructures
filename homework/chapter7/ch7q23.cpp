#include <iostream>
#include <vector>
using namespace std;

template<class object, class forwardItr>
void fill(const object x, forwardItr begin, forwardItr end)
{
  forwardItr itr;
  for(itr = begin; itr != end; itr++)
    {
      *itr = x;
    }

}

int main()
{

  vector<int> a;

  for(int i = 0; i < 15; i++)
    a.push_back(i);


  fill(4, a.begin(), a.end() );

  for(int k = 0; k < 15; k++)
    cout << a[k] << " ";



  return 0;
}
