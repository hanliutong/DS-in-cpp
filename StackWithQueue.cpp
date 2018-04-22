#include <queue>
#include <iostream>
using namespace std;
class MyStack {
private:
	queue<int> Q1;
	queue<int> Q2;
public:
      MyStack() {
        
    }
    
    void push(int x) {
        if (Q1.empty())
        {
        	Q2.push(x);
        }else{
        	Q1.push(x);
        }
    }
    
    int top() {
    	if (Q1.empty())
    	{	while(!Q2.empty()){
    		if (Q2.size() == 1)
    		{
    			int temp = Q2.front();
    			Q1.push(temp);
    			Q2.pop();
    			return temp;
    		}
    		Q1.push(Q2.front());
    		Q2.pop();
    		}
    	}else{
    		while(!Q1.empty()){
    		if (Q1.size() == 1)
    		{
    			int temp = Q1.front();
    			Q2.push(temp);
    			Q1.pop();
    			return temp;
    		}
    		Q2.push(Q1.front());
    		Q1.pop();
    		}
    	}
    return 0;    
    }
    
    int pop() {
        if (Q1.empty())
    	{	while(!Q2.empty()){
    		if (Q2.size() == 1)
    		{
    			int temp = Q2.front();
    			Q2.pop();
    			return temp;
    		}
    		Q1.push(Q2.front());
    		Q2.pop();
    		}
    	}else{
    		while(!Q1.empty()){
    		if (Q1.size() == 1)
    		{
    			int temp = Q1.front();
    			Q1.pop();
    			return temp;
    		}
    		Q2.push(Q1.front());
    		Q1.pop();
    		}
    	}
    }
    
    bool empty() {
        if (Q1.empty()&&Q2.empty())
        {
        	return 1;
        }
        return 0;
    }

};

int main()
{
	MyStack S1;
	S1.push(1);
	S1.push(2);
	// S1.top();
	cout << S1.top() <<endl;
	S1.pop();
	// S1.top();
	cout << S1.top() <<endl;
	S1.pop();
	cout << S1.empty() <<endl;
	return 0;
}