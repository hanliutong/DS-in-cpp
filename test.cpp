#include <iostream>
using namespace std;
#include <string>
#include "string.h"

int main(int argc, char const *argv[])
{
	string s;
	double x = 123.456;
	cout << x <<endl; 
	s = to_string(x);
	char ss[7];
	sprintf(ss, "%.1f",(double) x);
	string s_s = ss; 
	cout << s_s <<endl;
	return 0;
}
