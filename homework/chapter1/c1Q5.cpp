#include <iostream>
#include <vector>

using namespace std;

struct S
{ 

  int a;
  S *b;

};
int main()
{

  S z;
  S *x;
  
  cout << x->b-z.b;
  return 0;
}
