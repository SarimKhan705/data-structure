#include <iostream>
#include<conio.h>
#include"windows.h"
using namespace std;
class stack
{
  private:
  
    int *elements;
    int size,capacity;
  public:
    stack()
    {
        this->size=-1;
        this->capacity=5;	//5 is default capacity
        elements=new int[capacity];
    }
    stack(int capacity)
    {
        this->size=-1;
        this->capacity=capacity;	//user defined capacity
        elements=new int[capacity];
    }
    bool isEmpty()
    {
        return size==-1; //true if condition pass
    }
    void push(int value)
    {
        if(size==capacity-1)//check the size of the stack 
            cout<<"The Stack is Full\n"<<endl;
        else
            elements[++size]=value;
    }
    void pop()
    {
        if(size==-1)
            cout<<"The Stack is Empty\n"<<endl;
        else
            cout<<elements[size--]<<endl;
        cout<<"\n";
    }
    void displayNum()//display the numbers in stack
    {
        if(size==-1)
        {
            cout<<"The Stack is Empty\n"<<endl;
            return;
        }
        
        cout<<"Elements in the List:\n";
        for(int i=size; i>=0; i--)
        {
            cout<<elements[i]<<" ";
        }
        cout<<"\n";
        
    }
    int getSize()
    {
        cout<<"The Size is:\n";
        return size;
    }
    
};
class queue
{
  private:
    int *arr,size,capacity;
    
    
  public:
    queue()
    {
        this->size=-1;
        this->capacity=5;		//default capacity
        arr=new int[capacity];	//Dynamic array
        
    }
    queue(int capacity)
    {
        this->size=-1;
        this->capacity=capacity;
        arr=new int[capacity];
        
    }
    bool isEmpty()
    {
        return size==-1; //true if condition pass
    }
    void push(int value)
    {
        if(size<capacity-1)//check the size of the queue
            arr[++size]=value;
        else
            cout<<"The Queue is Full \n";
    }
    void pop()
    {
        if(size==-1)
        {
            cout<<"The Queue is Empty \n";
            return ;
        }
        
        cout<<arr[0]<<endl;
        cout<<"\n";
        for(int i=0; i<size; i++)
        {
            arr[i]=arr[i+1];
        }
        --size;
        cout<<"\n";
    }
    void display()
    {
        if(size==-1)
        {
            cout<<"The Queue is Empty \n";
            return ;
        }
        cout<<"Elements in the Lists: \n";
        for(int i=0; i<=size; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
};


int main()
{


    int choice;
    cout<<"Make Your Choice Between:  \n1.Stack\n2.Queue\n"<<endl;
    cin>>choice;
    if(choice==1)
    {
        int stsize;
        cout<<"\nEnter Size of Stack: ";
        cin>>stsize;
        cout<<"\n";
        system("cls");
        stack st(stsize); char status='n';
        do
        {
            int stchoice;
            cout<<"Choose Option:\n1.Push\n2.Pop\n3.Check whether stack empty\n4.Display stack\n"<<endl;//choices for user
            cin>>stchoice;
            switch(stchoice)
            {
                case 1:
                    {
                        int elements;
                        cout<<"Enter Number of Elements to Push in a Stack: ";
                        cin>>elements;
                        cout<<"\n";
                        for(int i=0; i<elements; i++)
                        {
                            int x;
                            cout<<"Enter "<<i+1<<" element:";
                            cin>>x;
                            cout<<"\n";
                            st.push(x);
                        }
                        cout<<"Do You Wanna Make Another Choic?\nPress Y or y\n"<<endl;
                        cin>>status;
                        system("cls");
                    }
                    break;
                case 2:
                    {
                        st.pop();
                        cout<<"Do You Wanna Make Another Choic?\nPress Y or y\n"<<endl;
                        cin>>status;
                        system("cls");
                    }
                    break;
                case 3:
                    {
                        if(st.isEmpty()==true)
                        {
                            cout<<"Your Stack is Empty\n"<<endl;
                        }
                        else
                        {
                            cout<<"Your Stack is Not empty\n"<<endl;
                        }
                        cout<<"Do You Wanna Make Another Choic?\nPress Y or y\n"<<endl;
                        cin>>status;
                        system("cls");
                    }
                    break;
                case 4:
                    {
                        st.displayNum();
                        cout<<"Do You Wanna Make Another Choic?\nPress Y or y\n"<<endl;
                        cin>>status;
                        system("cls");
                    }
                    break;
                default:
                    cout<<"You Have Entered a Wrong Choice"<<endl;
                    cout<<"Do You Wanna Make Another Choic?\nPress Y or y\n"<<endl;
                    cin>>status;
                    system("cls");
                    break;
            }
            
        }
        while(status=='y' || status=='Y');
        
    } //if
    else
    {
        int qsize;
        cout<<"Enter Size of Queue:";
        cin>>qsize;
        cout<<"\n";
        system("cls");
        queue q(qsize);
        char status='n';
        do
        {
            int qchoice;
            cout<<"Choose Option:\n1.Push\n2.Pop\n3.Check whether queue empty\n4.Display queue\n";
            cin>>qchoice;
            switch(qchoice)
            {
                case 1:
                    {
                        int elements;
                        cout<<"Enter Number of Elements to Push in a Queue:";
                        cin>>elements;
                        cout<<"\n";
                        for(int i=0; i<elements; i++)
                        {
                            int x;
                            cout<<"Enter "<<i+1<<" element:";
                            cin>>x;
                            cout<<"\n";
                            q.push(x);
                        }
                        cout<<"Do You Wanna Make Another Choic?\nPress Y or y\n"<<endl;
                        cin>>status;
                        system("cls");
                    }
                    break;
                case 2:
                    {
                        q.pop();
                        cout<<"Do You Wanna Make Another Choic?\nPress Y or y\n"<<endl;
                        cin>>status;
                        system("cls");
                    }
                    break;
                case 3:
                    {
                        if(q.isEmpty()==true)
                        {
                            cout<<"Your Queue is Empty \n"<<endl;
                        }
                        else
                        {
                            cout<<"Your Queue is Not empty \n"<<endl;
                        }
                        cout<<"Do You Wanna Make Another Choic?\nPress Y or y\n"<<endl;
                        cin>>status;
                        system("cls");
                    }
                    break;
                case 4:
                    {
                        q.display();
                        cout<<"Do You Wanna Make Another Choic?\nPress Y or y\n"<<endl;
                        cin>>status;
                        system("cls");
                    }
                    break;
                default:
                    cout<<"You HAve Entered a Wrong Choice"<<endl;
                    cout<<"Do You Wanna Make Another Choic?\nPress Y or y\n"<<endl;
                    cin>>status;
                    system("cls");
                    break;
            }
            
        }
        while(status=='y' || status=='Y');
        
    }//else
}
