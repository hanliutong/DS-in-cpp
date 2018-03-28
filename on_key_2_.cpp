	#include "lnkStack.h"
	#include "lnkQueue.h"
//#include "BinaryTreeNode.h"
//#include <stack> 
#include <iostream>
	#include "lnkList.h"
#include <string>
#include "string.h"
using namespace std;
bool isOperator(char &x){
	//cout << "\t\t\tDoing isOperator\n";
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
	//cout << "\t\t\tDoing isDigital\n";
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
	//cout << "\t\t\tDoing exp10\n";
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
			//cout << "1sum = " << sum <<endl; 
			sum = sum * 0.1;
			//cout << "1sum = " << sum <<endl; 
		}

	}
	return sum;	
	
}
int getlens(string x){
	//cout << "\t\t\tDoing getlens\n";
	int i = 0;
	while ( x[i] != '=' )
		{
			i++;
		}
	return i + 2;
}

double getDigital(string x,int &j){
	//cout << "\t\t\tDoing getDigital" <<endl;
	if (isDigital(x[0]) == 0)
	{
		cout << "err : getDigital error with front is not a digital" <<endl;
		exit(0);
		return -1;
	}
	lnkQueue<double> temp;
	lnkStack<double> temp_;
	int i =0;
	double sum = 0;
	int dot = 0;
	double y = 0;
	j=0;

	while (isDigital(x[j]))
	{	//cout  << "sum = "<< sum <<endl;
		if (dot == 0)
		{
			while ( isDigital(x[i]) && x[i] !='.'  )
			{	//cout << "i = " << i <<endl;
				temp.enQueue( int(x[i]) -48 );
				i++;
			}
			j = i;
			if (x[i] =='.')
			{
				dot = 1;
				//cout << "dot = 1" << x[j] <<endl;
			}
			while (i)
			{	
				//cout << "sum = "<< sum <<endl;
				--i;
				temp.deQueue(y);
				sum = sum + y*exp10(i);
			}
		} else
		{	i = j + 1;//从 ‘.’后面开始
			while ( isDigital(x[i]) && x[i] !='.')
			{
				temp_.push( int(x[i]) -48 );
				i++;
			}
			if (x[i] == '.')
			{
				cout << "err : more than one '.' ";
				exit(0);
			}
			int k=i-j-1;
			//cout << "k = " << k << endl;
			j = i;
			while (k)
			{
				
				temp_.pop(y);
				//cout << k << " : " << y <<endl;
				if (y != 0){
				//cout << y <<"*10^"<<-k<<endl;
				sum = sum + y*exp10(-k);}
				k--;
			}

		}
	}
	//cout  << "f_sum = "<< sum <<endl;	
 	return sum;
 }

double getDigFormLnk(lnkList<string> Pf){
	cout <<"Doing getDigFormLnk\n";
	double Postfix_double = 0;
	string Postfix_srtring;
	int count = 0;
	Pf.getValue(0,Postfix_srtring);
	Postfix_double = getDigital(Postfix_srtring,count);
	//cout << "Postfix_double" << Postfix_double << endl;
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
		case int('=') : return 6;
		default : exit(0);
	}
}

void string_del(string &str, int len){
	// cout <<"doing string_del\n"; 
	for (int j = 0; j < len  ; j++)
		{

			for (int i = 0; i < getlens(str); i++)
			{
			str[i] = str[i+1];
			}
			//cout << "正在删除" << temp << endl;
		}
}

bool getTwoDig(lnkStack<double> &s , double &s1 , double &s2){
	if (s.isEmpty())
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
int main()

{	lnkStack<int> oprator;
	oprator.push(-1);
	int t_opr = -1;
	int priority[7][7]={
		{2,2,0,0,0,2,2},
		{2,2,0,0,0,2,2},
		{2,2,0,0,0,2,2},
		{2,2,0,0,0,2,2},
		{0,0,0,0,0,1,-1},
		{2,2,2,2,-1,2,2},
		{0,0,0,0,0,0,1}
	};
	//string bef = "0.5/(-20)=";
	string bef = "101/( 202-303/3)+(0-404)+.1*606=";
	//string bef = "10+10=";
	lnkList<string> Postfix;
	cout << "中缀表达式输入：" << bef <<endl;
	string org = bef;
	string str_tmp = "";
	//int n = getlens(bef);//获得字符串长度
	//cout << "n = " << n << endl;
	double temp = 0;
	int len = 0;
	while (bef[0] != '=')
	{
		if (isDigital(bef[0]))
		{
			temp = getDigital(bef,len);
			Postfix.append( to_string(temp) );
			string_del(bef,len);
		}else if(isOperator(bef[0]))
		{		

			int opr = int(bef[0]);
			string_del(bef,1);//删去第一个字符（即符号）
			if (opr == 40)//   ( 就入栈
				{
				oprator.push(opr);
				}
			else if (opr == 41)
				{
					oprator.getTop(t_opr);
					if (t_opr == -1)//栈空 缺少左括号
					{
						cout <<"err : expect ("<<endl;
						exit (0);
					}
					t_opr = 0;
					while (t_opr != -1 && t_opr != 40 )//连续出栈
					{
						oprator.pop(t_opr);
						if (t_opr != 40)// ( 不进表达式
						{
							
							str_tmp = "";
							str_tmp += char(t_opr);
							Postfix.append( str_tmp );
						}
					}
					if (t_opr == -1)//没遇到左括号
					{
						cout <<"err : expect '('"<<endl;
						exit(0);
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
								str_tmp = "";
								str_tmp += char(t_opr);
								Postfix.append( str_tmp );
							}
					}
					oprator.push(opr);
				}
		}
		else {cout << "warning : Illegal input has been ignored\n";string_del(bef,1);}
		//else {cout << "err : Illegal input\n"; exit(0);}
	}//中值表达式入读结束
	oprator.getTop(t_opr);//输出到栈空
	while(t_opr != -1){
		oprator.pop(t_opr);
		if (t_opr != -1)
		{
			str_tmp = "";
			str_tmp += char(t_opr);
			Postfix.append( str_tmp );
		}
	}

	cout << "后缀表达式 : ";
	Postfix.append("=");
	Postfix.travel();

	string temp_Postfix_string;
	double temp_Postfix_double = 0;
	int count = 0;
	double s1 = 0,s2 = 0, res = 0;
	lnkStack<double> s;//操作数栈s
	while(Postfix.getValue(0,temp_Postfix_string)){
		Postfix.del(0);
		switch(temp_Postfix_string[0]){
			case '+':{
				//cout << "I found a '+'!\n";
				getTwoDig(s,s1,s2);
				s.push(s1+s2);
				break;
			}
			case '-': {
				//cout << "I found a '-'!\n";
				s.pop(s2);
				s.pop(s1);
				s.push(s1-s2);
				break;
			}
			case '*': 
			{
				//cout << "I found a '*'!\n";
				s.pop(s2);
				s.pop(s1);
				s.push(s1*s2);
				break;
			}
			case '/': 
			{
				//cout << "I found a '/'!\n";
				s.pop(s2);
				s.pop(s1);
				if (s2 == 0.0)
					{
						cout << "err: Divide by 0!!!\n";
						s.clear();
						exit(0);
					}
				else s.push(s1/s2); 
				break;
			}
			case '=': 
			{
				s.pop(res); 
				break;
			}
			default : 
			{
				temp_Postfix_double = getDigital(temp_Postfix_string,count); 
				//cout <<"temp_Postfix_double = " << temp_Postfix_double <<endl;
				s.push(temp_Postfix_double); 
				break;
			}
		}
	}
	cout << org << res << endl;


	return 0;
}