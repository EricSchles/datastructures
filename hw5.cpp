#include <iostream>

using namespace std;

template<class Comparable>
class BinarySearchTree;

template <class Comparable>
class BinaryNode
{
Comparable element;
BinaryNode *left;
BinaryNode *right;
int size;

BinaryNode( const Comparable & theElement, BinaryNode *lt, BinaryNode *rt, int sz = 1 ): element( theElement ), left( lt ), right( rt ), size( sz ) { }

friend class BinarySearchTree<Comparable>;
};


template <class Comparable>
class BinarySearchTree
{
public:

  typedef BinaryNode<Comparable> Node;


  BinarySearchTree( ) : root( NULL ) { } // Construct the tree.
  BinarySearchTree( const BinarySearchTree & rhs ) : root( NULL ) { *this = rhs; }// Copy constructor.

  ~BinarySearchTree( ){ makeEmpty( ); } // Destructor for the tree.

  int CountNodesWithOneChild(BinaryNode<Comparable> * rut, int counter); 
  void negateTree(BinaryNode<Comparable> * rut);
  int max_sum_root_to_leaf(BinaryNode<Comparable> * rut, int sum);
  void printer(BinaryNode<Comparable> * rut);
  const Comparable * findKth( int k ) const
  { return elementAt( findKth( k, root ) );}

  const Comparable * findMin( ) const
  { return elementAt( findMin( root ) ); }

  const Comparable * findMax( ) const
  { return elementAt( findMax( root ) ); }


  const Comparable * find( const Comparable & x ) const
  { return elementAt( find( x, root ) ); }

  bool isEmpty( ) const
  { return root == NULL;}

  void makeEmpty( )
  { makeEmpty( root ); }

  void insert( const Comparable & x )
  { insert( x, root ); }

  void remove( const Comparable & x )
  { remove( x, root ); }

  void removeMin( )
  { removeMin( root ); }

  const BinarySearchTree & operator=( const BinarySearchTree & rhs );

private:
  Node * root;
  int treeSize( Node *t ) const { return t == NULL ? 0 : t->size; }
  const Comparable * elementAt( Node *t ) const;
  void insert( const Comparable & x, Node * & t ) const;
  void remove( const Comparable & x, Node * & t ) const;
  void removeMin( Node * & t ) const;
  Node * findMin( Node *t ) const;
  Node * findMax( Node *t ) const;
  Node * find( const Comparable & x, Node *t ) const;
  void makeEmpty( Node * & t ) const;
  Node * clone( Node *t ) const;
  Node *findKth( int k, Node *t ) const;


};

template<class comparable>
int BinarySearchTree<comparable>::CountNodesWithOneChild(BinaryNode<comparable> * rut, int counter)
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
void BinarySearchTree<comparable>::negateTree(BinaryNode<comparable> * rut)
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
int BinarySearchTree<comparable>::max_sum_root_to_leaf(BinaryNode<comparable> * rut, int sum)
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
void BinarySearchTree<comparable>::printer(BinaryNode<comparable> * rut)
{

  if(rut != NULL) 
    {
      if( rut->left == NULL && rut->right == NULL)
	{
	  cout << rut->element << " , ";
	}
      else if(rut->left != NULL && rut->right ==NULL)
	{
	  cout << rut->element << " , ";
	  printer(rut->left);
	}
      else if(rut->right != NULL && rut->left == NULL)
	{
	  cout << rut->element << " , ";
	  printer(rut->right);
	}
      else
	{
	  cout << rut->element << " , ";
	  printer(rut->left);
	  printer(rut->right);

	}
    }
  
}

/*
pass in root node to the method and a counter
base case: if root->left node = NULL and root->right node = NULL:
	 return counter
else if root → left node = NULL xor root → right node = NULL 
	return counter +1
if left node ! = NULL, set node = left node 
if right node != NULL, set node = right node
*/

int main()
{
  BinarySearchTree<int> tree;
  
  for(int i =0; i < 10; i++)
    tree.insert(i);


}
