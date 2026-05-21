#include<iostream>
#include<vector>
using namespace std;

int main()
{

    int n = 5;

    vector<int> dp_array(n+1, -1);

    dp_array[0] = 0;
    dp_array[1] = 1;

    for(int i=2; i<=n; i++)
    {
        dp_array[i] = dp_array[i-1]+dp_array[i-2];
    }

    cout<<dp_array[n];

}