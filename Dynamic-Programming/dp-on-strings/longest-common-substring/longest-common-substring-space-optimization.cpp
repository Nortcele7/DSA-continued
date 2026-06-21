#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;


int main()
{


    string s1 = "abcdecd";

    string s2 = "bbcdezd";

    int n1 = s1.length();
    int n2 = s2.length();

    vector<int> prev(n2+1, 0);
    vector<int> curr(n2+1, 0);

    int max_val = 0;

    for(int i=1; i<=n1; i++)
    {
        for(int j=1; j<=n2; j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                curr[j] = 1 + prev[j-1];
                max_val = max(max_val, curr[j]);
            }
            else
            {
                curr[j] = 0;
            }
        }
        prev = curr;
    }
   
    cout<<max_val;

}