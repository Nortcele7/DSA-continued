#include<iostream>
#include<vector>
using namespace std;

int houseRobber(int idx, vector<int> arr)
{
    if(idx==0)
    {
        return arr[0];
    }

    if(idx<0)
    {
        return 0;
    }

    int pick = arr[idx]+houseRobber(idx-2, arr);
    int not_pick = 0+houseRobber(idx-1, arr);

    return max(pick, not_pick);

}

int main()
{

    vector<int> arr = {1,2,3,1};

    int n = arr.size();

    cout<<houseRobber(n-1, arr);

}