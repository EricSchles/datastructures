#include <iostream>

using namespace std;

class Date
{
private:
  int month_offset []= { 31,28,31,30,31,30,31,31,30,31,30,31 };//fill this with the offsets for each month.
  int month_offset_leap [] = { 31,29,31,30,31,30,31,31,30,31,30,31};
    enum{ FIRST_YEAR = 1800, MAX_YEAR = 2500 };
  int totalDays;
  const int MAX; //figure out total max days and set equal to this value.
public:
  //Constructor
  Date( int y = FIRST_YEAR, int m = 1, int d = 1 );
  Date( Date start)
    : totalDays(start) 
  { 
    bool check = rangeCheck(); 
    if( check )
      {
	cout << "failed check!!!";
	totalDays = 1;
  
      }
  }
  // I/O interface
  //remember to perform rangeCheck() inside these functions
  const Date get( bool print ) const;
  //pass in true if you want to print out the current date
  //false otherwise.
  void set( Date assign );

  //Assignment operator 
  Date operator+= (int days);
  
  //Binary operators
  int operator-( Date right ) const;
  bool operator<( Date right ) const;
  bool rangeCheck(); //if out of range raise error and exit the function with flag from return.
  //true means failed range check
  //false means passed range check
  bool isLeap( Date year) const;
  
};

void set( int year, int month, int days )
{
  
  for(int i = 0; i < year; i++)
    totalDays += 100;
  bool leap = isLeap( *this ); 
  for(int i = 0; i < month; i++)
    {
      if(leap)
	totalDays += month_offset_leap[i];
      else
	totalDays += month_offset[i];
    }
  for(int i = 0; i < days; i++)
    totaldays++;

}


const Date Date::get(bool print ) const
{

  Date use ( *this ); //otherwise we will modify the current date.
  int year;
  int month;
  int days;
  int counter = 0;
  bool leap = isLeap(use);
  while( use.totalDays > 365)
    {
      year++;
      use.totalDays-=365;
    }
  for(int i = 0; i < 12; i++)
    {
      if(leap)
	{
	  if(use.totalDays>month_offset_leap[i])
	    { 
	      counter = i;
	      month++;
	    }
	}
      else
	{
	  if( use.totalDays > month_offset[i] )
	    { 
	      counter = i; //keeps track of the offset for the next decrement;
	      month++;
	    }
	}
    }
  if(leap)
    use.totalDays = use.totalDays - month_offset_leap[counter];
  else
    use.totalDays = use.totalDays - month_offset[counter];  
  days = use.totalDays;
  if(print)
    {
      cout << "The current year is " << year;
      cout << "\nThe current month is " << month;
      cout << "\nThe current day is " << days;
    }
  return use;
}


int Date::operator-( Date right) const
{
  
  totalDays = totalDays - right.totalDays;
  if( rangeCheck( ) )
    {
      return;
    }
  else
    return totalDays;

}

Date Date::operator+=(int days)
{
  totalDays = totalDays + days;
  if( rangeCheck() )
    {
      return;
    }
  else
    return *this;
}



//is leap year if divisible by 4 not divisible by 100 unless also divisible by 400

bool Date::isLeap(Date year)
{
  if( totalDays % 4 == 0 )
    {
      if( ( totalDays % 100 == 0 ) && ( totalDays % 400 == 0 ) )
	return true;
    }
  else 
    return false;
}

bool Date::operator<( Date right) const
{
  
  return *this.totalDays < right.totalDays;

}

bool Date::rangeCheck()
{
  if(totalDays < 1)
    {
      cout << "Underflow error occurred!";
      return true;
    }
  if( MAX < totalDays) //max is the max number of days possible
    {
      cout << "Overflow error occurred!";
      return true;
    }
  else
    { return false; }
}
