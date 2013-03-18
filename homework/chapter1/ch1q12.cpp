#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;



int words(ifstream & in);
int characters(ifstream & in);
int lines(ifstream & in);

int main(int argc, char *argv[ ])
{

  int word_count;
  int character_count;
  int line_count;
  for(int i = 1; i < argc;i++)
    {
      ifstream myfile;
      
      myfile.open( argv[ i ] );
      if( !myfile.good( ))
	{
	  cout << "there was an error openning the file 1";
	  exit(1);
	}
      word_count = words(myfile);
       myfile.clear( );
      myfile.close( );
      
      myfile.open( argv[ i ] );
      if( !myfile.good( ))
	{
	  cout << "there was an error openning the file 2";
	  exit(1);
	}
     
      character_count = characters(myfile);
      myfile.close( );
      myfile.open( argv[ i ] );
      if( !myfile.good( ))
	{
	  cout << "there was an error openning the file 3";
	  exit(1);
	}
      line_count = lines(myfile);
      myfile.close( );
      cout << word_count << " is the number of words in file: " << argv[i] <<" (should be 3)";
      cout <<endl<< character_count << " is the number of characters in file: " << argv[i]<<" (should be 8)";
      cout <<endl<< line_count << " is the number of lines in file: " << argv[i]<<endl<<" (should be 1)";
    }


  return 0;
}

int words(ifstream & in)
{
  string word;
  int count = 0;
  while(in >> word)
    {
      count++;
    }

  return count;
}

int characters(ifstream & in)
{
  char ch;
  int count = 0;
  
  while( in >> ch )
    {
      
      count++;
    }
  return count;
}

int lines(ifstream & in)
{
  int count = 0;
  string line;
  //in >> getline(line);
  while( getline(in,line) )
    {
      count++;
    }

  return count;
}
