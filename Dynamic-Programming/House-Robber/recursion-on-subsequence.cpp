#include<iostream>
#include<vector>
using namespace std;

void ss(int n, vector<int> arr1, vector<int>& arr2)
{

    if(n>=arr1.size())
    {
        for(int i=0; i<arr2.size(); i++)
        {
            cout<<arr2[i]<<" ";
        }
        cout<<endl;
        return;
    }

    arr2.push_back(arr1[n]);
    ss(n+1,arr1,arr2);
    arr2.pop_back();
    ss(n+1, arr1, arr2);

}

int main()
{
    vector<int> arr1 = {3,1,2};

    vector<int> arr2 = {};

    ss(0, arr1, arr2);

}