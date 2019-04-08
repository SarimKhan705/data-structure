#include <iostream>
#include <conio.h>
#include <string>
#include <string.h>

using namespace std;
class LinkedList
{
  private:
  
    struct node
    {
        int data;
        node *next;
    };
    node *start,*end;
    
    void createNode(int value)
    {
        node *temp=new node;
        temp->data=value;
        temp->next=NULL;
        if(start==NULL)
        {
            start=temp;
            end=temp;
            temp=NULL;	/*Check this not necessary*/
        }
        else
        {
            end->next=temp;
            end=temp;
        }
        
    }
  public:
    LinkedList()
    {
        start=NULL; end=NULL;
    }
    
    
    void DisplayData()
    {
        int a=1;
        node *temp=new node;
        temp=start;
        
        while(temp!=NULL)
        {
            cout<<"Node "<<a<<":  "<<temp->data<<endl;
            temp=temp->next;
            //Until this is null it runs
            a++;
        }
        
    }
    
    void insert_node(int value)
    {
        //It is same as creating a new node
        createNode(value);
    }
    void insert_pos(int value,int pos)
    {
        node *temp=new node;
        temp->data=value;
        //insert at start
        if(pos==1)
        {
            temp->next=start;
            start=temp;
            return;
            
        }
        //else at a specific position
        node *pre=new node;
        node *current=new node;
        
        current=start;
        for(int i=1; i<pos; i++)
        {
            pre=current;
            current=current->next;
            
        }
        pre->next=temp;
        temp->next=current;
        if(pos==1)
            cout<<"1 Data is Inserted at "<<pos<<"st position"<<endl;
        else if(pos==2)
            cout<<"1 Data is Inserted at "<<pos<<"nd position"<<endl;
        else if(pos==3)
            cout<<"1 Data is Inserted at "<<pos<<"rd position"<<endl;
        else
            cout<<"1 Data is Inserted at "<<pos<<"th position"<<endl;
    }
    
    void del_start()
    {
        /*to de-allocate memory*/
        node *temp=new node;
        temp=start;
        start=start->next;
        delete temp;
        cout<<"2 Start Node is Deleted"<<endl;
    }
    void del_end()
    {
        node *curr=new node;
        node *pre=new node;
        curr=start;
        while(curr!=end)
        {
            pre=curr;
            curr=curr->next;
            
        }
        delete curr;
        end=pre;
        pre->next=NULL;
        cout<<"2 End Node is Deleted"<<endl;
    }
    void del_pos(int pos)
    {
        node *curr=new node;
        node *pre=new node;
        curr=start;
        for(int i=1; i<pos; i++)
        {
            pre=curr;
            curr=curr->next;
        }
        pre->next=curr->next;
        delete curr;
        if(pos==1)
            cout<<"2 "<<pos<<"st Node is Deleted" <<endl;
        else if(pos==2)
            cout<<"2 "<<pos<<"nd Node is Deleted" <<endl;
        else if(pos==3)
            cout<<"2 "<<pos<<"rd Node is Deleted" <<endl;
        else
            cout<<"2 "<<pos<<"th Node is Deleted" <<endl;
    }
    void updateNode(int data,int pos)
    {
        node *curr=new node;
        curr=start;
        for(int i=1; i<pos; i++)
        {
            curr=curr->next;
        }
        curr->data=data;
        if(pos==1)
            cout<<"2 "<<pos<<"st Node is Updated" <<endl;
        else if(pos==2)
            cout<<"2 "<<pos<<"nd Node is Updated" <<endl;
        else if(pos==3)
            cout<<"2 "<<pos<<"rd Node is Updated" <<endl;
        else
            cout<<"2 "<<pos<<"th Node is Updated" <<endl;
    }
    
    
};


int main()
{

    LinkedList l;
    
    l.insert_node(23); l.insert_node(45); l.insert_node(16);
    
    l.DisplayData();
    
    l.insert_pos(98,3);
    
    l.DisplayData();
    
    l.del_start();
    
    l.DisplayData();
    
    
    l.del_pos(3);
    
    l.DisplayData();
    
    l.updateNode(123,2);
    
    l.DisplayData();
    
    return 0;
}
