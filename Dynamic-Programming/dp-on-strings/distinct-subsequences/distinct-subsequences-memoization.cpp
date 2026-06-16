#include<iostream>
#include<vector>
using namespace std;

int f(int i, int j, string s1, string s2, vector<vector<int>>& dp)
{
    
    if(j<0)
    {
        return 1;
    }

    if(i<0)
    {
        return 0;
    }

    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }

    else
    {

        if(s1[i]==s2[j])
        {
            return dp[i][j] =  f(i-1, j-1, s1, s2, dp) + f(i-1, j, s1, s2, dp);
        }

        else
        {
            return dp[i][j] = f(i-1, j, s1, s2, dp);
        }
    }

}

int main()
{

    string s1 = "babgbag";
    string s2 = "bag";

    int n1 = s1.length();
    int n2 = s2.length();

    vector<vector<int>> dp(n1, vector<int>(n2, -1));

    cout<<f(n1-1, n2-1, s1, s2, dp);

}