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

  vector<S *> u(10);

  u[ 0 ]->a = 5;

  cout << u[ 0 ]->a << endl;
  return 0;
}
