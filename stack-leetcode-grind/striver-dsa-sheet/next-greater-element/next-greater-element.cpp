#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;



int main()
{

    vector<int> arr = {6, 0, 8, 1, 3};

    int n1 = arr.size();

    vector<int> nge(n1, -1);

    for(int i=0; i<n1; i++)
    {
        for(int j=i+1; j<n1; j++)
        {
            if(arr[j]>arr[i])
            {
                nge[i] = arr[j];
                break;
            }
        }
    }

    for(int i=0; i<n1; i++)
    {
        cout<<nge[i]<<" ";
    }
    


}

