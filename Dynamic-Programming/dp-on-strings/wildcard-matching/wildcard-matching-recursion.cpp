#include<iostream>
using namespace std;

bool isMatch(string s, string p, int i, int j)
{

    // Base Case

    if(i<0 && j<0)
    {
        return true;
    }

    if(i<0 && j>=0)
    {
        return false;
    }

    if(j<0 && i>=0)
    {
        for(int i1 = 0; i1<=i; i1++)
        {
            if(p[i1]!='*')
            {
                return false;
            }
        }
        return true;
    }


    if(p[i]==s[j] || p[i]=='?')
    {
        return isMatch(s,p,i-1,j-1);
    }

    if(p[i]=='*')
    {
        return isMatch(s, p, i-1, j) || isMatch(s, p, i, j-1);
    }

    return false;

}

int main()
{
    string p = "*bcd";
    string s = "bcd";

    int m = p.length();
    int n = s.length();

    cout<< isMatch(s, p, m-1, n-1);

}