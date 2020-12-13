//WAP to implement circular linked list
#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next;
};

class circularlinkedlist
{
    node *head;
public:
    circularlinkedlist()
    {
        head = NULL;
    }

    void create_circularlinkedlist()
    {
        int val;
        cout<<"enter -1 to end"<<endl;
        cout<<"Enter a value: ";
        cin>>val;
        do
        {
            node *newNode = new node;
            newNode->data = val;
            if(head == NULL)
            {
               head= newNode;
               newNode->next = head;
            }
            else
            {
               node *ptr = head;
               while(ptr->next != head)
               {
                   ptr = ptr->next;
               }
               ptr->next = newNode;
               newNode->next = head;
            }
            cout<<"Enter a value: ";
            cin>>val;
        }while(val != -1);
    }
    void insert_end_circularlinkedlist()
    {
        int val;
        cout<<"\nenter the number to insert at end: ";
        cin>>val;
        node *ptr = head;
        node *newNode = new node;
        newNode->data = val;
        newNode->next = head;
        if(head == NULL)
        {
            head= newNode;
        }
        else
        {
            while(ptr->next != head)
            {
                ptr = ptr->next;
            }
            ptr->next = newNode;
            newNode->next = head;
        }
    }

    void insert_beg_circularlinkedlist(int val)
    {

        node *newNode = new node;
        newNode->data = val;
        newNode->next = head;
        node *ptr = head;
        while(ptr->next != head)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
        head = newNode;
    }

    void insert_before_circularlinkedlist()
    {
        int n,val;
        cout<<"--------------------------------------------------\n";
        cout<<"-------------Inserting node before given node data--";
        cout<<"\n--------------------------------------------------\n";
        cout<<"enter the data to add the node before"<<endl;
        cin>>n;
        cout<<"enter the value "<<endl;
        cin>>val;
        node *newNode = new node;
        newNode->data = val;
        if(head->data == n)
        {
            insert_beg_circularlinkedlist(n);
        }
        else
        {
            node *ptr = head;
            node *preptr;

            while(ptr->data != n)
            {
                preptr = ptr;
                ptr = ptr->next;
            }

            preptr->next = newNode;
            newNode->next = ptr;
        }
    }
    void insert_after_circularlinkedlist()
    {
        int n,val;
        cout<<"--------------------------------------------------\n";
        cout<<"-------------Inserting node after given node data--";
        cout<<"\n--------------------------------------------------\n";
        cout<<"enter the data to add the node after"<<endl;
        cin>>n;
        cout<<"enter the value "<<endl;
        cin>>val;
        node *newNode = new node;
        newNode->data = val;

        node *ptr = head;
        while (ptr->data != n)
        {
            ptr = ptr->next;
        }
        if(ptr->next == head)
        {
          ptr->next = newNode;
          newNode->next = head;
        }
        else
        {
            newNode->next=ptr->next;
            ptr->next = newNode;
        }
    }

    void delete_beg_circularlinkedlist()
    {
        if(head->next == head)
        {
            head = NULL;
        }
        else
        {
            node *ptr = head;
            node *tmp = head;
            while(ptr->next != head)
            {
                ptr = ptr->next;
            }
            ptr->next = head->next;
            head = head->next;
            cout<<tmp->data<<" is deleted"<<endl;
            delete tmp;
        }
    }

    void delete_end_circularlinkedlist()
    {
        node *ptr =head;
        node *preptr = ptr;
        while(ptr->next != head)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = head;
        cout<<ptr->data<<" is deleted"<<endl;
        delete ptr;
    }

    void delete_node_circularlinkedlist()
    {
        cout<<"--------------------------------------------------\n";
        cout<<"--------------Deleting given node data----------";
        cout<<"\n--------------------------------------------------\n";
        int n;
        cout<<"enter the node data you want to delete"<<endl;
        cin>>n;
        node *ptr = head;
        if(ptr->data == n)
        {
            delete_beg_circularlinkedlist();
        }
        else
        {
            node*preptr = ptr;
            while(ptr->data != n)
            {
                preptr = ptr;
                ptr = ptr->next;
            }
            preptr->next = ptr->next;
            cout<<ptr->data<<" is deleted"<<endl;
            delete ptr;
        }
    }
    void delete_after_circularlinkedlist()
    {
        cout<<"--------------------------------------------------\n";
        cout<<"--------------Deleting after node data----------";
        cout<<"\n--------------------------------------------------\n";
        int n;
        cout<<"enter the node data"<<endl;
        cin>>n;
        node *ptr= head;
        while(ptr->data != n)
        {
            ptr = ptr->next;
        }
        if(ptr->next == head)
        {
            delete_beg_circularlinkedlist();
        }
        else
        {
            node *tmp = ptr->next;
            ptr->next = tmp->next;
            cout<<tmp->data<<" is deleted"<<endl;
            delete tmp;
        }
    }

    void delete_circularlinkedlist()
    {
        cout<<"--------------------------------------------------\n";
        cout<<"--------Deleting whole circular linked list---------\n";
        cout<<"\n--------------------------------------------------\n";
        while(head != NULL)
        {
            delete_beg_circularlinkedlist();
        }
    }
    void display_circularlinkedlist()
    {
        cout<<"--------------------------------------------------\n";
        cout<<"---------------Displaying All nodes---------------";
        cout<<"\n--------------------------------------------------\n";
        node *ptr = head;
        if(head == NULL)
        {
            cout<<"\nThe list is empty!!"<<endl;
        }
        else
        {
            while(ptr->next != head)
            {
                cout<<" "<<ptr->data<<" ";
                ptr = ptr->next;
            }
            cout<<" "<<ptr->data<<" ";
            cout<<endl;
        }
    }

};

int main()
{
    circularlinkedlist c;
    int ch;
    cout<<"\t\t\t-------Implementation of circular Linked list----------------        "<<endl;
        cout<<"1. create circular linked list "<<endl;
        cout<<"2. insert node at start"<<endl;
        cout<<"3. insert node at end"<<endl;
        cout<<"4. insert node at before"<<endl;
        cout<<"5. insert node at after"<<endl;
        cout<<"6. delete node at first"<<endl;
        cout<<"7. delete node at end"<<endl;
        cout<<"8. delete given node"<<endl;
        cout<<"9. delete after node"<<endl;
        cout<<"10. delete a linked list"<<endl;
        cout<<"11. exit"<<endl;
          do
        {
        cout<<"Choose the option: ";
        cin>>ch;
        switch (ch)
        {
        case 1:
        {
            c.create_circularlinkedlist();
            c.display_circularlinkedlist();
            break;
        }
        case 2:
        {
            int val;
            cout<<"--------------------------------------------------\n";
            cout<<"----------------Inserting At Start----------------";
            cout<<"\n--------------------------------------------------\n";
            cout<<"enter the number to insert at the beginning: ";
            cin>>val;
            c.insert_beg_circularlinkedlist(val);
            c.display_circularlinkedlist();
            break;
        }
        case 3:
        {
            c.insert_end_circularlinkedlist();
            c.display_circularlinkedlist();
            break;
        }
        case 4:
        {

            c.insert_before_circularlinkedlist();
            c.display_circularlinkedlist();
            break;
        }

        case 5:
        {
            c.insert_after_circularlinkedlist();
            c.display_circularlinkedlist();
            break;
        }

        case 6:
        {
            c.delete_beg_circularlinkedlist();
            c.display_circularlinkedlist();
            break;
        }

        case 7:
        {
            c.delete_end_circularlinkedlist();
            c.display_circularlinkedlist();
            break;
        }

        case 8:
        {
            c.delete_node_circularlinkedlist();
            c.display_circularlinkedlist();
            break;
        }

        case 9:
        {
            c.delete_after_circularlinkedlist();
            c.display_circularlinkedlist();
            break;
        }

        case 10:
        {
                c.delete_circularlinkedlist();
                c.display_circularlinkedlist();
                break;
        }

        case 11:
        {
            break;
        }

        default :
        {
            cout<<"Invalid input";
            break;
        }
        }
    }while (ch!=11);
    return 0;
}

