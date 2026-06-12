#include<iostream>
#include<vector>
using namespace std;

bool checkValidString(string s, int idx, int count, vector<vector<int>>& dp)
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

    if(dp[idx][count]!=-1)
    {
        return dp[idx][count];
    }

    bool ans = false;

    if(s[idx]=='*')
    {
        ans = checkValidString(s, idx+1, count+1, dp) || checkValidString(s, idx+1, count-1, dp) || checkValidString(s, idx+1, count, dp);
    }

    if(s[idx]=='(')
    {
        ans = checkValidString(s, idx+1, count+1, dp);
    }

    if(s[idx]==')')
    {
        ans = checkValidString(s, idx+1, count-1, dp);
    }

    return dp[idx][count] = ans;

}

int main()
{

    string s = "(*()";

    int n = s.length();

    vector<vector<int>> dp(n, vector<int>(n, -1));

    cout<<checkValidString(s, 0, 0, dp);

}