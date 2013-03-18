#include <iostream>
#include <string>
using namespace std;



struct Node
{
  string item;
  Node *next;

};

void printItem( string item, string last);



int main()
{

  string read_in = "start";  //initialize string
  string sentinel = "final";
  //initialize linked list
  Node *last,*header; 
  
  last  = new Node; //head
  header = last;
  last->next = NULL;

  cout << " Please input a string\n";
  cin >> read_in;
  
  while( read_in != sentinel) //sentinel value is 'final'
    {
      last->next = new Node;
      last = last->next;
      last->item = read_in;
      last->next = NULL;
      cout << "Please input another string (final to exit)\n";
      cin >> read_in;
    }
  
   for(Node *p = header; p != NULL; p = p->next )
     printItem( p->item,sentinel );
  
  return 0;

}


void printItem( string item, string last)
{
  if( item > last)
    cout << endl<<item<<endl;

}
