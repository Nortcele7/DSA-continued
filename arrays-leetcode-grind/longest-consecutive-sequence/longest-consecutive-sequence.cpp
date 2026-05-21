#include<iostream>
#include<vector>
using namespace std;

bool linear_search(vector<int> arr, int x)
{
    int n = arr.size();
    
    for(int i=0; i<n; i++)
    {
        if(arr[i]==x)
        {
            return true;
        }
    }

    return false;
}

int main()
{

    vector<int> arr = {102, 4, 100, 1, 101, 3, 2, 1, 1};

    int n = arr.size();

    int longest = 1, curr;

    int x;

    for(int i=0; i<n; i++)
    {
        x = arr[i];
        curr = 1;

        while(linear_search(arr, x+1))
        {
            x++;
            curr++;
        }

        longest = max(longest, curr);
    }

    cout<<longest;

}