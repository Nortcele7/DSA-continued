#include<iostream>
#include<vector>

using namespace std;

int f(int index, int target, vector<int>& arr)
{

    if(index==0)
    {
        if(target%arr[index]==0)
        {
            return 1;
        } 
        else
        {
            return 0;
        } 
    }



    int not_take = f(index-1, target, arr);

    int take = 0;

    if(target>=arr[index])
    {
        take = f(index, target-arr[index], arr);
    }

    return not_take + take;


}

int main()
{
    vector<int> arr = {1,2,3};

    int n = arr.size();

    int target = 4;

    cout<<f(n-1, target, arr);



}