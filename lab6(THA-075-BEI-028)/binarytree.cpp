/*Write a menu driven Program for the following operations on Binary Search Tree (BST) of Integers
   i.   Create a BST of N Integers: 5, 10, 25, 2, 8, 15, 24, 14, 7, 8, 35, 2
   ii.  Traverse the BST in Inorder, Preorder and Post Order
   iii. Search the BST for a given element (KEY) and print the appropriate message
   iv.  Exit*/
#include <iostream>
using namespace std;
struct node{
    struct node *left;
    int data;
    struct node *right;
};
struct node *newNode(int val)
{
    struct node *temp =  new struct node();
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}
struct node* insert(struct node* node, int val)
{
    if (node == NULL) return newNode(val);
    if (val < node->data)
       node->left  = insert(node->left, val);
    else
        node->right = insert(node->right, val);
    return node;
}
void inorder(struct node* node)
{
    if(node!=NULL)//LNR
    {
       inorder(node->left);
       cout<<node->data<<" ";
       inorder(node->right);
    }
}
void preorder(struct node* node)
{
    if(node!=NULL)//NLR
    {
       cout<<node->data<<" ";
       preorder(node->left);
       preorder(node->right);
    }
}
void postorder(struct node* node)
{
    if(node!=NULL)//LRN
    {
       postorder(node->left);
       postorder(node->right);
       cout<<node->data<<" ";
    }
}
void search(struct node* node ,int val)
{
    if(node!=NULL)
       {
        if(node->data==val)
            cout<<endl<<"key found successfully"<<endl<<endl;
        else
            if(val<node->data)
                search(node->left,val);
            else
                search(node->right,val);
       }
    else
        cout<<endl<<"key not found"<<endl<<endl<<endl;
}
int main()
{
 int n,val,ch;
 struct node* new_node=NULL;
 cout<<"Binary search tree"<<endl;
 cout<<"1. Insert an element in tree"<<endl;
 cout<<"2. Pre-order, In-order and Post-order of BST"<<endl;
 cout<<"3. Searching element "<<endl;
 cout<<"4. Exit"<<endl;
 do{
 cout<<"choose the option :\t";
 cin>>ch;
 switch(ch){
    case 1:  cout<<"enter the number of nodes for creating binary search tree:\t";
             cin>> n;
             cout<<"enter "<<n<<"  nodes"<<endl;
             for(int i=0;i<n;i++)
             {
                 cin>>val;
                 new_node=insert(new_node,val);
             }
             break;
    case 2: cout<<endl<<endl;
            cout<<"pre-order of given BST are "<<endl;
            preorder(new_node);
            cout<<endl<<endl;
            cout<<"In-order of given BST are "<<endl;
            inorder(new_node);
            cout<<endl<<endl;
            cout<<"Post-order of given BST are "<<endl;
            postorder(new_node);
            cout<<endl<<endl;
            break;
    case 3: cout<<"enter the key you want to search in BST:\t";
            cin>>val;
            search(new_node,val);
            break;
    case 4: break;
    default: cout<<"invalid input"<<endl;
           }
 }while(ch!=4);
 return 0;
}
