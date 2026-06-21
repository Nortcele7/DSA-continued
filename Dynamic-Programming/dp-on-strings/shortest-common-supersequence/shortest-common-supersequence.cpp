#include<iostream>
#include<vector>
using namespace std;

int main()
{
    string s1 = "brute";
    string s2 = "groot";

    int n1 = s1.length();
    int n2 = s2.length();

    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

    for(int i=1; i<=n1; i++)
    {
        for(int j=1; j<=n2; j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    int lcs = dp[n1][n2];

    int ans = n1 + n2 - lcs;

    cout<<ans;



}