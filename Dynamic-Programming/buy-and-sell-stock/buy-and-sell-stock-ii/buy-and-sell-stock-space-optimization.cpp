#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    int n = prices.size();

    int buy_zero = 0;
    int buy_one = 0;

    int old_buy_zero = 0;
    int old_buy_one = 1;

    for(int i=n-1; i>=0; i--)
    {

        old_buy_zero = buy_zero;
        old_buy_one = buy_one;
        
        buy_one = max(-prices[i]+old_buy_zero, 0+old_buy_one);

        buy_zero = max(prices[i]+old_buy_one, 0+old_buy_zero);
    }

    cout<<buy_one;
}