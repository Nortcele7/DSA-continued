#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int minPathSum(int i, int j, vector<vector<int>> path)
{

    if(i==0 && j==0)
    {
        return path[i][j];
    }

    if(i<0 || j<0)
    {
        return INT_MAX;
    }


    int left = minPathSum(i, j-1, path);
    int up =  minPathSum(i-1, j, path);

    if(left!=INT_MAX)
    {
        left+=path[i][j];
    }

    if(up!=INT_MAX)
    {
        up+=path[i][j];
    }

    return min(left, up);


    
   
}

int main()
{
    vector<vector<int>> path  = {{5,9,6},{11,5,2}};

    int m=path.size();
    int n=path[0].size();

    cout<<minPathSum(m-1, n-1, path);

}