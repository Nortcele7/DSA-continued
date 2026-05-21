#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main()
{

    vector<int> arr = {1,2,3,4,5};

    int n = arr.size();

    int currentSum = 0;
    int maxSum = INT_MIN;

    int i;

    for(i=0; i<n; i++)
    {
        currentSum += arr[i];
        maxSum = max(maxSum, currentSum);
        
        if(currentSum<0)
        {
            currentSum = 0;
        }


    }

    cout<<maxSum;


}