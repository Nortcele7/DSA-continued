#include<iostream>
#include<vector>
using namespace std;

int cherryPickup(int i, int j1, int j2, vector<vector<int>>& arr)
{

    if(i<0 || j1<0 || j2<0)
    {
        return -1e8;
    }

    if(i==0 && j1==0 && j2==0)
    {
        return arr[i][j1];
    }



}

int main()
{
    vector<vector<int>> arr = {{0,1,-1},{1,0,-1},{1,1,1}};

    int n = arr.size();



}