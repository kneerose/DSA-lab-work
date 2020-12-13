//WAP to implement STACK using linked list
#include <iostream>
using namespace std;

struct Node
{
   int data;
   struct Node *next;
};

struct Node* head = NULL;

void push()
{
     int val;
        cout<<"enter the value to push: ";
        cin>>val;
        Node *newnode = new Node;
        newnode->data = val;
        cout<<newnode->data<<" is pushed to linked list "<<endl;
        if(head == NULL)
        {
            head = newnode;
            head->next = NULL;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
}

void pop()
{

    if(head==NULL)
    cout<<"Stack Underflow"<<endl;
    else
    {
        Node *tmp = head;
        cout<<"The popped element is "<< head->data <<endl;
        head = head->next;
        delete tmp;
    }
}

void display()
{
   struct Node* t;
   if(head==NULL)
   cout<<"Stack is not created yet."<<endl;
   else
    {
        t = head;
        cout<<"Stack elements are: ";
        while (t!=NULL)
        {
            cout<< t->data <<"\t";
            t = t->next;
        }
    }
   cout<<endl;
}
int main() {
   int ch, val;
      cout<<"1) Push"<<endl;
      cout<<"2) Pop"<<endl;
      cout<<"3) Display"<<endl;
      cout<<"4) Exit"<<endl;
      do {
      cout<<"Enter your choice: \t";
      cin>>ch;
      switch(ch)
       {
         case 1:
            {
                push();
                break;
            }

         case 2:
            {
                pop();
                break;
            }
         case 3:
            {
                display();
                break;
            }
         case 4:
            {
                break;
            }
         default:
            {
                cout<<"Invalid input"<<endl;
            }
      }
   }while(ch!=4);

}
