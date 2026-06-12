#include<iostream>
using namespace std;

bool checkValidString(string s)
{

    int n = s.length();

    int count = 0;

    for(int i=0; i<n; i++)
    {
        if(s[i]=='(')
        {
            count = count + 1;
        }
        else if(s[i]==')')
        {
            count = count - 1;
        }
        if(count < 0 )
        {
            return false;
        }
    }

    return (count == 0);

}

int main()
{

    string s = "(()())";

    cout<<checkValidString(s);
    
}