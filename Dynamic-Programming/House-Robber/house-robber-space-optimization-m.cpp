#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main()
{
    vector<int> arr = {1,2,3,1};

    int n = arr.size();

    int curr;
    int prev2 = arr[0];
    int prev = max(arr[1], arr[0]);
    int pick;
    int not_pick;

    for(int i=2; i<n; i++)
    {
        pick = arr[i]+prev2;
        not_pick = 0+prev;
        curr = max(pick, not_pick);

        prev2 = prev;
        prev = curr;

    }

    cout<<prev;

}