#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int f(int index, int target, vector<int>& arr)
{

    // Base Case 

    if(index==0)
    {
        if(target%arr[index]==0)
        {
            return target/arr[index];
        }
        else
        {
            return 1e8;
        }
    }

    

    int not_take = f(index-1, target, arr);

    int take = 1e8;

    if(target>=arr[index])
    {
        take = 1 + f(index, target-arr[index], arr); 
    }

    return min(not_take, take);

}

int main()
{

    vector<int> arr = {1,2,3};
    int n = arr.size();

    int target = 7;

    cout<<f(n-1, target, arr);





}