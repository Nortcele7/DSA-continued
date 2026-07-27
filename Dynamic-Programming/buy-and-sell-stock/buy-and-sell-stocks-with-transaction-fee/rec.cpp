#include<iostream>
#include<vector>
using namespace std;

int f(int index, int buy, vector<int>& prices, int fee)
{
    int n = prices.size();
    if(index==n)
    {
        return 0;
    }

    if(buy)
    {
        return max(-prices[index]+f(index+1, 0, prices, fee), 0+f(index+1, 1, prices, fee));
    }

    else
    {
        return max(prices[index]+f(index+1, 1, prices, fee)-fee, 0+f(index+1, 0, prices, fee));
    }

}

int main()
{
    vector<int> prices = {1,3,2,8,4,9};
    int fee = 2;

    cout<<f(0, 1, prices, fee);
}