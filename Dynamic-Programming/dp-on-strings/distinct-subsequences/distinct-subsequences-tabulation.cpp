#include<iostream>
#include<vector>
using namespace std;

int main()
{

    string s1 = "babgbag";
    string s2 = "bag";

    int n1 = s1.length();
    int n2 = s2.length();

    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

    for(int j=0; j<=n2; j++)
    {
        dp[0][j] = 0;
    }

    for(int i=0; i<=n1; i++)
    {
        dp[i][0] = 1;
    }

    for(int i=1; i<=n1; i++)
    {
        for(int j=1; j<=n2; j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout<<dp[n1][n2];

    

 
}