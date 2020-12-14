//3.WAP to check parenthesis of algebraic expression using stack
#include <iostream>
#define SIZE 5
using namespace std;
class stack
{
    public:
    int tos=-1;
    int array[SIZE];
        bool isEmpty()
        {
            if(tos==-1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        bool isFull()
        {
            if(tos==(SIZE-1))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        void push(int value)
        {
            if(isFull()==true)
                cout<<"Stack Overflow";
            else
            {
                tos++;
                array[tos] = value;
            }
        }
        void pop()
        {
            if(isEmpty()==true)
                cout<<"Stack underflow";
            else
            {
                tos--;
            }
        }
};
bool check_parenthesis(string infix)
{
    stack stk;
    for(int i=0; i<infix.length(); i++)
    {
        if(infix[i]=='(' || infix[i]=='[' || infix[i]=='{')
            stk.push(infix[i]);
        else if(infix[i]==')')
        {
            if(stk.isEmpty()!=true)
                if(stk.array[stk.tos]=='(')
                    stk.pop();
            else
                return false;
        }
        else if(infix[i]=='}')
        {
            if(stk.isEmpty()!=true)
                if(stk.array[stk.tos]=='{')
                    stk.pop();
            else
                return false;
        }
        else if(infix[i]==']')
        {
            if(stk.isEmpty()!=true)
                if(stk.array[stk.tos]=='[')
                stk.pop();
            else
                return false;
        }
    }
    if(stk.isEmpty()==true)
        return true;
    else if(stk.isEmpty()==false)
        return false;
}



int main()
{
    string infix_exp;
    cout<<"enter the algebraic expression "<<endl;
    cin>>infix_exp;
    bool check = check_parenthesis(infix_exp);
    if(check==true)
        cout<<"Balanced";
    else
        cout<<"Unbalanced";
}
