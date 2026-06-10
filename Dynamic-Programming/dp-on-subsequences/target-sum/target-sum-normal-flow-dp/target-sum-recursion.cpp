#include<iostream>
#include<vector>
using namespace std;

int targetSum(int index, int target, vector<int>& arr)
{

    if(index==0)
    {

        if(target+arr[index]==0 && arr[0]==0)
        {
            return 2;
        }

        if(target-arr[index]==0)
        {
            return 1;
        }

        if(target+arr[index]==0)
        {
            return 1;
        }

        return 0;
    }

    // Recurrence Relation

    int plus = targetSum(index-1, target-arr[index], arr);
    int minus = targetSum(index-1, target+arr[index], arr);

    // We will return the sum of the ways in which we can assign plus and we can assign minus
    return plus+minus;

}

int main()
{

    vector<int> arr = {1,2,3,1};

    int n = arr.size();

    int target = 3;

    cout<<targetSum(n-1, target, arr);



}