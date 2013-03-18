#include <iostream>
using namespace std;

template<class Obj>
class Node
{

public:
  Node(Obj first)
    : data(first){ }
  Obj data;
  Node *next;

};

int main()
{

  Node<int> *header = new Node<int>;
  header->next = NULL;
  





  return 0;

}
