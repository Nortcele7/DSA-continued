#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maximumFallingPathSum(int i, int j, vector<vector<int>> arr)
{

    // Checking boundary condition

    if(i<0 || j<0 || j>=arr[0].size())
    {
        return INT_MIN;
    }

    // Then we have the base case
    // We are checking only i==0 but not j. So, if j goes out of bounds then we will never get the value of arr[i][j]
    // The value of i can be i-1 in next recursive call. So, it can go out of bound only if i<0
    // The value of j can be j-1 or j+1 in next recursive call. So, it can go out of bound if j<0 or j>=arr[0].size()

    // Since we know starting points are variable but all lie in the first row. 

    // We check the base case as i==0

    
    if(i==0)
    {
        return arr[i][j];
    }

    int up = maximumFallingPathSum(i-1, j, arr);
    int leftd = maximumFallingPathSum(i-1, j-1, arr);
    int rightd = maximumFallingPathSum(i-1, j+1, arr);

    if(up!=INT_MIN)
    {
        up+=arr[i][j];
    }

    if(leftd!=INT_MIN)
    {
        leftd+=arr[i][j];
    }

    if(rightd!=INT_MIN)
    {
        rightd+=arr[i][j];
    }

    return max(up, max(leftd, rightd));



}

int main()
{

    vector<vector<int>> arr = {{2,1,3}, {6,5,4}, {7,8,9}};

    int n = arr.size();
    int m = arr[0].size();

    int max_val = INT_MIN;


    // We pass each of the ending point

    for(int j=m-1; j>=0; j--)
    {
        max_val = max(max_val, maximumFallingPathSum(n-1, j, arr));
    }

    cout<<max_val;

}