#include <iostream>
#include <vector>
using namespace std;


int binary( vector<int> & a, int begin,int end, int search)
{

  int mid = begin + (end - begin)/2;

  if( mid == search)
    return mid;
    
  if( a[mid] < search)
    return binary(a, begin , mid - 1 , search);
  else 
    return binary(a, mid, end, search);
 
 
}
int main()
{
  
  vector<int> x;
  int c = 0;
  for(int i = 0; i < 6; i++)
    x.push_back(6);
  cout <<endl;
  c =binary(x, 0, x.size()-1 ,4);
  cout <<c <<endl;
  
  return 0;
}
