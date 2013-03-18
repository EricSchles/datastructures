#include <iostream>

using namespace std;




int binary( int n, int count)
{

  if( n == 0 )
    {
      return count;
    }
  if( n == 1 )
    {
      return ++count;
    }
  if( n % 2 == 0 )
    {
      return binary( n/2 , count);
    }
  else
      {
	return binary(n/2, ++count);
      }

}



int main()
{
  
  //int x = 0;
  int counter = 0;
  int result = 0;
  //result = binary(x,counter);
  //cout << endl<<result<< endl;
  
  for(int i = 0; i < 16 ; ++ i)
    {
      result = binary(i,counter);
      cout << endl<<result << " for " << i<<endl;
    }
  return 0;
}

/*
int binary( int n,int r, int count )
{  

  

  if( n == 0 && r == 0)
    return count;
  
  if( n == 0 && r == 1)
    return count + 1;
  
  if( n == 1 && r == 1)
    return count + 1;
  
  if(n == 1 && r == 0)
    return count;
  
  if( n % 2 == 1 && r == 1)
    return binary(n/2,n%2, count + 1);
  if( n % 2 == 0 && r == 0)
    return binary(0,n%2, count + 1);
  if( n % 2 == 0 && r == 1)
    return binary(n/2,n%2, count);
}



int binary( int n, int count)
{

  return  binary(n, n%2, count);
}
*/
