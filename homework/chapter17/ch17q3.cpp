#include <iostream>
using namespace std;


template<class Obj>
class Node
{
public:
  Node( const Node & rhs)
  {
    header = new Node<object>;
  }
  Node *next;
  Obj data;
  Node<Obj> *header;

};

template<class object>
Node<object> find( const object & x ) const
{

  Node<object> *p = header->next;
  Node<object> *r;
  r = NULL;
  
  while( p != NULL)
    {
      if( p->data == x)
	{
	   r = p;
	}
      p = p->next;
    }

  if( r != NULL )
    return Node<object>(r);
  else
    return Node<object>(p);

}
