#include<iostream>
#include<vector>
using namespace std;

int main()
{

    vector<int> arr = {1,4,3,2};

    int n = arr.size();

    int sum = 0;

    for(int i=0; i<n; i++)
    {
        int max_value = arr[i];
        int min_value = arr[i];
        for(int j=i+1; j<n; j++)
        {
            max_value = max(max_value, arr[j]);
            min_value = min(min_value, arr[j]);
            int range = max_value - min_value;
            sum = sum + range;

        }
    }

    cout<<sum;

}