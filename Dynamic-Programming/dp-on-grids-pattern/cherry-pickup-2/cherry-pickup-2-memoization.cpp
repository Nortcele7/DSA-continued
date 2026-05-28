#include<iostream>
#include<vector>
using namespace std;

int cherryPickup2(int i, int j1, int j2, vector<vector<int>> arr, vector<vector<vector<int>>>& dp)
{
    
    if(j1<0 || j1>=arr[0].size() || j2<0 || j2>=arr[0].size())
    {
        return -1e8;
    }

    if(i==arr.size()-1)
    {
        if(j1==j2)
        {
            return arr[i][j1];
        }
        else
        {
            return arr[i][j1]+arr[i][j2];
        }
    }

    if(dp[i][j1][j2]!=-1)
    {
        return dp[i][j1][j2];
    }

    else
    {
        int max_val = -1e8;
        for(int dj1=-1; dj1<=1; dj1++)
        {
            for(int dj2=-1; dj2<=1; dj2++)
            {
                if(j1==j2)
                {
                    max_val = max(max_val, arr[i][j1] + cherryPickup2(i+1, j1+dj1, j2+dj2, arr, dp));
                }
                else
                {
                    max_val = max(max_val, arr[i][j1] + arr[i][j2] + cherryPickup2(i+1, j1+dj1, j2+dj2, arr, dp));
                }
            }
        }
        return dp[i][j1][j2] = max_val;
    }

}

int main()
{
    vector<vector<int>> arr = {{3,1,1},{2,5,1},{1,5,5},{2,1,1}};

    int n = arr.size();
    int m = arr[0].size();

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m , vector<int>(m, -1)));

    cout<<cherryPickup2(0, 0, m-1, arr, dp);
}