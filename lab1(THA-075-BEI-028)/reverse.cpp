//2.WAP to reverse a list using stack
#include <iostream>
using namespace std;
#define max 10
int top=-1,stack[max];
void push(int x){
      if(top == max-1){
          cout<<"stack overflow"<<endl;
      }
      else {
          top++;
          stack[top]=x;
      }

}

void pop(){
    if(top==-1)
    {
        cout<<"stack underflow"<<endl;
    }
      cout<<stack[top]<<"\t";
      top--;
}


int main()
{
    int val,i;
   cout<<"----------for reverse a list----------"<<endl;
   cout<<"Enter value in list"<<endl;
   cout<<"press -1 for stop inserting value"<<endl;
   cin>>val;
   do {
        push(val);
        cin>>val;
   }while(val!=-1);
    cout<<"value in stack are :"<<endl;
    for(i=0;i<=top;i++)
    {
        cout<<stack[i]<<"\t";
    }
    cout<<endl;
    cout<<"value of stack after reverse :"<<endl;
    while(top!=-1)
      {
        pop();
      }
}
