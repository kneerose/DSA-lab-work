//WAP to implement contiguous list using array
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
            exit(1);
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
    void insertnode(int &list1)
    {
        int val,ptr,curptr,newnode=1;
        while(newnode==1)
        {
            if(list1==-1)
            {
                ptr=get_node();
                list1=ptr;
                cout<<"Enter the number: ";
                cin>>val;
                node[ptr].info=val;
                node[ptr].next=-1;
            }
            else
            {
                curptr=0;
                while(node[curptr].next!=-1)
                {
                    curptr=node[curptr].next;
                }
                ptr=get_node();
                cout<<"Enter the Number: ";
                cin>>val;
                node[curptr].next=ptr;
                node[ptr].info=val;
                node[ptr].next=-1;
            }
            cout<<"enter 1 for newnode"<<endl;
            cin>>newnode;
        }
    }
    int displaynode()
    {
        cout<<"**********Displaying The list**********"<<endl;
        int i;
        int ptr=0;
        if(avail==0)
        {
            cout<<"List Underflow"<<endl;
        }
        while(ptr!=-1)
        {
            cout<<"Index: "<<ptr<<" Value: "<<node[ptr].info<<" Next: "<<node[ptr].next<<endl;
            ptr=node[ptr].next;
        }
    }
    int deletenode(int &list1)
    {
        int val,curptr,preptr=-1;
        curptr = list1;
        while(node[curptr].next!=-1)
        {
            preptr=curptr;
            curptr=node[curptr].next;
        }
        freenode(curptr);
        cout<<endl;
        cout<<"The deleted value is: "<<node[curptr].info<<endl;
        if(preptr==-1)
        {
            list1=-1;
        }
        else
        {
            node[preptr].next=-1;
        }
    }
    int insert_after(int ptr,int val)
    {
        int newptr;
        if(ptr==-1)
        {
            cout<<"Invalid Insertion";
        }
        else
        {
            newptr=get_node();
            node[newptr].info=val;
            node[newptr].next=node[ptr].next;
            node[ptr].next=newptr;
            cout<<"Inserted Node After "<<ptr<<" Value: "<<val<<" Index: "<<newptr<<endl;
        }
    }
    int delete_after(int ptr)
    {
        int delptr,delval;
        if(ptr==-1 || node[ptr].next==-1)
        {
            cout<<"Invalid deletion after given ptr"<<endl;
        }
        else{
            delptr=node[ptr].next;
            delval=node[delptr].info;
            cout<<"Deleted Value is "<<delval<<endl;
            node[ptr].next=node[delptr].next;
            freenode(delptr);
        }
    }
};
int main()
{
    list l;
    l.intialize_availlist();
    int ch;
    int list1=-1;
    do
    {
    cout<<"1. Insert a new node: "<<endl;
    cout<<"2. Display Nodes: "<<endl;
    cout<<"3. Delete  Node"<<endl;
    cout<<"4. Insert After Node"<<endl;
    cout<<"5. Delete After Node"<<endl;
    cout<<"6. Exit"<<endl;
    cin>>ch;
    switch(ch)
    {
    case 1:
            l.insertnode(list1);
            break;
    case 2:
            l.displaynode();
            break;
    case 3:
            l.deletenode(list1);
            break;
    case 4:
            {
            int ptr,val;
            cout<<"Enter the node index after which the new node has to be inserted: ";
            cin>>ptr;
            cout<<"Enter the value to be inserted in the new node: ";
            cin>>val;
            l.insert_after(ptr,val);
            break;
            }
    case 5:
            {
            int ptr;
            cout<<"Enter the node index after which the node has to be deleted: ";
            cin>>ptr;
            l.delete_after(ptr);
            break;
            }
    case 6: break;
    default: cout<<"invalid input"<<endl;
    }
    }while (ch!=6);
}

