#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int f(int index, vector<int>& arr)
{
    if(index==0)
    {
        return arr[0];
    }

    if(index<0)
    {
        return 0;
    }

    int take = arr[index] + f(index-2, arr);

    int not_take = f(index-1, arr);

    return max(take, not_take);



}

int main()
{

    vector<int> arr = {2,2,3,3,3,4};

    int n = arr.size();

    vector<int> freq(10001,0);
    vector<int> points(10001,0);

    int max_val = INT_MIN;

    for(int i=0; i<n; i++)
    {
        max_val = max(max_val, arr[i]);
        freq[arr[i]]++;
    }

    for(int i=0; i<=max_val; i++)
    {
        points[i] = i * freq[i];
    }

    // We will now use points array

    cout<<f(max_val, points);

}