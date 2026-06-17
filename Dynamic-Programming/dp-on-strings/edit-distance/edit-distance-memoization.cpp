#include<iostream>
#include<vector>
using namespace std;

int editDistance(int i, int j, string s1, string s2, vector<vector<int>>& dp)
{

    if(i<0)
    {
        return j+1;
    }

    if(j<0)
    {
        return i+1;
    }

    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    
    else
    {

        if(s1[i]==s2[j])
        {
            return dp[i][j] = 0 + editDistance(i-1, j-1, s1, s2, dp);
        }

        // Insert
        int insert = 1 + editDistance(i, j-1, s1, s2, dp);

        // Remove
        int remove = 1 + editDistance(i-1, j, s1, s2, dp);

        // Replace
        int replace = 1 + editDistance(i-1, j-1, s1, s2, dp);

        return dp[i][j] = min(insert, min(remove, replace));

    }



}

int main()
{

    string s1 = "horse";
    string s2 = "ros";

    int n1 = s1.length();
    int n2 = s2.length();

    vector<vector<int>> dp(n1, vector<int>(n2, -1));

    cout<<editDistance(n1-1, n2-1, s1, s2, dp);



}