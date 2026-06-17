#include<iostream>
#include<vector>
using namespace std;


int main()
{

    string s1 = "horse";
    string s2 = "ros";

    int n1 = s1.length();
    int n2 = s2.length();

    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

    for(int i=0; i<=n1; i++)
    {
        for(int j=0; j<=n2; j++)
        {
            if(i==0)
            {
                dp[i][j] = j;
            }

            else if(j==0)
            {
                dp[i][j] = i;
            }

            else if(s1[i-1]==s2[j-1])
            {
                dp[i][j] = 0 + dp[i-1][j-1];
            }

            else
            {
                int insert = 1 + dp[i][j-1];
                int remove = 1 + dp[i-1][j];
                int replace = 1 + dp[i-1][j-1];
                dp[i][j] = min(insert, min(remove, replace));
            }
        }
    }

    // Only one of the if cases should be executed
    // We replaced j+1 by j and i+1 by i in base case because we are using 1 based indexing
    // This is the reason why we used s1[i-1]==s2[j-1] to compare the characters of two strings

    cout<<dp[n1][n2];



}