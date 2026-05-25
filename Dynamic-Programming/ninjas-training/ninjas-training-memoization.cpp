#include<iostream>
#include<vector>
using namespace std;

int function(int day, int last, vector<vector<int>>& task, vector<vector<int>>& dp)
{
    int n = task[0].size();

    int max_val;

    if(day==0)
    {
        max_val = 0;

        for(int i=0; i<n; i++)
        {
            if(i!=last)
            {
                max_val = max(max_val, task[0][i]);
            }
        }

        return max_val;

    }

    if(dp[day][last]!=-1)
    {
        return dp[day][last];
    }

    else{
        max_val = 0;

        for(int i=0; i<n; i++)
        {
            if(i!=last)
            {
                int points = task[day][i] + function(day-1, i , task, dp);
                max_val = max(max_val, points);
            }
        }   

        return dp[day][last]=max_val;
    }

}

int main()
{

    vector<vector<int>> task = {{10, 50, 1}, {5, 100, 11}};

    int n = task.size();
    int m = task[0].size();

    vector<vector<int>> dp(n, vector<int>(m+1, -1));

    int day = task.size()-1;

    cout<<function(day, 3, task, dp);

}