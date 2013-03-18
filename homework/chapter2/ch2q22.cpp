#include <iostream>
using namespace std;

class CombinationLock
{

public:
  CombinationLock( int first, int second, int third)
    : one(first), two(second), three(third), lockOpen(false) { }
  
  void open( );
  void changeCombo( );



private:
  bool lockOpen;
  int one;
  int two;
  int three;
};

void CombinationLock::open( )
{

  int ONE;
  int TWO;
  int THREE;
  cout << "Please enter the combination\n";
  cout << "first number: "
  cin >> ONE;
  cout <<"\nsecond number: ";
  cin >> TWO;
  cout <<"\nthird number: ";
  cin >> THREE;

  if( ONE == one && TWO == two && THREE == three)
    {
      cout <<"You got it right\n";
      lockOpen = true;
    }
  else
    {
      cout << "you gave the wrong combination\n";
    }
      
}

void CombinationLock::changeCombo( )
{
  int ONE;
  int TWO;
  int THREE;
  if(lockOpen)
    {
      cout << "Enter the new combination";
      cout << "first number: ";
      cin >> ONE;
      cout << "\nsecond number: ";
      cin >> TWO;
      cout << "\nthird number: ";
      cin >> THREE;

      one = ONE;
      two = TWO;
      three = THREE;
    }
  else
    cout << "You must open the lock first!";

}
