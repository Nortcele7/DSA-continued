#include<iostream>
using namespace std;

class deque{

    int* arr;
    int front;
    int rear;
    int size;

    public:

        deque(int n)
        {
            size = n;
            arr = new int[size];
            front = -1;
            rear = -1; 
        }
        
        bool isEmpty()
        {
            return front==-1;
        }

        bool isFull()
        {
            return ((rear+1)%size == front);
        }

        void insertAtFront(int val)
        {
            if(isFull())
            {
                cout<<"Deque Overflow"<<endl;
                return;
            }

            if(isEmpty())
            {
                front = 0;
                rear = 0;
            }

            else
            {
                front = (front-1+size)%size;
            }

            arr[front] = val;

            cout<<"Inserted at front: "<<val<<endl;

        }

        void insertAtRear(int val)
        {
            if(isFull())
            {
                cout<<"Deque Overflow"<<endl;
                return;
            }

            if(isEmpty())
            {
                front = 0;
                rear = 0;
            }

            else
            {
                rear = (rear+1)%size;
            }

            arr[rear] = val;

            cout<<"Inserted at rear: "<<val<<endl;

        }

        void deleteFromFront()
        {
            if(isEmpty())
            {
                cout<<"Deque Underflow"<<endl;
                return;
            }

            int item = arr[front];

            if(front==rear)
            {
                front = -1;
                rear = -1;  
            }

            else
            {
                front = (front+1)%size;
            }

            cout<<"Deleted from front: "<<item<<endl;

        }

        void deleteFromRear()
        {
            if(isEmpty())
            {
                cout<<"Deque Underflow"<<endl;
                return;
            }

            int item = arr[rear];

            if(front==rear)
            {
                front = -1;
                rear = -1;
            }

            else
            {
                rear = (rear-1+size)%size;
            }

            cout<<"Delete from rear: "<<item<<endl;


        }



};

int main()
{

    deque dq1(4);

    dq1.insertAtFront(4);
    dq1.insertAtFront(3);
    dq1.insertAtRear(1);
    dq1.insertAtRear(2);

    dq1.insertAtRear(5);

    dq1.deleteFromRear();

    dq1.insertAtRear(6);

}