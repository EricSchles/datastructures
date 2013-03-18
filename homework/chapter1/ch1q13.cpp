#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void read_RC(ifstream & in , int & ROW,int& COLUMN);
//read in row column
//returns nothing
void read_data(ifstream & in,int ROW,int COLUMN, char & grid[][]);
//expects a file that has height and width of a grid and then a grid
//returns a string 
void write_data(char grid[][],int ROW,int COLUMN); 
//expects a string
//prints out the string

int main(int argc, char *argv[ ])
{

  ifstream myfile;
  
  int row, column;

  myfile.open(argv[1]);
  if( !myfile.good( ) )
    {
      cout << "There was a problem openning the file";
      exit(1);
    }
  read_RC(myfile,row,column);
  myfile.clear();
  myfile.close();

  //SPACING!!!!!!!!!!!
  char GRID[row][column];
  
  myfile.open(argv[1]);
  if( !myfile.good( ) )
    {
      cout << "There was a problem openning the file";
      exit(1);
    }
  read_data(myfile,row,column,GRID);
  write_data(GRID[row][column],row,column);

  myfile.close( );
  return 0;
}

void read_RC(ifstream & in , int & ROW,int& COLUMN)
{

  in >> ROW;
  in >> COLUMN;

}

void read_data(ifstream & in,int ROW,int COLUMN,char & grid[][])
{
  char x,y;//variables to throw away
  in >> x;
  in >> y;
  for(int i = 0; i< ROW; i++)
    {
      for(int j = 0; j < COLUMN;j++)
	{
	  in >> grid[ i ][ j ];
	}
    }


}


void write_data(char grid[][],int ROW,int COLUMN)
{

  for(int i = 0; i < ROW;i++)
    {
      cout <<endl;
      for(int j = 0; j < COLUMN;j++)
	{

	  cout << grid[ i ][ j ];

	}
      
    }

}
