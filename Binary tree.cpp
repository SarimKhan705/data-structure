#include <iostream>
#include <conio.h>

#include <string>
#include <string.h>

using namespace std;



struct node
{
    int data;
    node *left;
    node *right;
};


//Create a node and return it's address i.e a pointer of node type
node *CreateNode(int value)
{
    node *temp_node=new node;
    temp_node->data=value;
    temp_node->left=temp_node->right=NULL;
    return temp_node;
}

//first we send the address of root node,then at recursion the address willl be of our choice
node *InsertNode(node *root,int value)
{

    if(root==NULL)
    {
        root=CreateNode(value);
        
    }
    else if(value<root->data)
    {
        root->left = InsertNode(root->left,value); //first it will go on left then second left and so on
    }
    else 	//node *root;
    {
        root->right = InsertNode(root->right,value); //first right then left node
    }
    
    return root; 
}
bool Search(node* root,int data)//it wil search the node
{

    if(root == NULL)
    {
        return false;
    }
    else if(root->data == data)
    {
        return true;
    }
    else if(data < root->data)
    {
        return Search(root->left,data);
    }
    else
    {
        return Search(root->right,data);
    }
}

void inorder_display(node *root)//it will display the tree in inorder way
{
    if(root==NULL) return;
    inorder_display(root->left);
    cout<<"\n"<< root->data<<"\n";
    inorder_display(root->right);
}



int main()
{

    node *root=NULL;
    
    int noofnodes;
    cout<<"How many nodes do you want to insert?"<<endl;
    cin>>noofnodes;
    
    for(int i=0; i<noofnodes; i++)
    {
        cout<<"Enter "<<i+1<<" node value:";
        int nodevalue;
        cin>>nodevalue;
        root=InsertNode(root,nodevalue);
    }
    inorder_display(root);
    /*	root=InsertNode(root,12);
    	root=InsertNode(root,5);
    	root=InsertNode(root,15);
    	root=InsertNode(root,3);
    	root=InsertNode(root,7);
    	root=InsertNode(root,13);
    	root=InsertNode(root,17);
    */
    /*	root=Delete(root,5); */
    int n;
    cout<<"\n Enter the node you want to search:\n";
    cin>>n;
    cout<<"\n";
    if(Search(root,n)==true)
    {
        cout<<"\n your node is present\n";
    }
    else
    {
        cout<<"\n your Node is not found\n";
    }
    
    
    return 0;
}
