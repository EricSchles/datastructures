#include <vector>
#include <iostream>
using namespace std;

template<class Container>
void printCollection( const Container  & c)
{

  typename Container::const_iterator itr;
  for( itr = c.end() -1; itr != c.begin(); --itr )
    cout << *itr << " ";


}

int main()
{

  vector<int> a;
  for(int i = 0; i < 15; i++)
    a.push_back(i);
  printCollection( a );


  return 0;


}
