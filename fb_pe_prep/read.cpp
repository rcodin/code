#include <iostream>
#include <fstream>
#include <cstdlib>
#include <unistd.h>

using namespace std;

int main ()
{
	ifstream ifile;
	ifile.open("test.txt", ifstream::in);
	string s;
	sleep(40);
	while (getline(ifile, s))
	{
		cout<<s<<endl;
	}

	sleep(40);
	ifile.close();

	return 0;
}
