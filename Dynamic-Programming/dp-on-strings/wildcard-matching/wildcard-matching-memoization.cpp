#include<iostream>
#include<vector>
using namespace std;

bool isMatch(string s, string p, int i, int j, vector<vector<int>>& arr)
{

    // Base Case

    if(i<0 && j<0)
    {
        return true;
    }

    if(i<0 && j>=0)
    {
        return false;
    }

    if(j<0 && i>=0)
    {
        for(int i1 = 0; i1<=i; i1++)
        {
            if(p[i1]!='*')
            {
                return false;
            }
        }
        return true;
    }

    if(arr[i][j]!=-1)
    {
        return arr[i][j];
    }


    if(p[i]==s[j] || p[i]=='?')
    {
        return arr[i][j] = isMatch(s,p,i-1,j-1, arr);
    }

    if(p[i]=='*')
    {
        return arr[i][j] = isMatch(s, p, i-1, j, arr) || isMatch(s, p, i, j-1, arr);
    }

    return arr[i][j] = false;

}

int main()
{
    string p = "ab*cd";
    string s = "abdefcd";

    int m = p.length();
    int n = s.length();

    vector<vector<int>> arr(m, vector<int>(n, -1));

    cout<< isMatch(s, p, m-1, n-1, arr);

}