#include<iostream>
using namespace std;

int f(int i, int j, string s1, string s2)
{

    if(j<0)
    {
        return 1;
    }

    if(i<0)
    {
        return 0;
    }

    if(s1[i]==s2[j])
    {
        return f(i-1, j-1, s1, s2) + f(i-1, j, s1, s2);
    }

    else
    {
        return f(i-1, j, s1, s2);
    }

}

int main()
{

    string s1 = "babgbag";
    string s2 = "bag";

    int n1 = s1.length();
    int n2 = s2.length();

    cout<<f(n1-1, n2-1, s1, s2);

}