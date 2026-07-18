#include<iostream>
#include<vector>
using namespace std;

int main()
{
    string p = "ab*cd";
    string s = "abdefcd";

    int m = p.length();
    int n = s.length();

    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    dp[0][0] = true;

    for(int j=1; j<=n; j++)
    {
        dp[0][j] = false;
    }


    for(int i = 1; i <= m; i++)
    {
        if(p[i - 1] == '*')
            dp[i][0] = dp[i-1][0];
        else
            dp[i][0] = false;
    }

    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(p[i-1]==s[j-1] || p[i-1]=='?')
            {
                dp[i][j] = dp[i-1][j-1];
            }

            else if(p[i-1]=='*')
            {
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }

            else
            {
                dp[i][j] = false;
            }
        }
    }

    cout<<dp[m][n];

}