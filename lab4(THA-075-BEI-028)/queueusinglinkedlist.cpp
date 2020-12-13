//WAP to implement QUEUE using linked list
#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};
struct node* head = NULL;
void enqueue()
{
    int val;
    cout<<"Enter the value to push: ";
    cin>>val;
    node *ptr = head;
    node *newnode = new node;
    newnode->data = val;
    cout<<newnode->data<<" is enqueue to linked list "<<endl;
    if(head == NULL)
    {
        head= newnode;
        newnode->next = NULL;
    }
    else
    {
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        newnode->next = ptr->next;
        ptr->next = newnode;
    }
}

void dequeue()
{
    if(head == NULL)
    {
        cout<<"Underflow!!"<<endl;
    }
    else
    {
        node *ptr = head;
        cout<<"The dequeued data is: "<<head->data<<endl;
        head = head->next;
        delete ptr;
    }
}

void display()
{
    if(head == NULL)
    {
        cout<<"\nThe list is empty!!"<<endl;
    }
    else
    {
        node *ptr = head;
        while(ptr != NULL)
        {
            cout<<" "<<ptr->data<<" ";
            ptr = ptr->next;
        }
        cout<<endl;
    }
}
int main()
{
    int ch;
        cout<<"1. Enqueue."<<endl;
        cout<<"2. Dequeue"<<endl;
        cout<<"3. Display"<<endl;
        cout<<"4. Exit"<<endl;
        do
        {
        cout<<"Enter your choice ";
        cin>>ch;
        switch (ch)
        {
        case 1:
        {
            enqueue();
            break;
        }

        case 2:
        {
            dequeue();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
            break;

        default :
        {
            cout<<"Invalid input";
            break;
        }
        }
    } while (ch != 4);

    return 0;
}

