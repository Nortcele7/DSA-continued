#include<iostream>
#include<vector>
using namespace std;

int f(int index, int buy, vector<int>& prices)
{
    int n = prices.size();

    if(index==n || index==n+1)
    {
        return 0;
    }

    if(buy)
    {
        return max(-prices[index]+f(index+1, 0, prices), 0+f(index+1, 1, prices));
    }

    else
    {
        return max(prices[index]+f(index+2, 1, prices), 0+f(index+1, 0, prices));
    }

}

int main()
{
    vector<int> prices = {1,2,3,0,2};

    cout<<f(0, 1, prices);
}