//WAP for list implementation of QUEUE
#include<iostream>
#define max 15
using namespace std;
struct nodetype
{
    int info,next;
};
class list
{
    struct nodetype node[max];
    int avail=0;
    int front=-1,rear=-1;
public:
    int intialize_availlist()
    {
        int i;
        for(i=0;i<max-1;i++)
        {
            node[i].next=i+1;
        }
        node[max-1].next=-1;
    }
    int get_node()
    {
        int p;
        if(avail==-1)
        {
            cout<<"Overflow";
        }
        p=avail;
        avail=node[avail].next;
        return p;
    }
    int freenode(int p)
    {
        node[p].next=avail;
        avail=p;
    }
     void enqueue()
    {   int val, ptr;

        if(rear==max-1)
        {
            cout<<"Overflow"<<endl<<endl;
        }
        else
        {
            ptr = get_node();
            cout<<"Enter a value to enqueue: ";
            cin>>val;
            node[ptr].info = val;
            node[ptr].next = -1;
            if(rear == -1)
            {
                front = ptr;
            }
            else
            {
                node[rear].next = ptr;
            }
            rear = ptr;
        }
    }

    void dequeue()
    {
        int val, ptr;

        if(front>rear || front<0)
        {
            cout<<"Underflow"<<endl<<endl;
        }
        else
        {
            val = node[front].info;
            cout<<"The dequeued value is: "<<val<<endl<<endl;
            ptr = front;
            front = node[front].next;
            if(front == -1)
            {
                rear = -1;
            }
            freenode(ptr);
        }
    }
    int displaynode()
    {
       cout<<"***Created Queue***"<<endl<<endl;
       cout<<"index\t"<< "Value\t"<<"next node"<<endl;

            for(int i=front ; i <=rear; i++)
            {
                cout<<i<<"\t";
                cout<<node[i].info<<"\t";
                cout<<node[i]. next<<endl<<endl;
            }
    }
};
int main()
{
    list l;
    l.intialize_availlist();
    int ch;
    do
    {
    cout<<"1. Insert a new node: "<<endl;
    cout<<"2. Display Nodes: "<<endl;
    cout<<"3. Delete  Node"<<endl;
    cout<<"4. Exit"<<endl;
    cin>>ch;
    switch(ch)
    {
    case 1:
            l.enqueue();
            break;
    case 2:
            l.displaynode();
            break;
    case 3:
            l.dequeue();
            break;
    case 4: break;
    default: cout<<"invalid input"<<endl;
    }

    }while (ch!=4);

}
