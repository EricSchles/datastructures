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

  u;


  return 0;
}
