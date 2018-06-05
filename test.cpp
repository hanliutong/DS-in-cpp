#include<iostream>

using namespace std;
int col(int x,int y){
	return y*y + x*x + 7*x;
}

int SI(int x,int y){
		cout << "x = " << x << "\t y = " << y << endl;
		int FO = col(x,y);
		int FY = col(x,y+1);
		int FX = col(x+1,y);
		if (FO > FY && FY > FX ) SI(x+2,y);
		if (FO > FX && FX > FY ) SI(x,y+2);
		if (FO < FX && FX < FY ) SI(x,y-2);
		if (FO < FY && FY < FX ) SI(x-2,y);
		if (FY < FO && FO < FX ) SI(x-2,y+2);
		if (FX < FO && FO < FY ) SI(x+2,y-2);
		return 0;
}



int show (int x ,int y){
	cout << col(x,y) << "\t";
	cout << col(x+1,y) << "\t";
	cout << col(x,y+1) << "\t" <<endl;
	if (col(x+1,y) > col(x,y+1)) return 1;
	if (col(x+1,y) < col(x,y+1)) return 2;
	return 0;

}



int main(){

int x = 5, y = 7;
for (int i = 0; i < 17; ++i)
{	cout << i << "\t";
	if (show(x,y) == 1) x--;
	else y--;
	if (i == 15) cout << x << "\t" << y;
}



	return 0;
} 