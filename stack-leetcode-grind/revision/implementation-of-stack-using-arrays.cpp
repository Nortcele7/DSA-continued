#include<iostream>
#include<vector>
using namespace std;

class Stack
{

    int top_c = -1;
    int size = 0;
    int *arr;

    public:
        Stack(int capacity)
        {
            size = capacity;
            arr = new int [size];
        }

        void push(int value)
        {
            if(top_c==size-1)
            {
                cout<<"Stack Overflow";
                return;
            }
            
            else
            {
                top_c++;
                arr[top_c] = value;
            }

        }

        void pop()
        {
            if(top_c==-1)
            {
                cout<<"Stack Underflow";
                return;
            }

            else
            {
                top_c--;
            }
        }

        int top()
        {
            return arr[top_c];
        }

        bool isEmpty()
        {
            if(top_c==-1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

};

int main()
{

    Stack s1(5);

    s1.push(390);
    s1.push(380);
    s1.push(370);

    cout<<s1.top();
    
}