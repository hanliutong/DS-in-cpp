#include "lnkStack.h"
#include "lnkQueue.h"
#include <iostream>
#include "lnkList.h"
#include <string>
// #include <queue>
#include "string.h"
#include "BinaryTree.h"
// #include "stdio.h"
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
		default : {cout << "err: cpr_priority has an error in default :" << int_opr << "(ASCII)" << endl; exit(0);}
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

void getTwoDig(lnkStack<double> &s , double &s1 , double &s2){
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

void In2Post(string bef, lnkList<string> &Postfix )

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
	string str_tmp = "";
	double temp = 0;
	int len = 0;
	while (bef[0] != '=')
	{
		if (isDigital(bef[0]))
		{
			temp = getDigital(bef,len);
			char c[len];
			sprintf(c, "%.1f", (double)temp);
			string s = c;
			Postfix.append( s );
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

	// cout << "后缀表达式 : ";
	// Postfix.travel();
}

void Post2Tree(lnkList<string> &Postfix, BinaryTree<string> & Tree){
	lnkStack<BinaryTreeNode<string>*> Node;
	string temp_Postfix_string;
	BinaryTree<string> Tree_temp;
	BinaryTreeNode<string> *Root, *Left, *Right ,*Troot;
	while (Postfix.getValue(0,temp_Postfix_string )){
		Postfix.del(0);
		if (isDigital(temp_Postfix_string[0])){
			Node.push(new BinaryTreeNode<string> (temp_Postfix_string));
		}
		else{
			Root = new BinaryTreeNode<string> (temp_Postfix_string);
			if (Node.isEmpty()){
				cout << "err: Post2Tree error with Node(stack) is empty -Right" <<endl;
				exit(0);
			}
			Node.pop(Right);
			if (Node.isEmpty()){
				cout << "err: Post2Tree error with Node(stack) is empty -Left" <<endl;
				exit(0);
			}

			Node.pop(Left);
			Tree_temp.CreateTree(Root,Left,Right);
			Node.push(Root);

		}
	}
	Node.pop(Troot);
	Tree.CreateTree(Troot);

}
void Tree2In(BinaryTree<string> &tree){

	BinaryTreeNode<string>* Root = tree.Root();
	TreeNode2In(Root,0);
}

void TreeNode2In(BinaryTreeNode<string>*root,bool flag){
	int priority[4][4]={
		{1,1,0,0},
		{1,1,0,0},
		{2,2,1,1},
		{2,2,1,1},
	};
	if (flag == 1)
	{
		cout << "(";
	}
	if (root -> left)
	{	
		if (isOperator(root -> left -> info[0]) && priority[cpr_priority(int(root->info[0]))][cpr_priority(int(root -> left -> info[0]))] == 2 )
		{
			TreeNode2In(root -> left,1);
		}else{
			TreeNode2In(root -> left,0);
		}
			
	}

		cout << root -> info << " ";
	
	if (root -> right)
	{
		if (isOperator(root -> right -> info[0]) && priority[cpr_priority(int(root->info[0]))][cpr_priority(int(root -> right -> info[0]))] == 2 )
		{
			TreeNode2In(root -> right,1);
		}else{
			TreeNode2In(root -> right,0);
		}
	}
	if (flag == 1)
		cout << ")";
}

void Post2Post(string Post, lnkList<string> &Postfix ){
	double temp = 0;
	int len = 0;

	while (Post[0] != '='){
		if (isDigital(Post[0])){
			temp = getDigital(Post,len);
			char c[len];
			sprintf(c, "%.1f", (double)temp);
			string s = c;
			Postfix.append( s );
			string_del(Post,len);
		}
		else if (isOperator(Post[0]))
		{	string str_tmp = "";
			str_tmp += Post[0];
			Postfix.append(str_tmp);
			string_del(Post,1);
		}
		else{
			cout << "warning : Illegal input has been ignored\n";
			string_del(Post,1);
		}
	}
}

void Pre2Tree(string Post, BinaryTree<string> &t ){
	lnkStack<string> str_Stack;
	double temp = 0;
	int len = 0;
	while (Post[0] != '='){
		if (isDigital(Post[0])){
			temp = getDigital(Post,len);
			char c[len];
			sprintf(c, "%.1f", (double)temp);
			string s = c;
			str_Stack.push( s );
			string_del(Post,len);
		}
		else if (isOperator(Post[0]))
		{	string str_tmp = "";
			str_tmp += Post[0];
			str_Stack.push(str_tmp);
			string_del(Post,1);
		}
		else{
			cout << "warning : Illegal input has been ignored\n";
			string_del(Post,1);
		}
	}
	
	string pop;
	lnkStack<BinaryTree<string>> s;
	
	while (!str_Stack.isEmpty())
    {	
    	str_Stack.pop(pop);
        if (isDigital(pop[0])) {
            t.CreateTree(pop, NULL, NULL);
            s.push(t);
        } else {
            BinaryTree<string> t_1;
            if (s.isEmpty())
            {
            	cout << "err!"<<endl;
            	exit(0);
            }
            s.pop(t_1);
            BinaryTree<string> t_2;
            if (s.isEmpty())
            {
            	cout << "err!"<<endl;
            	exit(0);
            }
            s.pop(t_2);
            t.CreateTree(pop, &t_1, &t_2);
            s.push(t);
        }
    }

}
	lnkList<string> Postfix;
int main(){
	BinaryTree<string> Tree;


//————————————————————————————————用户输入——————————————————————————————————————————
	string str = "- + / 1.0 - 2.0 / 30.0 3.0 + 40.0 55.0 * 0.1 66.0 =";//前缀
	// string str = "1/(2-30/3)+(40+55)-0.1*66=";//中缀
	// string str = "1.0 2.0 30.0 3.0 / - / 40.0 55.0 + + 0.1 66.0 * - =";//后缀
	
	int input = 0;//0->前缀； 1->中缀； 2->后缀；
	int output = 1;
	// cout << "output = ";
	// cin >> output;
	// output = 2;

//————————————————————————————————用户输入——————————————————————————————————————————


	switch(input){
		case 0 : {Pre2Tree(str,Tree); break;}
		// case 1 : {lnkList<string> Postfix; In2Post(str,Postfix); Post2Tree(Postfix,Tree);break;}
		// case 2 : {lnkList<string> Postfix; Post2Post(str,Postfix); Post2Tree(Postfix,Tree);break;}
		case 1 : {In2Post(str,Postfix); Post2Tree(Postfix,Tree);break;}
		case 2 : {Post2Post(str,Postfix); Post2Tree(Postfix,Tree);break;}
		default : {cout << "Illegal input" << endl; exit(0);}
	}

	Tree.print();

	switch(output){
		case 0 : {Tree.PreOrder(Tree.Root()); break;}
		case 1 : {Tree2In(Tree); break;}
		case 2 : {Tree.PostOrder(Tree.Root());;break;}
		default : {cout << "Illegal input" << endl; exit(0);}
	}

	return 0;
}