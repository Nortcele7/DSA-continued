#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main()
{
    
    vector<int> arr = {1,2,9,4,5};

    int n = arr.size();
    int largest = INT_MIN, second_largest = INT_MIN;
    
    for(int i=0; i<n; i++)
    {
        if(arr[i]>largest)
        {
            second_largest = largest;
            largest = arr[i];
        }

        else if(arr[i]>second_largest && arr[i]!=largest)
        {
            second_largest = arr[i];
        }
    }

    cout<<second_largest;

}