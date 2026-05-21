#include<iostream>
#include<vector>
#include <unordered_set>
#include<climits>
using namespace std;
int main()
{

    vector<int> arr = {102, 4, 100, 1, 101, 3, 2, 1, 1};

    int n = arr.size();

    unordered_set<int> st;

    int longest=INT_MIN;
    int countCurr = 0;
    int x;

    for(int i=0; i<n; i++)
    {
        st.insert(arr[i]);
    }

    for(auto it: st)
    {
        if(st.find(it-1) == st.end())
        {
            // This means it-1 is not present in set so it can be the staring element of the sequence

            countCurr = 1;
            x = it;

            while(st.find(x+1)!=st.end())
            {
                x++;
                countCurr++;
            }

            longest = max(longest, countCurr);

        }
    }

    cout<< longest;

}