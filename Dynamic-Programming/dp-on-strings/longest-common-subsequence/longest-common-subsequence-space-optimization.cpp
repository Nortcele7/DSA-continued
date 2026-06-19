#include<iostream>
#include<vector>
#include<climits>

using namespace std;


int main()
{


    string s1 = "acd";

    string s2 = "ced";

    int n1 = s1.length();
    int n2 = s2.length();

    vector<int> prev(n2, 0);
    vector<int> curr(n2, 0);

    for(int i=0; i<n1; i++)
    {
        for(int j=0; j<n2; j++)
        {
            if(s1[i]==s2[j])
            {
                
                curr[j] = 1;
                
                if(i>0 && j>0)
                {
                    curr[j] = 1 + prev[j-1];
                }
                
            }
            else
            {
                int case1 = 0, case2 = 0;
                if(i>0)
                {
                    case1 = prev[j];
                }
                if(j>0)
                {
                    case2 = curr[j-1];
                }
                curr[j] = 0 + max(case1, case2);
            }
        }
        prev = curr;
    }

    cout<<prev[n2-1];


}