#include<iostream>
#include<vector>
#include<stack>
using namespace std;

bool checkValidParenthesis(string s)
{

    stack<char> st1;

    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
        {
            st1.push(s[i]);
        }

        else{

            if(st1.empty())
            {
                return false;
            }

            if(s[i]==')' && st1.top()=='(' || s[i]=='}' && st1.top()=='{' || s[i]==']' && st1.top()=='[')
            {
                st1.pop();
            }

            else
            {
                return false;
            }

        }

    }

    if(st1.empty())
    {
        return true;
    }

    else
    {
        return false;
    }



}


int main()
{

    string s = ")]})";

    cout<<checkValidParenthesis(s);
   
}