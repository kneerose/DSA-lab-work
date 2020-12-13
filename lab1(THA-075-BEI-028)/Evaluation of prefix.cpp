//WAP to evaluate a prefix expression
#include<iostream>
#include<math.h>
#define max 100
using namespace std;

class stack
{
    int data[max];
    int top;
public:
    stack()
    {
        top=-1;
    }
    int isFull()
    {
        if(top==(max-1))
            return(1);
        return(0);
    }
    int isEmpty()
    {
        if(top==-1)
        {
            return(1);
        }
        else
        {
            return 0;
        }
    }
    void push(int val)
    {
        int i;
        i=isFull();
        if(i==0)
        {
            top++;
            data[top]=val;
        }
    }
    int pop()
    {
        int i;
        int value;
        i=isEmpty();
        if(i==0)
        {
            value=data[top];
            top--;
        }
        return value;
    }
};
float prefix_evaluate(stack s,string postfix)
{
    int a,b,x;
    float result;
    for(int i=postfix.length()-1;i>=0;i--)
    {
        if(postfix[i]>='0' && postfix[i]<='9')
        {
            x=postfix[i]-48;
            s.push(x);
        }
        else if(postfix[i]=='+'|| postfix[i]=='-'|| postfix[i]=='*'|| postfix[i]=='/'|| postfix[i]=='$')
        {
            a=s.pop();
            b=s.pop();
            switch(postfix[i])
            {
            case'+':
                result=a+b;
                s.push(result);
                break;
            case'-':
                result=a-b;
                s.push(result);
                break;
             case'*':
                result=a*b;
                s.push(result);
                break;
            case'/':
                result=a/b;
                s.push(result);
                break;
            case'$':
                result=pow(b,a);
                s.push(result);
                break;
            }
        }
    }
    return s.pop();
}
int main()
{
    stack s;
    string prefix_exp;
    float evaluated_result;
    cout<<"Enter the prefix Expression:";
    cin>>prefix_exp;
    evaluated_result=prefix_evaluate(s,prefix_exp);
    cout<<"The evaluated result is: "<<evaluated_result<<endl;
    return 0;
}

