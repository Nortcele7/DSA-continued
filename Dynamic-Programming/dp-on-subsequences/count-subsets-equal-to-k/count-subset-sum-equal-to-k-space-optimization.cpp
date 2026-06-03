#include<iostream>
#include<vector>
using namespace std;

int main()
{

    vector<int> arr = {0,0,1};

    int n = arr.size();

    int target = 1 ;

    vector<int> prev(target+1, 0);
    vector<int> curr(target+1, 0);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=target; j++)
        {
            if(j==0)
            {
                curr[j] = 1;
            }
            else if(i==0)
            {
                curr[j] = (arr[i]==j);
            }
            else
            {
                int not_pick = prev[j];

                int pick = 0;

                if(j>=arr[i])
                {
                    pick = prev[j-arr[i]];
                }

                curr[j] = not_pick + pick;
            }

        }
        prev = curr;
    }

    cout<<prev[target];

}