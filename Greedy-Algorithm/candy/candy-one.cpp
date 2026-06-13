#include<iostream>
#include<vector>
using namespace std;

int main()
{

    vector<int> arr = {0, 2, 4, 3, 2, 1, 1, 3, 5, 6, 4, 0, 0};

    int n = arr.size();

    vector<int> left(n, 1);
    vector<int> right(n, 1);

    left[0] = 1;

    for(int i=1; i<n; i++)
    {
        if(arr[i]>arr[i-1])
        {

            left[i] = left[i-1] + 1;
        }
        else
        {
            left[i] = 1;
        }
    }

    right[n-1] = 1;

    for(int i=n-2; i>=0; i--)
    {
       if(arr[i]>arr[i+1])
       {
        right[i] = right[i+1] + 1;
       }
       else
       {
         right[i]=1;
       }
    }

    int total = 0;
    
    for(int i=0; i<n; i++)
    {
        total += max(left[i], right[i]);
    }

    cout<<total;

}