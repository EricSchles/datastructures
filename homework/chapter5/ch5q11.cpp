#include <iostream>
using namespace std;

template <class Comparable>
class Pointer
{
public:
  explicit Pointer( Comparable *rhs = NULL)
    :pointee( rhs ) { }
  bool operator<( const Pointer & rhs ) const
  { return *pointee < *rhs.pointee; }
  operator Comparable * ( ) const
  { return pointee; }
  Comparable * get( ) const
  { return pointee; }
  Comparable operator* ()const
  { return *pointee; }
  /*Comparable operator-> ()const
  { return *( this.get( ) )}
  */


private:
  Comparable *pointee;
};

int main()
{

  int *x = new int(7);
  Pointer<int> first(new int(6));

  cout << *(first.get());
  cout << first->pointee;

  return 0;
}
