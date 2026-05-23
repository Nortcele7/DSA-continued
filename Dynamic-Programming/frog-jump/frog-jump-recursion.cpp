#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int frogJump(int idx, vector<int> arr)
{
    if(idx==0)
    {
        return 0;
    }

    int jump1, jump2=INT_MAX;
    
    jump1 = frogJump(idx-1, arr)+abs(arr[idx]-arr[idx-1]);

    if(idx>1)
    {
        jump2 = frogJump(idx-2, arr)+abs(arr[idx]-arr[idx-2]);
    }

    return min(jump1, jump2);


}

int main()
{
    vector<int> arr = {30, 10, 60, 10, 60, 50};

    cout<< frogJump(5, arr);
    
    

}