#include<iostream>
#include<vector>
using namespace std;
int main()
{

    vector<int> arr = {3, 1, -2, -5, 2, -4};

    vector<int> pos;
    vector<int> neg;

    int n = arr.size();

    for(int i=0; i<n; i++)
    {
        if(arr[i]>=0)
        {
            pos.push_back(arr[i]);
        }
        else
        {
            neg.push_back(arr[i]);
        }
    }

    int i=0;

    while(i<pos.size())
    {
        arr[2*i] = pos[i];
        arr[2*i + 1] = neg[i];

        i++;
    }

    for(int i=0; i<n; i++)
    {
        cout<< arr[i] <<" ";
    }

}