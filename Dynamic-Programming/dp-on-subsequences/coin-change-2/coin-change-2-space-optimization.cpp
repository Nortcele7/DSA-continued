#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> arr = {1,2,3};

    int n = arr.size();

    int target = 4;

    vector<vector<int>> dp(n, vector<int>(target+1, 0));

    vector<int> prev(target+1, 0);
    vector<int> curr(target+1, 0);

    // Replace this in tabulation: arr[i] by curr and arr[i-1] = prev


    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=target; j++)
        {
            if(i==0)
            {
                if(j%arr[i]==0)
                {
                    curr[j] = 1;
                }
                else
                {
                    curr[j] = 0;
                }
            }
            else
            {
                int not_take = prev[j];

                int take = 0;

                if(j>=arr[i])
                {
                    take = curr[j-arr[i]];
                }

                curr[j] = not_take + take;

            }
        }
        prev = curr;
    }

    cout<<curr[target];



}