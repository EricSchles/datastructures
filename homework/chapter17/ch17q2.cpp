#include <iostream>
using namespace std;

template<class Obj>
class Node
{
public:

  Obj data;
  Node *next;
  Node *prev;

};

int main()
{


  Node<int> *header = new Node<int>;
  Node<int> *tail = new Node<int>;
  header->next = tail;

  tail->next = NULL;
  tail->prev = header;
  header->prev = NULL;



  return 0;
}
