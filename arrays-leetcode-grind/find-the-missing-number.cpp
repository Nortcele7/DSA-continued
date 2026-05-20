#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> arr = {0,1,3};

    int n = arr.size();
    int xor1 = 0, xor2 = 0;

    for(int i=0; i<n; i++)
    {
        xor1 = xor1 ^  arr[i];
    }

    for(int i=0; i<=n; i++)
    {
        xor2 = xor2 ^ i;
    }

    int found_missing_number = xor1 ^ xor2;

    cout<< found_missing_number;

}