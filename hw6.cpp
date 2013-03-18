#include <iostream>
#include<queue>
using namespace std;

template <class Comparable>
class BinarySearchTree;

template <class Comparable>
class BinaryNode
{
    Comparable  element;
    BinaryNode *left;
    BinaryNode *right;
    int size;
	
    BinaryNode( const Comparable & theElement, BinaryNode *lt,
			   BinaryNode *rt, int sz = 1 )
	: element( theElement ), left( lt ), right( rt ), size( sz ) { }	
	
    friend class BinarySearchTree<Comparable>;
};


// BinarySearchTree class
//
// CONSTRUCTION: with no parameters or another BinarySearchTree.
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// bool isEmpty( )        --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// ******************ERRORS********************************
// Error messages are printed by insert if warranted

template < class Comparable >
class BinarySearchTree
{
public:
	typedef BinaryNode<Comparable> Node;
	
	BinarySearchTree( ) : root( NULL ) { } // Construct the tree.
	BinarySearchTree( const BinarySearchTree & rhs ) : root( NULL ) { *this = rhs; }// Copy constructor.
	~BinarySearchTree( ){ makeEmpty( ); } // Destructor for the tree.

        
        void CountNodesWithOneChild(int i)
        {CountNodesWithOneChild(root,i); } 
        void negateTree()
        {negateTree(root);}
        void max_sum_root_to_leaf(int i)
        {max_sum_root_to_leaf(root,i);}
        void printer()
        {
	  queue<Comparable> contents;
	  printer(root,contents );
	  while
	}	
	// Test if the tree is logically empty.
	// Return true if empty, false otherwise.	
	bool isEmpty( ) const { return root == NULL;}
	
	// Make the tree logically empty.
	void makeEmpty( )
	{ makeEmpty( root ); }

	// Insert x into the tree;
	void insert( const Comparable & x )
	{ insert( x, root ); }

	

private:
	Node * root;
	
        int CountNodesWithOneChild(BinaryNode<Comparable> * rut, int counter) const; 
        void negateTree(BinaryNode<Comparable> * rut) const;
        int max_sum_root_to_leaf(BinaryNode<Comparable> * rut, int sum) const;
        queue<Comparable> printer(BinaryNode<Comparable> * rut,queue<Comparable> contain) const;

	void insert( const Comparable & x, Node * & t ) const;
	void makeEmpty( Node * & t ) const;
};


// Internal method to insert into a subtree.
// x is the item to insert.
// t is the node that roots the tree.
// Set the new root.
// Send error message if x is already in the tree.
template <class Comparable>
void BinarySearchTree<Comparable>::
insert( const Comparable & x, Node * & t ) const
{
    if( t == NULL )
        t = new Node( x, NULL, NULL, 0 );
    else if( x < t->element )
        insert( x, t->left );
    else if( t->element < x )
        insert( x, t->right );
    else
	{
		cout << x << " has already been inserted." << endl;	
		return;
	}
    t->size++;
}


// Internal method to make subtree empty.
template <class Comparable>
void BinarySearchTree<Comparable>::makeEmpty( Node * & t ) const
{
    if( t != NULL )
    {
        makeEmpty( t->left );
        makeEmpty( t->right );
        delete t;
    }
    t = NULL;
}



template<class comparable>
int BinarySearchTree<comparable>::CountNodesWithOneChild(BinaryNode<comparable> * rut, int counter) const
 {

   if( rut->left == NULL && rut->right == NULL)
     {
       return counter;
     }
   else if( (rut->left == NULL && rut->right != NULL) )  
     {
        counter++;
	CountNodesWithOneChild(rut->right, counter);
     }
     else if( (rut->right == NULL && rut->left != NULL))
       {
	 counter++;
	 CountNodesWithOneChild(rut->left, counter);
       }
     else if( rut->right != NULL && rut->left != NULL)
       {
	 CountNodesWithOneChild(rut->left, counter);
	 CountNodesWithOneChild(rut->right, counter);
       }
 }

template<class comparable>
void BinarySearchTree<comparable>::negateTree(BinaryNode<comparable> * rut) const
 {

   if( rut->left == NULL && rut->right == NULL)
     {
       ;
     }
   else if( (rut->left == NULL && rut->right != NULL) )  
     {
       rut->element = -(rut->element);
	negateTree(rut->right);
     }
     else if( (rut->right == NULL && rut->left != NULL))
       {
	 rut->element = -(rut->element);
	 negateTree(rut->left);
       }
     else if( rut->right != NULL && rut->left != NULL)
       {
	 rut->element = -(rut->element);
	 negateTree(rut->left);
	 negateTree(rut->right);
       }
 }


template<class comparable>
int BinarySearchTree<comparable>::max_sum_root_to_leaf(BinaryNode<comparable> * rut, int sum) const
 {

   if( rut->left == NULL && rut->right == NULL)
     {
      return sum;
     }
   else if( (rut->left == NULL && rut->right != NULL) )  
     {
        
      sum = sum + rut->element;
       max_sum_root_to_leaf(rut->right, sum);
     }
     else if( (rut->right == NULL && rut->left != NULL))
       {
	 sum = sum + rut->element;
	 negateTree(rut->left, sum);
       }
     else if( rut->right != NULL && rut->left != NULL)
       {
	 int add_left = rut->left->element + sum;
	 int add_right = rut->right->element + sum;
	 if( add_right < add_left)
	    max_sum_root_to_leaf(rut->left, sum);
	 if( add_left < add_right)
	   max_sum_root_to_leaf(rut->right, sum);
	 
       }
 }

template<class comparable>
queue<comparable> BinarySearchTree<comparable>::printer(BinaryNode<comparable> * rut, queue<comparable> contain) const
{
  
  if(rut != NULL) 
    {
      if( rut->left == NULL && rut->right == NULL)
	{
	  contain.push(rut->element);
	}
      else if(rut->left != NULL && rut->right ==NULL)
	{
	  
	  contain.push(rut->element);
	  printer(rut->left,contain);
	}
      else if(rut->right != NULL && rut->left == NULL)
	{
	  
	  contain.push(rut->element);
	  printer(rut->right,contain);
	}
      else
	{
	  
	  contain.push(rut->element);
	  printer(rut->left,contain);
	  printer(rut->right,contain);
	}
    }
  
}//Don't use recursion use a while loop


int main()
{

 BinarySearchTree<int> tree;
  
  
  tree.insert(4);
  tree.insert(7);
  tree.insert(3);
  tree.insert(2);

  //int j =0;
  tree.printer();

  return 0;
}
