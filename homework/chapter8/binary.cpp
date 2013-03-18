
#include <iostream>
using namespace std;


int bitcount(int i){
    int c=0;
    
    while(i>0)
      {
	if(i == 1)
	  {
	    c+=1;
	    return c;
	  }
	int rem = i % 2;
	c+=bitcount(rem);
	i=i/2;
      }
    return c;
}

int main()
{

  int x = 15;
  int result =0;
  result = bitcount(x);
  cout <<endl<< result <<endl;

  return 0;
}
