#include<iostream>
using namespace std;

bool checkValidString(string s, int idx, int count)
{
    int n = s.length();

    if(count<0)
    {
        return false;
    }

    if(idx==n)
    {
        return (count==0);
    }

    if(s[idx]=='*')
    {
        return checkValidString(s, idx+1, count+1) || checkValidString(s, idx+1, count-1) || checkValidString(s, idx+1, count);
    }

    if(s[idx]=='(')
    {
        return checkValidString(s, idx+1, count+1);
    }

    if(s[idx]==')')
    {
        return checkValidString(s, idx+1, count-1);
    }

}

int main()
{

    string s = "(*()";

    cout<<checkValidString(s, 0, 0);

}