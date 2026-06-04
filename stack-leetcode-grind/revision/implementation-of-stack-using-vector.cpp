#include<iostream>
#include<vector>
using namespace std;

class Stack{

    vector<int> v1;

    public:
        void push(int val)
        {
            v1.push_back(val);
        }

        void pop()
        {
            v1.pop_back();
        }

        int top()
        {
            return v1[v1.size()-1];
        }

        bool isEmpty()
        {
            if(v1.size()==0)
            {
                return true;
            }
            else
            {
                return true;
            }
        }

};

int main()
{

    Stack s1;

    s1.push(390);
    s1.push(380);
    s1.push(370);

    cout<<s1.top();


}