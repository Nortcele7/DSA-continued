#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class MinStack
{

    stack<pair<int,int>> st;

    public:
        void push(int val)
        {
            if(st.empty())
            {
                st.push({val, val});
            }
            else
            {
                int min_val = min(val, st.top().second);
                st.push({val, min_val});
            }
        }

        void pop()
        {
            st.pop();
        }

        int top()
        {
            return st.top().first;
        }

        int getMin()
        {
            return st.top().second;
        }

};


int main()
{

    MinStack min_s1;
   
    min_s1.push(30);
    min_s1.push(40);
    min_s1.push(29);
    min_s1.push(64);

    cout<<min_s1.getMin()<<endl;
    cout<<min_s1.top()<<endl;


}

