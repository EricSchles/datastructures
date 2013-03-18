#include <iostream>
using namespace std;

template <class obj>
class SingleBuffer
{
public:
  
  SingleBuffer()
    : isEmpty(true) { }
  obj get( )
  {
    if( !isEmpty )
      {
	obj element = *this.data;
	*this.data = NULL;
	return element;
      }
    else
      {
	cout << "The buffer is empty please enter data first";
      }
  void put( obj item)
  {
    if(isEmpty)
      {
	data = item;
      }
    else
      cout <<"There is already an item in the buffer\n";
  }
  

private:
  bool isEmpty;
  obj data;
  
};


 
