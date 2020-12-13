//WAP to implement singly linked list
#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
class list
{
		private:
		node *Start,*End;
		public:
		list()
		{
			Start=NULL;
			End=NULL;
		}
		void createnode()
		{
            int value;
            cout<<"enter -1 to end"<<endl;
            cout<<"enter the data"<<"\t";
            cin>>value;
            do {
            node *newnode=new node;
			newnode->data=value;
			if(Start==NULL)
			{
			    Start=newnode;
			    End=newnode;
			}
			else
            {
                End->next = newnode;
                End=newnode;
            }
            cout<<"enter the data"<<"\t";
			cin>>value;
			}while(value!=-1);

		}
		void display()
		{
            cout<<"\n--------------------------------------------------\n";
            cout<<"---------------Displaying All nodes---------------";
            cout<<"\n--------------------------------------------------\n";
			struct node *temp;
			temp=Start;
			if(temp==NULL)
            {
                cout<<"Empty linear link list"<<endl;
            }
            else
            {
                while(temp!=NULL)
                {
                    cout<<temp->data<<"\t";
                    temp=temp->next;
                }
                cout<<endl;
            }
		}
		void insert_start()
		{
            cout<<"\n--------------------------------------------------\n";
            cout<<"----------------Inserting At Start----------------";
            cout<<"\n--------------------------------------------------\n";
            int value;
            cout<<"enter the data to add at start"<<endl;
            cin>>value;
			node *newnode=new node;
			newnode->data=value;
			newnode->next=Start;
			Start=newnode;
		}
		void insert_end()
		{
            cout<<"\n--------------------------------------------------\n";
            cout<<"----------------Inserting At End--------------------";
            cout<<"\n--------------------------------------------------\n";
            int value;
            cout<<"enter the data "<<endl;
            cin>>value;
            struct node *pre,*cur;
			node *newnode=new node;
			cur=Start;
			while(cur!=NULL)
			{
				pre=cur;
				cur=cur->next;
			}
			newnode->data=value;
			pre->next=newnode;
			newnode->next=cur;

		}
		void insert_val_before()
		{
			cout<<"\n--------------------------------------------------\n";
            cout<<"-------------Inserting node before given node data--";
            cout<<"\n--------------------------------------------------\n";
            int val,value;
            cout<<"enter the data to add the node before"<<endl;
            cin>>val;
            cout<<"enter the value "<<endl;
            cin>>value;
			struct node *pre,*cur;
			node *newnode=new node;
			cur=Start;
			while(cur->data!=val)
			{
				pre=cur;
				cur=cur->next;
			}
			newnode->data=value;
			pre->next=newnode;
			newnode->next=cur;
		}
		void insert_val_after()
		{
            cout<<"\n--------------------------------------------------\n";
            cout<<"-------------Inserting node after given node data---";
            cout<<"\n--------------------------------------------------\n";
            int num,value;
            cout<<"enter the data to add the node after"<<endl;
            cin>>num;
            cout<<"enter the data "<<endl;
            cin>>value;
			struct node *pre,*cur;
			node *newnode=new node;
			cur=Start;
			while(pre->data!=num)
			{
				pre=cur;
				cur=cur->next;
			}
			newnode->data=value;
			pre->next=newnode;
			newnode->next=cur;
		}
		void delete_first()
		{
            cout<<"\n--------------------------------------------------\n";
            cout<<"----------------Deleting At Start-----------------";
            cout<<"\n--------------------------------------------------\n";
			struct node *temp;
			temp=Start;
			if(temp==NULL)
            {
                cout<<"empty list "<<endl;
            }
            else {
			Start=Start->next;
			delete temp; }
		}
		void delete_last()
		{
            cout<<"\n--------------------------------------------------\n";
            cout<<"-----------------Deleting At End-------------------";
            cout<<"\n--------------------------------------------------\n";
			struct node *previous,*current;
			current=Start;
			if (current == NULL )
            {
                cout<<"empty list "<<endl;
            }
            else {
                while(current->next!=NULL)
                {
                    previous=current;
                    current=current->next;
                }
                previous->next=NULL;
                delete current;
            }
		}
		void delete_num_node()
		{
            cout<<"\n--------------------------------------------------\n";
            cout<<"--------------Deleting given node data----------";
            cout<<"\n--------------------------------------------------\n";
            int num;
            cout<<"enter the node data you want to delete"<<endl;
            cin>>num;
			struct node *previous,*current;
			current=Start;
			if(current==NULL)
            {
                cout<<"Empty list  "<<endl;
            }
            else
            {
                while(current->data!=num)
			{
				previous=current;
				current=current->next;
			}
			previous->next=current->next;
			delete current;

            }
        }
};
int main()
{
    list obj;
    int a;
    cout<<"\t\t\t-------Implementation of singly Linked list----------------        "<<endl;
    cout<<"1. create linked list "<<endl;
    cout<<"2. insert node at start"<<endl;
    cout<<"3. insert node at end"<<endl;
    cout<<"4. insert node at before"<<endl;
    cout<<"5. insert node at after"<<endl;
    cout<<"6. delete node at first"<<endl;
    cout<<"7. delete node at last"<<endl;
    cout<<"8. delete given node"<<endl;
	cout<<"9. exit"<<endl;
	do{
	cout<<"choose the option\t";
	cin>>a;
	switch(a)
	{
	case 1:
            obj.createnode();
            obj.display();
            break;
    case 2:
            obj.insert_start();
            obj.display();
            break;
    case 3:
            obj.insert_end();
            obj.display();
            break;
    case 4:
            obj.insert_val_before();
            obj.display();
            break;
    case 5:
            obj.insert_val_after();
            obj.display();
            break;
    case 6:
            obj.delete_first();
            obj.display();
            break;
    case 7:
            obj.delete_last();
            obj.display();
            break;
    case 8:
            obj.delete_num_node();
            obj.display();
            break;
    case 9: break;
    default:cout<<"invalid input"<<endl;
    }

    }
    while(a!=9);

}
