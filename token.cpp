#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

void tokenizer( char s[],  vector<string> & tokens, const char delim[] )
{
	tokens.clear();
	char * pch;
	pch = strtok (s, delim);
	while (pch != NULL)
	{
		string temp = pch;
		tokens.push_back(pch);
		pch = strtok (NULL, delim);
	}
}

// Here is a toy example showing how tokenizer works.
int main()
{
  const char *delim = " ->,";
  vector<string> tokens(4);

  char temp[7];
  strcpy(temp,"a-b>c");

  
  tokenizer(temp, tokens, delim);
  cout << tokens[0] << tokens[1] << tokens[2] << endl;

  
  return 0;
}
