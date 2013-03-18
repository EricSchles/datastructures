#include <iostream>
#include <vector>
using namespace std;

template<class obj>
vector<obj> & Read()
{

  obj x;
  vector<obj> r;
  cout << "Input an arbitrary number of objects\n";
  cin >> x;
  while( cin >> x )
    {
      r.push_back(x);
    }

  return r;

}


int main()
{

  Read<int>();

  return 0;
}
