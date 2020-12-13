//WAP to implement priority queue using linked list
#include<iostream>
using namespace std;
class Queue{
    struct node
    {
        int data;
        int priority;
        struct node * next;
    };
   public:
    struct node * start;
    struct node * newnode,* temp,* ptr;
    void creation()
    {
            newnode = new node;
            cout<<"Enter the data for the queue(insert -1 to end the ): ";
            cin>>newnode->data;
            cout<<"Enter the priority of the data: ";
            cin>>newnode->priority;
            newnode->next=NULL;
            if (start==NULL)
            {
                start=newnode;
                temp=newnode;
            }
            else
            {
                temp->next=newnode;
                temp=newnode;
            }
        do{
                enqueue();
        }while (newnode->data!=-1);
    }
    void enqueue()
    {
        newnode=new node;
        cout<<"Enter the data to be stored in the queue: ";
        cin>>newnode->data;
        newnode->next=NULL;
        if (newnode->data!=-1)
        {
            cout<<"Enter the priority of the data: ";
            cin>>newnode->priority;
            ptr=start;
            if (newnode->priority<start->priority)
            {
                newnode->next=start;
                start=newnode;
            }
            else
            {
                while(ptr->next!=NULL && ptr->next->priority<newnode->priority )
                {
                    ptr=ptr->next;
                }
                newnode->next=ptr->next;
                ptr->next=newnode;
            }
        }
    }
    void dequeue()
    {
        ptr=start->next;
        delete start;
        start=ptr;
    }
    void display_queue()
    {
        ptr=start;
        cout<<endl;
        cout<<"-----------------------------------------------------------"<<endl;
        cout<<"The queue is: \t";
        cout<<ptr->data<<"|"<<ptr->priority;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
            cout<<"\t"<<ptr->data<<"|"<<ptr->priority;
        }
        cout<<endl;

        cout<<"-----------------------------------------------------------"<<endl;
     }
};
int main()
{
    class Queue q;
    q.start=NULL;
    int choice;
    while(choice!=4){
        cout<<"1-Creating a new queue "<<endl;
        cout<<"2-Enqueue "<<endl;
        cout<<"3-Dequeue "<<endl;
        cout<<"4-Exit "<<endl;
        cout<<"your choice: ";
        cin>>choice;
        switch (choice){
        case 1:
            q.creation();
            break;
        case 2:
            q.enqueue();
            break;
        case 3:
            q.dequeue();
            break;
        }
        q.display_queue();
    }
}
