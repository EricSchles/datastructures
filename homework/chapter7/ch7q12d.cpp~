#include <iostream>
using namespace std;

template<class Object>
class Queue
{
public:
  virtual Queue(int size): capacity(size){ }//must take a size parameter
  virtual ~Queue() { } //destructor

  virtual void enqueue( const Object & x )
  {
    int count = 0;
    for(int i = 0; i < capacity; i++)
      {
	if( ARRAY[i] != 0)
	  count++;
      }
    //this is wrong, it will cause problems in the following situation: 1 1 2 0 0 0 3 4 5 0 0 0 23 
    if( count == capacity)
      {
	oldcap = capacity;
	capacity = capacity * 2 - 1;
	Object arr[capacity];
	for(int j = 0; j < capacity; j++)
	  arr[j] = ARRAY[j];
	arr[oldcap + 1] = x;
      }
    else
      {
	ARRAY[count + 1] = x;
      }

  }
  virtual void dequeue( )
  {
    for(int i = 0; i < capacity; i++)
      {
	  if( ARRAY[i] != 0)
	    count++;
      }
    if( count == 0)
      {
	cout << "this array is empty, nothing to remove!";
      }
    else
      {

	for(int i = capacity; i > 0; i--)
	  {
	    ARRAY[i] = ARRAY[i-1];
	  }
      }
  }
  

  virtual const Object & getFront( ) const
  {
    return ARRAY[0];
  }

  virtual bool isEmpty( ) const = 0;
  virtual void makeEmpty( ) = 0;

private:
  int capacity;
  Object ARRAY[capacity];

};
