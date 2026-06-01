#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int main()
{

    vector<int> weight = {3,2,4};
    vector<int> val = {30, 40, 60};

    int n = weight.size();

    int wt = 6;

    vector<int> prev(wt+1, 0);

    for(int i=0; i<n; i++)
    {
        for(int j=wt; j>=0; j--)
        {
            if(i==0)
            {
                if(j>=weight[i])
                {
                    prev[j] = val[i];
                }
                else
                {
                    prev[j] = 0;
                }
            }
            else
            {
                int not_take = prev[j];

                int take = INT_MIN;

                if(j>=weight[i])
                {
                    take = val[i]+prev[j-weight[i]];
                }

                prev[j] = max(not_take, take);
            }
        }
    }


    cout<<prev[wt];
}
