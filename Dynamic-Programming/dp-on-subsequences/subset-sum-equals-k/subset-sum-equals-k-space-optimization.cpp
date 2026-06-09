#include<iostream>
#include<vector>
using namespace std;

int main()
{

    vector<int> arr = {2,3,1,1};

    int n=arr.size();

    int target = 4;

    vector<bool> prev(target+1, false);
    vector<bool> curr(target+1, false);



    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=target; j++)
        {
            if(j==0)
            {
                curr[j] = true;
            }
            else if(i==0)
            {
                curr[j] = (arr[i]==j);
            }
            else
            {
                bool not_take = prev[j];

                bool take = false;

                if(j>=arr[i])
                {
                    take = prev[j-arr[i]];
                }

                curr[j] = take || not_take;
            }
        }
        prev = curr;
    }

    cout<<prev[target];

}