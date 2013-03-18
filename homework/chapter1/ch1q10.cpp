#include <iostream>
#include <string>
#include <vector>
using namespace std;

void printItem( string item, string last);

int main()
{

  string read_in = "start";  //initialize string
  string sentinel = "final";
 
  vector<string> container;

  cout << " Please input a string\n";
  cin >> read_in;
  
  while( read_in != sentinel) //sentinel value is 'final'
    {
      container.push_back(read_in);
      cout << "Please input another string (final to exit)\n";
      cin >> read_in;
    }
  int size = container.size( );
  for(int i = 0; i <size; i++ )
     printItem( container[i],sentinel );
  
  return 0;

}


void printItem( string item, string last)
{
  if( item > last)
    cout << endl<<item<<endl;

}
