#include <list>
#include <iostream>
using namespace std;

template<class Object>
class Myqueue
{
public:
  Myqueue();
  Myqueue(Object first): data.push_front(first){ } 
  ~Myqueue();
  void insert( const Object & x)  //insert
  {
    data.push_back(x);

  }  
  void remove( )
  {
    data.pop_back();
  }
  const Object & getFront() const
  {

    data.back();
  }
  bool isEmpty () const
  {
    return data.front == NULL;
  }
  void makeEmpty()
  {
    while( *this.isEmpty == false)
      {
	data.pop_back();
      }
  }

private:
  list<Object> data;

};



