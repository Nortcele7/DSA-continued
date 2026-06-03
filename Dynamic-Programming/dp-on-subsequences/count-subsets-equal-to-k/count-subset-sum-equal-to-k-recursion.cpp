#include<iostream>
#include<vector>
using namespace std;

int count(int index, int target, vector<int>& arr)
{

    if(target==0)
    {
        return 1;
    }

    if(index==0)
    {
        return (arr[index]==target);
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

    vector<int> arr = {1,2,2,3};

    int n = arr.size();

    int target = 3;

    cout<<count(n-1, target, arr);

}