#include<iostream>
#include<vector>
using namespace std;

int function(int day, int last, vector<vector<int>>& task)
{
    int n = task[day].size();

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

    max_val = 0;

    for(int i=0; i<n; i++)
    {
        if(i!=last)
        {
            int points = task[day][i] + function(day-1, i , task);
            max_val = max(max_val, points);
        }
    }

    return max_val;

}

int main()
{

    vector<vector<int>> task = {{10, 50, 1}, {5, 100, 11}};

    int day = task.size()-1;

    cout<<function(day, 3, task);

}