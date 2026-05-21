#include<iostream>
#include<vector>
using namespace std;
int main()
{
    
    vector<int> arr = {3, 1, -2, -5, 2, -4};
    
    int n = arr.size();

    vector<int> res_array(n);

    int p_idx = 0;
    int n_idx = 1;

    for(int i=0; i<n; i++)
    {
        if(arr[i]>=0)
        {
            res_array[p_idx] = arr[i];
            p_idx+=2;
        }
        else
        {
            res_array[n_idx] = arr[i];
            n_idx+=2; 
        }
    }

    for(int i=0; i<n; i++)
    {
        cout<<res_array[i]<<" ";
    }

}