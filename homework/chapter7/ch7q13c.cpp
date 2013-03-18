#include <iostream>
using namespace std;

template<class Object>
class Collection
{

public:
  //constructor, destructor
  virtual Collection(int size): 
    capacity(size) {}
  virtual ~Collection( ) {}

  virtual void insert( const Object & x )
  {
    if( find(x) == -5 )
      {
	int i = 1;
	int max = ARRAY[0];
	while( ARRAY[i] < x )
	  {
	    if( max < ARRAY[i])
	      max = ARRAY[i];
	    i++;
	  }
	int j = capacity;
	int min = ARRAY[capacity];
	while( ARRAY[j] > x )
	  {
	    if( min > ARRAY[j] )
	      min = ARRAY[j];
	    j--;
	  }
	Object *arr = new Object[capacity + 1];
	for(int k = 0; k <= i; k++)
	  arr[k] = ARRAY[k];
	arr[i + 1] = ARRAY[i + 1];
	for( int d = j; d < capacity + 1; d++)
	  arr[d] = ARRAY[d];
	//this is wrong, but that's because we can't pass in any other objects.  
	//for this to be correct x needs to be the array but then we need to add the prototype
	//to allow for insertion of values.
      }
    else
      {
	cout << "element already exists.  No duplicates allowed";
      }
  }
  virtual void remove( const Object & x )
  {
    if( find(x) == -5)
      {
	cout << "the item does not exist in the set";
      }
    else
      {
	for(int i = 0; i < capacity; i++)
	  {
	    int lowerbound = 0;
	    if( ARRAY[i] < x )
	      {
		lowerbound++;
	      }
	  }
	for(int k = capacity; i > lowerbound; i--)
	  {
	    ARRAY[i] = ARRAY[i-1];
	  }
      }
  }
  virtual Cref<Object> find(const Object & x ) const
  {
    return find( x, 0, capacity);

  }
  virtual Cref<Object> find( const Object & x, int low, int high)
  {
    if( low > high)
      return -5; //sentinel value means item not found.
    int mid = (low + high) / 2;

    if( ARRAY[mid] < x)
      return find( x, mid + 1, high);
    else if( x < ARRAY[mid] )
      return find( x, low, mid -1 );
    else
      return mid;
  }
  virtual bool isEmpty( ) const;
  virtual void makeEmpty( );
private:
  int capacity;
  Object ARRAY[capacity];
  
};
