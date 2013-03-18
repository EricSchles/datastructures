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
    data.push_front(x);

  }  
  void remove( )
  {
    data.pop_back();
  }
  const Object & getFront() const
  {

    data.front();
  }
  bool isEmpty () const
  {
    return data.back == NULL;
  }
  void makeEmpty()
  {
    while( *this.isEmpty == false)
      {
	data.pop_front();
      }
  }

private:
  list<Object> data;

};



