#include<iostream>
#include<vector>
using namespace std;

int countPartitionsWithGivenSum(int index, int target, vector<int>& arr)
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

    int not_take = countPartitionsWithGivenSum(index-1, target, arr);

    int take = 0;

    if(target>=arr[index])
    {
        take = countPartitionsWithGivenSum(index-1, target-arr[index], arr);
    }

    return not_take+take;

}

int main()
{

    vector<int> arr = {1,1,2,3};

    int n = arr.size();

    int diff = 1, sum=0;

    for(int i=0; i<n; i++)
    {
        sum += arr[i];
    }

    if(((sum-diff)<0) || ((sum-diff)%2 == 1))
    {
        cout<<0;
        return 0;
    }

    int s2 = (sum-diff)/2;

    cout<<countPartitionsWithGivenSum(n-1, s2, arr);







}
