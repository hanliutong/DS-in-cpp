#include "lnkStack.h"
#include "lnkQueue.h"
#include "lnkList.h"
#include <iostream>
#include <string>
using namespace std;
bool isOperator(char &x){//O（1）
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

bool isNum(char &x){//O（1）
	//cout << "\t\t\tDoing isNum\n";
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

double exp10(int x){
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

int getlens(string x){//O（1）
	//cout << "\t\t\tDoing getlens\n";
	int i = 0;
	while ( x[i] != '=' )
		{
			i++;
		}
	return i + 2;
}

double getNum(string x,int &j){
	//cout << "\t\t\tDoing getNum" <<endl;
	if (isNum(x[0]) == 0)
	{
		cout << "err : getNum error with front is not a digital" <<endl;
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

	while (isNum(x[j]))
	{	//cout  << "sum = "<< sum <<endl;
		if (dot == 0)
		{
			while ( isNum(x[i]) && x[i] !='.'  )
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
			while ( isNum(x[i]) && x[i] !='.')
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


int cpr_priority( int int_opr){
//返回符号在优先级矩阵中的位置
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
		}
}

void getTwoNum(lnkStack<double> &s , double &s1 , double &s2){
	if (s.isEmpty())
	{
		cout << "err : expect number(s2)\n";
		exit(0);
	}
	s.pop(s2);
	if (s.isEmpty())
	{
		cout << "err : expect number(s1)\n";
		exit(0);
	}
	s.pop(s1);
}

int main()
{	lnkStack<int> oprator;
	oprator.push(-1);//监视
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
	// string bef = "1.1.1*10=";
	// string bef = "20/1+=";
	string bef = "101/(202-303 / 3)+0.1*61a=";
	// string bef = "10+10=";
	lnkList<string> Postfix;//用来保存后缀表达式的链表
	cout << "中缀：" << bef <<endl;
	string org = bef;//保存输入，用于最后展示结果
	string str_tmp = "";//操作符暂存
	double temp = 0;//数字暂存
	int len = 0;
//————————————————————————————中缀转后缀————————————————	
	while (bef[0] != '=')
	{
		if (isNum(bef[0]))//是数字？
		{
			temp = getNum(bef,len);
			Postfix.append( to_string(temp) );
			string_del(bef,len);
		}else if(isOperator(bef[0]))//是符号？
		{		

			int opr = int(bef[0]);
			string_del(bef,1);//删去第一个字符（即符号）
			if (opr == 40)//   是左括号就入栈
				{
				oprator.push(opr);
				}
			else if (opr == 41)//是右括号就去栈里找
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
			else //不是括号
				{
					oprator.getTop(t_opr);
					while (t_opr != -1 && t_opr != 40 && //↓比较优先级
						( priority[cpr_priority(t_opr)][cpr_priority(opr)] != 0 ))
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
		else {//既不是数字也不是符号，则跳过
			cout << "warning : Illegal input has been ignored\n";
			string_del(bef,1);
		}
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
//————————————————————————————后缀表达式求值————————————————
	cout << "后缀：";
	Postfix.append("=");
	Postfix.travel();

	string temp_Postfix_string;
	double temp_Postfix_double = 0;
	int count = 0;
	double s1 = 0,s2 = 0, ans = 0;
	lnkStack<double> s;//操作数栈s
	while(Postfix.getValue(0,temp_Postfix_string)){
		Postfix.del(0);
		switch(temp_Postfix_string[0]){
			case '+':{
				getTwoNum(s,s1,s2);
				s.push(s1+s2);
				break;}
			case '-': {
				s.pop(s2);
				s.pop(s1);
				s.push(s1-s2);
				break;}
			case '*': {
				s.pop(s2);
				s.pop(s1);
				s.push(s1*s2);
				break;}
			case '/': {
				s.pop(s2);
				s.pop(s1);
				if (s2 == 0.0){
						cout << "err: Divide by 0!\n";
						s.clear();
						exit(0);}
				else s.push(s1/s2); 
				break;}
			case '=': {
				s.pop(ans);
				break;}
			default : {
				temp_Postfix_double = getNum(temp_Postfix_string,count); 
				s.push(temp_Postfix_double); 
				break;}
		}
	}
	cout <<"结果："<< org << ans << endl;
	return 0;
}