#include<iostream>
#include<vector>

using namespace std;

int f(int idx, int prev_idx, vector<int>& arr, int k)
{
    // Base Case


    int n = arr.size();

    if(idx==n)
    {
        return 0;
    }

    // We first have the choice of taking the element or choice of not taking the element

    // If we dont take the current element then we add 0 and then calculate the Length of Longest Increasing Subsequence again
    int len = 0 + f(idx+1, prev_idx, arr, k);


    // One subtle change that we make is, here the difference between 2 adjacent elements must be less or equal to k
    // If we take it, we can only take it if there is no previous element, so we are free to choose any element or if current element is higher than previous element

    if(prev_idx==-1 || arr[idx]>arr[prev_idx] && arr[idx]-arr[prev_idx]<=k)
    {
        len = max(len, 1+f(idx+1, idx, arr, k));
    }

    return len;

}

int main()
{
    vector<int> arr = {4,2,1,4,3,4,5,8,15};
    int k = 3;

    int n = arr.size();

    cout<<f(0, -1, arr, k);
}