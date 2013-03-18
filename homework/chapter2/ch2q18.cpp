#include <iostream>
using namespace std;

class mystring
{

public:
  mystring( char ch );
  mystring ( const char *cstring = "" );
  mystring( const mystring & str );
  ~mystring( )
  { delete [ ] buffer; }


  const mystring & operator=( const mystring & rhs);
  const mystring & operator+=( const mystring & rhs );
  
  const int size( )
  { return sizeof( *this ) / sizeof ( char ); }
  const char *c_str( ) const
  { return buffer; }
  int length( ) const
  { return strLength; }

  bool empty( )
  { return *this == ""; }
  void clear( )
  { *this = ""; }
  char at(int i)
  { return *this[i]; }
  char operator[]( int k ) const;
  char & operator[]( int k );
  mystring operator() ( int begin, int end);
private:
  int strLength;
  int bufferLength;
  char *buffer;

};

ostream & mystring::operator<<( ostream & out, const mystring & str );
istream & mystring::operator>>( istream & in, mystring & str );
istream & mystring::getline( istream & in, mystring & str, char delim = '\n' );


mystring mystring::operator() ( int begin, int end )
{

  mystring s ="";
  for(int i = begin; i < end; i++)
    s += *this[i];
  return s;

}

bool mystring::operator==(const mystring & lhs, const mystring & rhs);
bool mystring::operator!=(const mystring & lhs, const mystring & rhs);
bool mystring::operator< (const mystring & lhs, const mystring & rhs);
bool mystring::operator<=(const mystring & lhs, const mystring & rhs);
bool mystring::operator> (const mystring & lhs, const mystring & rhs);
bool mystring::operator>=(const mystring & lhs, const mystring & rhs);

mystring::mystring(const char * cstring)
{
  if (cstring == NULL)
    cstring = "";
  strLength = strlen( cstring );
  bufferLength = strLength + 1;
  buffer = new char[ bufferLength ];
  strcpy( buffer, cstring );

}

