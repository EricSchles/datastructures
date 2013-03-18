#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cmath>
using namespace std;


//Read in a file character by character
//if the character is a space skip - use isspace() to do this
//convert the characters to integers
//sum the integers
//convert to binary
//output the checksum

//void integer_to_binary(int summation, char * file);
//expects the sum of the ASCII characters in the file
//returns a binary representation of the sum

void binary(int number);

int main(int argc, char *argv [ ] )
{
  //to do, take a command line argument
  //set it equal to file variable before testing
  ifstream myfile;
  string line;
  if( argc > 2)
    {
      cout<< "too many command-line arguments";
      exit(1);
    }
  myfile.open(argv[1]);
  if( !myfile.is_open( ))
    {
      cout << "File failed to open";
      exit(1);
    }

  char ch;
  int sum;
  int convert;
   while( myfile.good( )) //not eof, this is more general -> better
    {
      getline(myfile,line);
      int length = line.length( );
      for(int i =0; i < length;i++)
	{
	  ch = line[i];
	  if( ( !isspace( ch ) ) && (ch != '\t') && ( ch != '\n' ) && (ch != '\v') && (ch !='\f') && (ch != '\r') )
	    {
	      convert = ch; //converts character to integer
	      sum += convert;
	    }
	}
    }

   
  cout << "The check sum is "; 
  binary(sum);
  cout<< " for file " <<argv[1];
   //   integer_to_binary(sum,argv[1]);
  
  myfile.close( );
  return 0;
}

/*
void integer_to_binary(int summation, char * file)
//expects the sum of the ASCII characters in the file
//returns a binary representation of the sum
{
  int binary[32];
  int sum = summation;
  double summer = static_cast<double>(sum);
  //initialize to 0 for 32 bit number
  for(int i = 0; i < 32; i++)
    {binary[i] = 0;}
  int count = 0;
  for(int i = 0; i < 32;i++)//figure out how many places to use for binary
    {
      if( summation/2 > 0)
	++count;
      summation = summation/2;
    }
 
  count = 32 - count;
      
  for(int i = count; (i > 0)  && ( i > (32-count) ); --i)
    {
      cout << endl << i << endl;
      if( sum == 1 )
	{
	  binary[0] = 1;
	    --sum;  
	}
      if( sum % 2 == 0 )
	binary[i] = 1;
      else
	binary[i] = 0;
      
      sum /= 2;
    
    }
  
  cout << "The check sum is "; 
  for(int i = 31; i > 0;--i)
    cout <<binary[i];
  cout<< " for file " <<file;

}
*/
void binary(int number) {
	int remainder;

	if(number <= 1) {
		cout << number;
		return;
	}

	remainder = number%2;
	binary(number >> 1);    
	cout << remainder;
}
