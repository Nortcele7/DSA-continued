#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main()
{

    vector<vector<int>> arr = {{2,1,3}, {6,5,4}, {7,8,9}};

    int n = arr.size();
    int m = arr[0].size();

    vector<int> prev(m,0);
    vector<int> curr(m,0);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(i==0)
            {
                curr[j] = arr[i][j];
            }

            else
            {
                int up=INT_MIN, leftd=INT_MIN, rightd=INT_MIN;

                if(i>0)
                {
                    up = arr[i][j] + prev[j];
                }

                if(i>0 && j>0)
                {
                    leftd = arr[i][j] + prev[j-1];
                }

                if(i>0 && j<m-1)
                {
                    rightd = arr[i][j] + prev[j+1];
                }

                curr[j] = max(up, max(leftd, rightd));

            }

        }
        prev = curr;
    }

    int max_val = INT_MIN;

    for(int j=m-1; j>=0; j--)
    {
        max_val = max(max_val, prev[j]);
    }

    cout<<max_val;

}