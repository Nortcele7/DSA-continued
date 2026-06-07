#include<iostream>
#include<vector>

using namespace std;

int f(int index, int N, vector<int>& price)
{


    if(index==0)
    {
        return N * price[index];
    }


    int not_take = f(index-1, N, price);

    int take = 0;

    if(N>=(index+1))
    {
        take = price[index] + f(index, N-(index+1), price);
    }

    return max(not_take, take);

}

int main()
{

    vector<int> price = {2,5,7,8,10};

    int n = price.size();

    cout<<f(n-1, n, price);

}