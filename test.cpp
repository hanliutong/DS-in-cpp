#include <iostream>
#include "lnkstack.h"
using namespace std;
bool getTwoDig(lnkStack<double> &s , double &s1 , double &s2){
	cout <<s.isEmpty() <<endl;
	if (s.isEmpty() == 1)
	{
		cout << "err : expect digital(s2)\n";
		exit(0);
	}
	s.pop(s2);
	if (s.isEmpty())
	{
		cout << "err : expect digital(s1)\n";
		exit(0);
	}
	s.pop(s1);
}
int main(int argc, char const *argv[])
{	double s1 = 0,s2 = 0;
	lnkStack<double> s;
	s.push(1);
	s.push(2);
	cout <<s.isEmpty() <<endl;
	getTwoDig(s,s1,s2);
	cout << s1 <<endl;
	cout << s2 <<endl;
	return 0;
}
