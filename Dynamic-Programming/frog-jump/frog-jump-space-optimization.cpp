#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main()
{


    vector<int> arr = {30, 10, 60, 10, 60, 50};

    int n = arr.size();

    int curr;
    int prev2 =  0;
    int prev = abs(arr[1]-arr[0]);

    for(int i=2; i<n; i++)
    {
        curr = min( (prev+abs(arr[i]-arr[i-1])), (prev2+abs(arr[i]-arr[i-2])) );

        prev2 = prev;
        prev = curr;

    }

    cout<<prev;

}