#include <iostream>
using namespace std;

class Subject;

class Observer
{
public:
  virtual ~Observer( ) { }
  virtual void update( Subject * observee) = 0; //abstract method!!!

};

class Subject
{
public:
  virtual ~Subject( ) = 0; //abstract
  

  //Add obs to the set of observers;
  virtual void addObserver( Observer *obs);
  
  virtual void removeObserver( Observer *obs);
  
  virtual void notifyAll( )
  {

    for( int i = 0; i < observer.size( ); i++)
      observer[ i ]->update( this );

  }

private:
  vector<Observer *> observers;

};
