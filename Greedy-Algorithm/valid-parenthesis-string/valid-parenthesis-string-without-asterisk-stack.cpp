#include<iostream>
#include<stack>
using namespace std;

bool checkValidString(string s) {
    
        int n = s.length();

        stack<int> st;

        for(int i=0; i<n; i++)
        {
            if(s[i]=='(')
            {
                st.push(s[i]);
            }
            else if(s[i]==')')
            {
                if(st.empty())
                {
                    return false;
                }
                st.pop();
            }
        }

        return st.empty();

    }

int main()
{
 
    string s =")))";

    cout<<checkValidString(s);
    
}