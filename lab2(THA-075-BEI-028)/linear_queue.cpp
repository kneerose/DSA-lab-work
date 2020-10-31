#include <iostream>
#define max 5
using namespace std;
int array[max],front=-1,rear=-1;
void enqueue()
{
    int val;
    if (rear>=max-1)
    {
        cout<<"Queue overflow"<<endl;
    }
    else
    {
        if(front==-1 && rear==-1)
        {
            rear=0;
            front=0;
        }
        else
        {
        rear++;
        }
        cout<<"enter the element you want to push in queue"<<endl;
        cin>>val;
       array[rear]=val;
       cout<<"enqueue element is :"<<array[rear]<<"\t"<<"front =\t"<<front<<"\trear= \t"<<rear<<endl;


    }

}
void dequeue()
{
    if(rear<front || front==-1)
    {
        cout<<"queue underflow"<<endl;
    }
    else
    {
        cout<<"dequeue element is : "<<array[front]<<"\t"<<"front =\t"<<front<<"\trear= \t"<<rear<<endl;
        array[front]=0;
        front++;
    }

}
void display()
{
    if(rear<front || front==-1)
    {
    cout<<"empty queue"<<endl;
    }
    else {
    cout<<"element in queue are \t";
    for(int i=0;i<=max-1;i++)
    {
        cout<<array[i];
        cout<<"\t";
    }
    cout<<"front =\t"<<front<<"\trear= \t"<<rear<<endl;
    }
    cout<<endl;
}
int main (){
    int a;
    cout<<"1. enqueue "<<endl;
    cout<<"2. dequeue "<<endl;
    cout<<"3. display queue "<<endl;
    cout<<"4. exit"<<endl;
    do{
    cout<<"choose the option : \t \t ";
    cin>>a;
    switch(a)
    {
        case 1:enqueue();
                break;
        case 2:dequeue();
                break;
        case 3:display();
                break;
        case 4:break;
        default: cout<<"invalid input"<<endl;
    }
    }while(a!=4);

}
