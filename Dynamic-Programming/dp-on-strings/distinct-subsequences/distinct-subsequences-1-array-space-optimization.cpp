#include<iostream>
#include<vector>
using namespace std;

int main()
{

    string s1 = "babgbag";
    string s2 = "bag";

    int n1 = s1.length();
    int n2 = s2.length();

    vector<int> prev(n2+1, 0);

    prev[0] = 1;

    for(int i=1; i<=n1; i++)
    {
        for(int j=n2; j>=1; j--)
        {
            if(s1[i-1]==s2[j-1])
            {
                prev[j] = prev[j-1] + prev[j];
            }
            else
            {
                prev[j] = prev[j];
            }
        }
    }

    cout<<prev[n2];

    


}