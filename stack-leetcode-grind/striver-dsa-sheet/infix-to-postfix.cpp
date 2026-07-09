#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int precedence(char i)
{
    if(i=='+' || i=='-')
    {
        return 1;
    }
    else if(i=='*' || i=='/' || i=='%')
    {
        return 2;
    }
    else if(i=='^')
    {
        return 3;
    }
    else
    {
        return 0;
    }
}

void infixToPostfix(string& s, string& postfix)
{

    stack<char> st;

    int i = 0;

    while(i<s.size())
    {

        if(s[i]>='A' && s[i]<='Z' || s[i]>='a' && s[i]<='z' || s[i]>='0' && s[i]<='9' )
        {
            postfix += s[i];
        }

        else if(s[i]=='(')
        {
            st.push(s[i]);
        }

        else if(s[i]==')')
        {
            while(!st.empty() && st.top()!='(')
            {
                postfix+=st.top();
                st.pop();
            }
            st.pop();
        }

        else
        {
            while(!st.empty() && precedence(st.top())>=precedence(s[i]))
            {
                postfix+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }


        i++;



    }

    while(!st.empty())
    {
        postfix += st.top();
        st.pop();
    }

}



int main()
{

    string s = "(p+q)*(m-n)";

    string postfix = "";

    infixToPostfix(s, postfix);

    cout<<postfix;


   
}