#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> arr = {100, 4, 200, 1, 3, 2};

    sort(arr.begin(), arr.end());


    int n = arr.size();

    int lastSmaller = INT_MIN;
    int countCurr = 0;

    int longest = INT_MIN;

    int x;

    for(int i=0; i<n; i++)
    {
        x = arr[i];

        if(lastSmaller==INT_MIN)
        {
            lastSmaller = x;
            countCurr = 1;
            continue;
        }

        if((x-1)==lastSmaller)
        {
            lastSmaller=x;
            countCurr++;
        }

        else if(x==lastSmaller)
        {
            continue;
        }

        else
        {
            lastSmaller=x;
            countCurr=1;
        }

        longest = max(longest, countCurr);

    }

    cout<<longest;


}