#include<iostream>
#include<vector>
using namespace std;

int f(int ind, int buy, vector<int>& prices)
{
    if(ind==prices.size())
    {
        return 0;
    }



    if(buy)
    {
        return max(-prices[ind]+f(ind+1, 0, prices), 0+f(ind+1, 1, prices));
    }

    else
    {
        return max(prices[ind]+f(ind+1, 1, prices), 0+f(ind+1, 0, prices));
    }


}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    int n = prices.size();

    cout<<f(0, 1, prices);
}