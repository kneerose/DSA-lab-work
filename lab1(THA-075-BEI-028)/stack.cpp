//1.WAP for array implementation of Stack
#include <iostream>
using namespace std;
#define max 5
int array[max],stack=-1;
void push()
{
    int val;
    if (stack==max-1)
    {
        cout<<"stack overflow"<<endl;
    }
    else
    {
        cout<<"enter the element you want to push in stack "<<endl;
        cin>>val;
        stack++;
       array[stack]=val;
       cout<<"pushing element is :"<<array[stack]<<endl;

    }

}
void pop()
{
    if(stack==-1)
    {
        cout<<"stack underflow"<<endl;
    }
    else
    {
        cout<<"popping element is : "<<array[stack]<<endl;
        stack--;
    }

}
void display()
{
    if(stack==-1)
    {
    cout<<"empty stack"<<endl;
    }
    else {
    cout<<"element in stack are \t";
    for(int i=0;i<=stack;i++)
    {
        cout<<array[i];
        cout<<"\t";
    }
    }
    cout<<endl;
}
int main (){
    int a;
    cout<<"1. stack push "<<endl;
    cout<<"2. stack pop "<<endl;
    cout<<"3. display stack "<<endl;
    cout<<"4. exit"<<endl;
    do{
    cout<<"choose the option : \t \t ";
    cin>>a;
    switch(a)
    {
        case 1:push();
                break;
        case 2:pop();
                break;
        case 3:display();
                break;
        case 4:break;
        default: cout<<"invalid input"<<endl;
    }
    }while(a!=4);

}
