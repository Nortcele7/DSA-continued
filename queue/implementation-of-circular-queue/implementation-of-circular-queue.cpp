#include<iostream>
using namespace std;

class CircularQueue
{

    int* arr;
    int front;
    int rear;
    int size;

    public:

        CircularQueue(int n)
        {
            size = n;
            arr = new int[size];
            front = rear = -1;
        }

        void enqueue(int val)
        {
            if((rear+1)%size==front)
            {
                cout<<"Queue Overflow"<<endl;
                return;
            }

            if(front==-1 && rear==-1)
            {
                front = 0;
                rear = 0;
            }

            else
            {
                rear = (rear+1)%size;
            }
            

            arr[rear] = val;
            cout<<"Enqueued: "<<val<<endl;


        }

        void dequeue()
        {
            if(front==-1)
            {
                cout<<"Queue Undeflow";
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

            cout<<"Dequeued: "<<item<<endl;

            
        }

};

int main()
{
    CircularQueue q1(4);

    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    q1.dequeue();
    q1.enqueue(7);


}