#include <iostream>
#include <cmath>
using namespace std;

typedef long IntType;

class Rational
{

public:
  //Constructors
  Rational( const IntType & numerator = 0)
    : numer(numerator), denom( 1 ) { }
  Rational( const IntType & numerator, const IntType & denominator)
    :numer(numerator), denom(denominator) { fixSigns(); reduce(); }
  Rational( const Rational & rhs)
    :numer(rhs.numer), denom( rhs.denom ) { }


  //Destructor
  ~Rational() {}

  //Assignment Ops 
  const Rational & operator= ( const Rational & rhs);
  const Rational & operator+=( const Rational & rhs);
  const Rational & operator-=( const Rational & rhs);
  const Rational & operator/=( const Rational & rhs);
  const Rational & operator*=( const Rational & rhs);

  //Math Binary Ops 
  Rational operator+( const Rational & rhs) const;
  Rational operator-( const Rational & rhs) const;
  Rational operator/( const Rational & rhs) const;
  Rational operator*( const Rational & rhs) const;
  Rational operator^( const Rational & rhs) const;

  //Relational & Equality Ops
  bool operator< ( const Rational & rhs) const;
  bool operator<= (const Rational & rhs) const;
  bool operator> (const Rational & rhs) const;
  bool operator>= (const Rational & rhs) const;
  bool operator== (const Rational & rhs) const;
  bool operator!= (const Rational & rhs) const;

  //Unary operators
  const Rational & operator++();
  Rational operator++(int );
  const Rational & operator--( );
  Rational operator--( int );
  const Rational & operator+( ) const;
  Rational operator-( ) const;
  bool operator!() const;

  //Member Function
  double toDouble( ) const
  { return static_cast<double>( numer) / denom; }

  //I/O friends: privacy is waived
  friend ostream & operator<<( ostream & out, const Rational & value);
  
  friend istream & operator>>( istream & in, Rational & value);

private:
  //A rational number is represented by a numerator and 
  // denominator in reduced form
  IntType numer;
  IntType denom;
  
  void fixSigns( );
  void reduce( );

};

void Rational::fixSigns( )
{

  if( denom < 0 )
    {
      denom = -denom;
      numer = -numer;
    }

}

void Rational::reduce( )
{

  IntType d = 1;
  
  if( denom != 0 && numer != 0)
    d = gcd( numer, denom);

  if( d > 1 )
    {
      numer /= d;
      denom /= d;
    }
}

IntType gcd( numerator, denominator)
{

     while( 1 )
    {
        a = a % b;
	if( a == 0 )
	       return b;
	b = b % a;

        if( b == 0 )
	       return a;
    }
}



const Rational & Rational::operator=( const Rational & rhs)
{

  if( this != &rhs)
    {
      numer = rhs.numer;
      denom = rhs.denom;
    }
  return *this;
}

const Rational & Rational::operator++(const Rational & rhs)
{
  numer = numer * rhs.denom + rhs.numer * denom;
  denom = denom * rhs.denom;
  reduce( );

  return *this;
}

Rational operator^( const Ratio  Rational operator^( const Rational & rhs) const;nal & rhs) const
{

  Rational lhs_tmp( *this );
  Rational rhs_tmp( rhs );
  Rational answer;
  double power;
  rhs_tmp.reduce();
  
  power = static_cast<double>(rhs_tmp.numer) / rhs_tmp.denom;

  answer.numer = pow(lhs_tmp.numer, power);
  answer.denom = pow(lhs_tmp.denom, power);
        
  return answer;
}
Rational Rational::operator*( const Rational & rhs) const
{

  Rational lhs_tmp( *this );
  Rational rhs_tmp( rhs );

  lhs_tmp.numer = numer;
  lhs_tmp.denom = rhs.denom;
  
  rhs_tmp.numer = rhs.numer;
  rhs_tmp.denom = denom;

  lhs_tmp.reduce();
  rhs_tmp.reduce();

  return (lhs_tmp.numer * rhs_tmp.numer)/(lhs_tmp.denom * rhs_tmp.denom);

}

Rational Rational::operator+( const Rational & rhs) const
{

  Rational answer( *this );
  answer += rhs;
  return answer;
}
//part a
bool Rational::operator==(const Rational & rhs) const
{
  if( numer == rhs.numer)
    { 
      if( denom = rhs.denom)
	return true;
    }
  else
    return false;
}
//part a
bool Rational::operator!=( const Rational & rhs) const
{
  return !(rhs == *this);
}

const Rational & Rational::operator++( )
{

  numer += denom;
  return *this;

}

Rational Rational::operator++( int )
{

  Rational tmp = *this;
  numer += denom;
  return tmp;

}

bool Rational::operator!() const
{
  return !numer;
}

const Rational & Rational operator+() const
{
  return *this;

}

Rational Rational::operator-() const
{
  return Rational(-numer, denom);
}

istream & operator>>( istream & in, Rational & value)
{

  in >> value.numer;
  value.denom = 1;

  char ch;
  in.get( ch );

  if ( !in.eof( ) )
    {
      if( ch == '/' )
	{
	  in >> value.denom;
	  value.fixSigns( );
	  value.reduce( );
	}
      else
	in.putback( ch );

    }

  return in;

}

ostream & operator<<( ostream & out, const Rational & value )
{

  if( value.denom  != 0 )
    {
      out << value.denom;
      if( value.denom != 1)
	{
	  out <<'/' << value.denom;
	}
      return out;
    }

  if( value.numer == 0 )
    out << "indeterminate";
  else
    {
      if( value.numer < 0)
	out << '-';
      out <<"infinity";
    }
  return out;

}

