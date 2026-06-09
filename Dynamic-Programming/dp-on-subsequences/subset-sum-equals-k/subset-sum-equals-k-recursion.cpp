#include<iostream>
#include<vector>
using namespace std;

bool subsetSum(int index, int target, vector<int>& arr)
{
    if(target==0)
    {
        return true;
    }

    if(index==0)
    {
        return arr[index] == target;
    }

    bool not_take = subsetSum(index-1, target, arr);

    bool take = false;

    if(target>=arr[index])
    {
        take = subsetSum(index-1, target-arr[index], arr);
    }

    return take||not_take;

}

int main()
{

    vector<int> arr = {2,3,1,1};

    int target = 4;

    int n=arr.size();

    cout<<subsetSum(n-1, target, arr);
    
}