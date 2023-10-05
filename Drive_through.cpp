#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Stack
{
    public:
    int top=-1;
    //string a[100];
    vector<string> po; 
    void Push(string x);
    void Pop();
    void Top();
    void Display();
};
void Stack::Push(string x)
{
    top+=1;
    po.push_back(x);
}
void Stack::Pop()
{
    if (top==-1)
    {
        cout<<"Underflow: No orders remaining"<<endl;
    }
    else
    {
        //cout<<po[top]<<endl;
        po.pop_back();
        top-=1;
    }
}
void Stack::Top()
{
    cout<<po[top]<<endl;
}
void Stack::Display()
{
    for(int i=top;i>-1;i--)
    {cout<<po[i]<<"|";}
    cout<<endl;
}

class Queue
{
    public:
        int f=-1;
        int r=-1;
        int n=10;
        vector<string> orders;
        vector<string>::iterator fi,ri;
        void Enqueue(string x);
        string Dequeue();
        void Front();
        void display();
};
void Queue::Enqueue(string x)
{
    if(f==-1 && r==-1)
    {
        f=0;
        r=0;
    }
    else if((f==(r+1)%n))
    {
        cout<<"Overflow: Too many orders in Queue."<<endl;
        return;
    }
    else
    {
        r=((r+1)%n);
    }
    orders.insert(orders.begin()+r,x);
}
string Queue::Dequeue()
{
    string y;
    if(f==-1 && r==-1)
    {
        //cout<<"No orders remaining"<<endl;
        return "0";
    }
    else if(f==r)
    {
        y=orders[f];
        f=-1;
        r=-1;
        return y;
    }
    else
    {
        y=orders[f];
        f=(f+1)%n;
        return y;
    }
}
void Queue::display()
{
    int i;
    if(f==-1 && r==-1)
    {
        cout<<"No orders under process"<<endl;
        return;
    }
    else
    {
        for(i=f;i<=r;i=(i+1)%n)
        {
            cout<<orders[i]<<"|";
        }
        cout<<endl;
        return;
    }
}
void Queue::Front()
{
    cout<<orders[f]<<endl;
}
//Driver Code
int main()
{
    cout<<"DRIVE THROUGH FAST FOOD"<<endl;;
    Stack p_orders;
    Queue c_orders;
    int c;
    string x,y;
    bool flag=true;
    //printf("1. Enter New Order\n2. View Orders Under Process\n3. Mark Order Completed\n4. View Order History\n5. View Last Order\n6. Exit");
    cout<<"1. Enter New Order\n2. View Orders Under Process\n3. Mark Order Completed\n4. View Order History\n5. View Last Order\n6. Exit"<<endl;
    while(flag==true)
    {
        //printf("\nEnter choice: ");
        //scanf("%d",&c);
        cout<<"Enter choice: ";
        cin>>c;
        switch(c)
    {
        case 1:
            cout<<"Input order: ";
            cin.ignore();
            getline(cin,x);
            c_orders.Enqueue(x);
            cout<<"Order Placed"<<endl;;
            //c_orders.display();
            break;
        
        case 2:
            //c_orders.Dequeue();
            c_orders.display();
            break;

        case 3:
            y=c_orders.Dequeue();
            p_orders.Push(y);
            cout<<y<<" :Marked as Complete"<<endl;
            break;
        
        case 4:
            p_orders.Display();
            break;

        case 5:
            p_orders.Top();
            break;

        default:
            flag=false;
    }
    }
}
