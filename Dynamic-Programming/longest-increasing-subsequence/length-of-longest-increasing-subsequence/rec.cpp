#include<iostream>
#include<vector>

using namespace std;

int f(int idx, int prev_idx, vector<int>& arr)
{
    // Base Case


    int n = arr.size();

    if(idx==n)
    {
        return 0;
    }

    // We first have the choice of taking the element or choice of not taking the element

    // If we dont take the current element then we add 0 and then calculate the Length of Longest Increasing Subsequence again
    int len = 0 + f(idx+1, prev_idx, arr);


    // If we take it, we can only take it if there is no previous element, so we are free to choose any element or if current element is higher than previous element

    if(prev_idx==-1 || arr[idx]>arr[prev_idx])
    {
        len = max(len, 1+f(idx+1, idx, arr));
    }

    return len;

}

int main()
{
    vector<int> arr = {10,9,2,5,3,7,101,18};

    int n = arr.size();

    cout<<f(0, -1, arr);
}