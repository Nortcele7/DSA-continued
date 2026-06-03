#include<iostream>
#include<vector>
using namespace std;

int main()
{

    vector<int> arr = {1,2,2,3};

    int n = arr.size();
    
    int target = 3;

    vector<vector<int>>dp(n, vector<int>(target+1, 0));

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=target; j++)
        {
            if(j==0)
            {
                dp[i][j] = 1;
            }
            else if(i==0)
            {
                dp[i][j] = (arr[i]==j);
            }
            else
            {
                int not_pick = dp[i-1][j];

                int pick = 0;
                if(j>=arr[i])
                {
                    pick = dp[i-1][j-arr[i]];
                }
                dp[i][j] = not_pick+pick;
            }
            
        }
    }

    cout<<dp[n-1][target];
    

}