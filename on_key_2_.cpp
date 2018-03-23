#include "lnkStack.h"
#include "lnkQueue.h"
#include "BinaryTreeNode.h"
#include <stack> 
#include <iostream>
#include "lnkList.h"
#include <string>
#include "string.h"
using namespace std;
bool isOperator(char &x){
	cout << "\t\t\tisOperator is called\n";
	for (int i = 40; i <= 47; i++)
	{
		if (int(x) == i)
		{
			return 1;
		}
	}
	return 0;
} 



bool isDigital(char &x){
	if (int(x) == 46)// '.'
	{
		return 1;
	}
	for (int i = 48; i <= 57; i++)//0-9
	{
		if (int(x) == i)
		{
			return 1;
		}
	}
	return 0;
}

double  exp10(int x){
	double sum = 1.0;
	if (x >= 0)
	{
		for (int i = 0; i < x; i++)
		{
			sum = sum * 10;
		}
	}else
	{ 
		for (int i = 0; i > x; i--)
		{
			cout << "1sum = " << sum <<endl; 
			sum = sum * 0.1;
			cout << "1sum = " << sum <<endl; 
		}

	}
	return sum;	
	
}
int getlens(string x){
	int i = 0;
	while ( x[i] != '#' )
		{
			i++;
		}
	return i + 2;
}

double getDigital(string x,int &j){
	cout << "Doing getDigital" <<endl;
	if (isDigital(x[0]) == 0)
	{
		return -1;
		cout << "err" <<endl;
	}
	lnkQueue<double> temp;
	int i =0;
	double sum = 0;
	int dot = 0;
	double y = 0;
	j=0;
	if (isDigital(x[j]) == 0)
	{
		cout << "err : getDigital error with front is not a digital" <<endl;
	}
	while (isDigital(x[j]))
	{	//cout  << "sum = "<< sum <<endl;
		if (dot == 0)
		{
			while ( isDigital(x[i]) && x[i] !='.'  )
			{	cout << "i = " << i <<endl;
				temp.enQueue( int(x[i]) -48 );
				i++;
			}
			j = i;
			if (x[i] =='.')
			{
				dot = 1;
				cout << "dot = 1" << x[j] <<endl;
			}
			while (i)

			{	
				cout << "sum = "<< sum <<endl;
				--i;
				temp.deQueue(y);
				sum = sum + y*exp10(i);
			}
		} else
		{	i = j + 1;//从 ‘.’后面开始
			while ( isDigital(x[i]) && x[i] !='.')
			{
				temp.enQueue( int(x[i]) -48 );
				i++;
			}
			int k=i-j-1;
			cout << "k = " << k << endl;
			cout << exp10(-1) <<endl;
			j = i;
			while (k)
			{
				
				temp.deQueue(y);
				sum = sum + y*exp10(-k);
				k--;
			}

		}
	}
	cout  << "sum = "<< sum <<endl;	
 	return sum;
 }

int cpr_priority( int int_opr){
	switch (int_opr)
	{
		case int('+') : return 0;
		case int('-') : return 1;
		case int('*') : return 2;
		case int('/') : return 3;
		case int('(') : return 4;
		case int(')') : return 5;
		case int('#') : return 6;
		default : exit(2);
	}
}

int main()

{	lnkStack<int> oprator;
	oprator.push(-1);
	int t_opr = 0;
	int priority[7][7]={
		{2,2,0,0,0,2,2},
		{2,2,0,0,0,2,2},
		{2,2,0,0,0,2,2},
		{2,2,0,0,0,2,2},
		{0,0,0,0,0,1,-1},
		{2,2,2,2,-1,2,2},
		{0,0,0,0,0,0,1}
	};
	string bef = "1.1/(20-0)+400*505#";
	//string bef = "101/(202-303)+404+505*606#";
	//string bef = "10+10#";
	lnkList<string> Postfix;
	string aft = "";
	string str_tmp = "";
	//int n = getlens(bef);//获得字符串长度
	//cout << "n = " << n << endl;
	double temp = 0;
	int len = 0;
	while (bef[0] != '#')
	{
		cout <<"bef = "<<bef<<endl;
		temp = getDigital(bef,len);
		cout << "temp = " << temp << "\t" << endl;
		Postfix.append( to_string(temp) );
		aft += to_string(temp);
		aft += ",";
		//cout << "bef = " << bef <<endl;
		for (int j = 0; j < len  ; j++)//temp的数字被删去
		{

			for (int i = 0; i < getlens(bef); i++)
			{
			bef[i] = bef[i+1];
			}
			cout << "正在删除" << temp << endl;
		}
		cout << "bef = " << bef <<endl;
		while (isOperator(bef[0]))
		{
			int opr = int(bef[0]);
			for (int i = 0; i < getlens(bef); i++) //删去符号
				{
				bef[i] = bef[i+1];
				}
			cout << "opr = " << char(opr) <<endl;
			if (opr == 40)//   ( 就入栈
				{
				oprator.push(opr);
				}
			else if (opr == 41)
				{
					oprator.getTop(t_opr);
					if (t_opr == -1)//栈空 缺少左括号
					{
						cout <<"err"<<endl;
						exit (3);
					}
					t_opr = 0;
					while (t_opr != -1 && t_opr != 40 )//连续出栈
					{
						oprator.pop(t_opr);
						if (t_opr != 40)// ( 不进表达式
						{
							cout << "aft is adding : " << char(t_opr) <<endl;
							str_tmp = "";
							str_tmp += char(t_opr);
							Postfix.append( str_tmp );
							aft += char(t_opr);
							aft += ",";
						}
					}
					if (t_opr == -1)//没遇到左括号
					{
						cout <<"err"<<endl;
						exit (1);
					}
				}
			else 
				{oprator.getTop(t_opr);
					while (t_opr != -1 && t_opr != 40 && ( priority[cpr_priority(t_opr)][cpr_priority(opr)] != 0 ))
					{
						oprator.pop(t_opr);
						if (t_opr == -1)
						{
							oprator.push(-1);
							break;
						}else if (t_opr != 40)
							{
								cout << "aft is adding : " << char(t_opr) <<endl;
								str_tmp = "";
								str_tmp += char(t_opr);
								Postfix.append( str_tmp );
								aft += char(t_opr);
								aft += ",";
							}
					}
					oprator.push(opr);


				}
			


		}
	}//中值表达式入读结束
	oprator.getTop(t_opr);
	while(t_opr != -1){
		oprator.pop(t_opr);
		if (t_opr != -1)
		{
			cout << "aft is adding : " << char(t_opr) <<endl;
			str_tmp = "";
			str_tmp += char(t_opr);
			Postfix.append( str_tmp );
			aft += char(t_opr);
			aft += ",";
		}
	}

	cout << "后缀表达式aft = " << aft << endl;
	int length = Postfix.length();
	cout << "length = " << length << endl;
	string travel;
		// Postfix.getValue(0,travel);
		// cout << travel <<"\t";
	Postfix.travel();

	return 0;
}