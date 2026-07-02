#include<iostream>
using namespace std;

class queue{

    int* arr;
    int front;
    int rear;
    int size;

    public:
        queue(int n)
        {
            size = n;
            arr = new int[size];
            front = rear = -1;
        }

        void enqueue(int val)
        {
            if(rear==size-1)
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
                rear = rear + 1;
            }

            arr[rear] = val;

            cout<<"Enqueued: "<<val<<endl;



        }

        void dequeue()
        {
            if(front==-1 || front>rear)
            {
                cout<<"Queue Underflow"<<endl;
                return;
            }
            int item = arr[front];

            if(front==rear)
            {
                front=-1;
                rear=-1;
            }


            else
            {

                front = front+1;

            }

            cout<<"Dequeued: "<<item<<endl;
        }



};

int main()
{
    queue q1(3);
    
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    q1.dequeue();
    q1.enqueue(5);
}