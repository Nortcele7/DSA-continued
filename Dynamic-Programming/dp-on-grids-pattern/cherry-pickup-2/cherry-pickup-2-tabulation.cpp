#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<vector<int>> arr = {{3,1,1},{2,5,1},{1,5,5},{2,1,1}};

    int n = arr.size();
    int m = arr[0].size();

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m , vector<int>(m, 0)));

    // We start with the last index and then move to [0][0][m-1]
    for(int i=n-1; i>=0; i--)
    {
        for(int j1=0; j1<m; j1++)
        {
            for(int j2=0; j2<m; j2++)
            {
                if(i==n-1)
                {
                    if(j1==j2)
                    {
                        dp[i][j1][j2] = arr[i][j1];
                    }
                    else
                    {
                        dp[i][j1][j2] = arr[i][j1]+arr[i][j2];
                    }
                }
                else
                {
                    int max_val = -1e8;
                    for(int dj1=-1; dj1<=1; dj1++)
                    {
                        for(int dj2=-1; dj2<=1; dj2++)
                        {
                            if(j1+dj1>=0 && j1+dj1<m && j2+dj2>=0 && j2+dj2<m){
                                if(j1==j2)
                                {
                                    max_val = max(max_val, arr[i][j1]+dp[i+1][j1+dj1][j2+dj2]);
                                }
                                else
                                {
                                    max_val = max(max_val, arr[i][j1]+arr[i][j2]+dp[i+1][j1+dj1][j2+dj2]);
                                }
                            }
                        }
                    }
                    dp[i][j1][j2] = max_val;
                }
            }
        }
    }

    cout<<dp[0][0][m-1];



   
}