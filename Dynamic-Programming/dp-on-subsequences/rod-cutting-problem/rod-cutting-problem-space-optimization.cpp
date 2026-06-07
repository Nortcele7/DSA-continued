#include<iostream>
#include<vector>

using namespace std;

int main()
{

    vector<int> price = {2,5,7,8,10};

    int n = price.size();

    vector<int> prev(n+1, 0);
    vector<int> curr(n+1, 0);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i==0)
            {
                curr[j] = j*price[i];
            }
            
            else
            {
                int not_take = prev[j];

                int take = 0;

                if(j>=(i+1))
                {
                    take = price[i] + curr[j-(i+1)];
                }

                curr[j] = max(not_take, take);
            }
 
        }

        prev = curr;

    }

    cout<<prev[n];

}