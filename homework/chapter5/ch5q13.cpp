#include <iostream>

using namespace std;



template <class Object>
class StorageCell
{
public:
  explicit StorageCell( const Object * initialValue = Object( ) )
    : MemoryCell<Object>( initialValue ) { }
  
  const Object & get( ) const
  { return read( ); }







};
