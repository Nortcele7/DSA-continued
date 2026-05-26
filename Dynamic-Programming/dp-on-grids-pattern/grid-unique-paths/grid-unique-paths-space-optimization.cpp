#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int m = 3, n = 7;

    vector<int> prev(n,0);
    vector<int> curr(n,0);


    for(int i=0; i<m; i++)
    {
        // prev = curr;
        for(int j=0; j<n; j++)
        {
            if(i==0 && j==0)
            {
              curr[j] = 1;  
            }
            else
            {
                int left=0, up=0;
                if(j>0)
                {
                    left = curr[j-1];
                }
                
                if(i>0)
                {
                    up = prev[j];
                }

                curr[j] = left+up;
            }
        }
        prev = curr;
    }

    cout<<curr[n-1];

}