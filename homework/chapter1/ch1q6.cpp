#include <iostream>
#include <string>
using namespace std;



struct Node
{
  string item;
  Node *next;

};

void printItem( string item)
{

  cout << item;

}


int main()
{
  //initialize linked list
  Node *first,*last; 
  
  first  = new Node; //head
  
  last = first->next; //join head and tail
  
  last->next = NULL; //tail

  for(Node *p = first; p != NULL; p->next )
    printItem( p->item );

  return 0;

}
