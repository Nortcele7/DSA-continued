#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int f(int index, int wt, vector<int>& weight, vector<int>& val)
{

    // Base Case

    if(index==0)
    {
        if(wt>=weight[index])
        {
            return val[index];
        }

        else
        {
            return 0;
        }
    }

    int not_take = 0+f(index-1, wt, weight, val);

    int take = INT_MIN;

    if(wt>=weight[index])
    {
        take=val[index]+f(index-1, wt-weight[index], weight, val);
    }

    return max(not_take, take);



}

int main()
{

    vector<int> weight = {3,2,4};
    vector<int> val = {30, 40, 60};

    int n = weight.size();

    int wt = 6;

    cout<<f(n-1,wt, weight, val);

}