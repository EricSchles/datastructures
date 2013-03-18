#include <iostream>
#include <queue>
using namespace std;

template<class Object>
class Queue
{
public:
  virtual ~Queue() { } //destructor

  virtual void enqueue( const Object & x )
  {
    data.push(x);

  }
  virtual void dequeue( )
  {
    data.pop();
  }
  

  virtual const Object & getFront( ) const
  {
    return data.front();
  }

  virtual bool isEmpty( ) const = 0;
  virtual void makeEmpty( ) = 0;

private:
  queue<Object> data;
