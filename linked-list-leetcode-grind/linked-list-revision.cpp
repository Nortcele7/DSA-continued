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

        // Inserting element in Linked List from the front

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
            cout<<endl;
        }

        void insertLL(int value, int pos)
        {
            Node* temp = head;

            if(pos<0)
            {
                cout<<"Position shouldn't be negative";
            }

            if(pos==0)
            {
                push_front(value);
                return;
            }

            Node* newNode = new Node(value);

            for(int i=0; i<pos-1; i++)
            {
                temp = temp->next;
            }

            newNode->next = temp->next;
            temp->next = newNode;

        }

        void reverse()
        {
            Node* curr = head;
            Node* prev = NULL;
            Node* next;

            while(curr!=NULL)
            {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            head = prev;
        }

        void middleOfLL()
        {
            Node* slow = head;
            Node* fast = head;

            while(fast!=NULL && fast->next!=NULL)
            {
                slow = slow->next;
                fast = fast->next->next;
            }


            cout<<slow->data<<endl;
        }

        bool detectCycle()
        {
            Node* slow = head;
            Node* fast = head;

            while(fast!=NULL && fast->next!=NULL)
            {
                slow = slow->next;
                fast = fast->next->next;

                if(slow==fast)
                {
                    return true;
                }

            }
            return false;
        }

        void cycleStart()
        {
            Node* slow = head;
            Node* fast = head;
            int x = 0;

            while(fast->next!=NULL && fast->next->next!=NULL)
            {
                slow = slow->next;
                fast = fast->next->next;

                if(slow==fast)
                {
                    x = 1;
                    break;
                }
                

            }

            if(x==0)
            {
                cout<<"No cycle detected";
                return;
            }

            slow = head;

            while(slow!=fast)
            {
                slow = slow->next;
                fast = fast->next;
            }

            cout<<"Starting Node is: "<<slow->data<<endl;

        }



};

int main()
{

    List l1;

    l1.push_front(20);
    l1.push_front(30);
    l1.push_front(40);
    l1.push_front(50);
    l1.insertLL(100, 1);
    l1.insertLL(200, 4);

    l1.printLL();

    l1.middleOfLL();

    l1.tail->next = l1.head->next->next;

    cout<<l1.detectCycle()<<endl;

    l1.cycleStart();





}