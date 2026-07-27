#include<iostream>
#include<vector>
using namespace std;

int f(int ind, int buy, int cap, vector<int>& prices)
{

    if(cap==0)
    {
        return 0;
    }

    if(ind==prices.size())
    {
        return 0;
    }

    if(buy)
    {
        return max(-prices[ind]+f(ind+1, 0, cap, prices), 0+f(ind+1, 1, cap, prices));
    }

    else
    {
        return max(prices[ind]+f(ind+1, 1, cap-1, prices), 0+f(ind+1, 0, cap, prices));
    }
    

}

int main()
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};

    int n = prices.size();

    cout<<f(0, 1, 2, prices);
}