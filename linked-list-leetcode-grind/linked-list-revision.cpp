#include<iostream>
using namespace std;

class Node
{

    public:
        int data;
        Node* next;

        Node(int val)
        {
            data = val;
            next = NULL;
        }


};

class List
{

    public:
        Node* head;
        Node* tail;

        List()
        {
            head = tail = NULL;
        }

        void push_front(int val)
        {

            Node* newNode = new Node(val);

            if(head==NULL)
            {
                head=tail=newNode;
            }

            else
            {
                newNode->next = head;
                head = newNode;
            }

        }

        void push_back(int val)
        {

            Node* newNode = new Node(val);

            if(tail==NULL)
            {
                head = tail = newNode;
            }

            else
            {
                tail->next = newNode;
                tail = newNode;
            }

        }

        void pop_front()
        {

            if(head==NULL)
            {
                return;
            }

            else
            {
                Node* temp = head;

                head = temp->next;

                temp->next = NULL;

                delete temp;

                // If we delete the last available node then the tail should also point to NULL
                if(head==NULL)
                {
                    tail=NULL;
                }
            }

        }

        void pop_back()
        {
            Node* temp = head;

            // When it has no nodes
            if(head==NULL)
            {
                return;
            }

            // When it has only one node
            if(head==tail)
            {
                delete head;
                head=tail=NULL;
                return;
            }


            while(temp->next!=tail)
            {
                temp=temp->next;
            }

            temp->next = NULL;
            delete tail;
            tail = temp;
        }

        void printLL()
        {
            Node* temp = head;

            while(temp!=NULL)
            {
                cout<<temp->data<<"->";
                temp = temp->next;
            }
        }



};

int main()
{

    List l1;

    l1.push_front(20);
    l1.push_front(30);
    l1.push_front(40);
    l1.push_front(50);
    l1.push_back(100);
    l1.pop_front();
    l1.pop_back();

    l1.printLL();






}