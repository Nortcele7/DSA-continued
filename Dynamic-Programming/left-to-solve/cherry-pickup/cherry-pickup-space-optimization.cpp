#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<vector<int>> arr = {{0,1,-1},{1,0,-1},{1,1,1}};

    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    vector<int> prev(n, 0);
    vector<int> curr(n, 0);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(arr[i][j]!=-1)
            {

                if(i==0 && j==0)
                {
                    curr[j] = arr[i][j];
                }
                else
                {
                    int left=-1e8, up=-1e8;
                    if(j>0)
                    {
                        left = arr[i][j] + curr[j-1];     // Same row diff column
                    }

                    if(i>0)
                    {
                        up = arr[i][j] + prev[j];    // Previous row same column  So we need only curr row and prev row
                    }

                    curr[j] = max(left, up);
                }
            }
            else
            {
                curr[j] = -1e8;
            }
        }
        prev = curr;
    }

    cout<<prev[n-1];


}