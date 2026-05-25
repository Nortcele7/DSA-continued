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

int houseRobber2(vector<int> arr)
{
    int ans1, ans2;

    int n = arr.size();

    // n-2 because we generally use n-1 to pass to the function but here we are slicing the array and the size of passed array is itself n-1 
    // So, we use n-2 i.e n-1-1
    ans1 = houseRobber(n-2, vector<int>(arr.begin()+1, arr.end()));
    ans2 = houseRobber(n-2, vector<int>(arr.begin(), arr.end()-1));

    return max(ans1, ans2);
}

int main()
{

    vector<int> arr = {2,3,2};

    cout<<houseRobber2(arr);

}