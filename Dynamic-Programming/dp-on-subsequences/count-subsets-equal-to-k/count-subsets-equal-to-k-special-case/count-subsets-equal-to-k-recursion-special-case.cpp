#include<iostream>
#include<vector>
using namespace std;

int count(int index, int target, vector<int>& arr)
{

    if(index==0)
    {
        if(target==0 && arr[index]==0)
        {
            return 2;
        }

        if(target==0 || arr[index]==target)
        {
            return 1;
        }

        return 0;

    }

    int not_pick = count(index-1, target, arr);
    int pick = 0;

    if(target>=arr[index])
    {
        pick = count(index-1, target-arr[index], arr);
    }

    return pick+not_pick;

}

int main()
{

    vector<int> arr = {0,0,1};

    int n = arr.size();

    int target = 1;

    cout<<count(n-1, target, arr);

}