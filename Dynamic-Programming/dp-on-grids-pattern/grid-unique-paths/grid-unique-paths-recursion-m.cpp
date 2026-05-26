#include<iostream>
using namespace std;

int gridUniquePaths(int i, int j)
{

    if(i==0 && j==0)
    {
        return 1;
        // Because here we have already reached (0,0) so we have one way already found for it i.e reaching (0,0) from (m,n);
    }

    if(i<0 || j<0)
    {
        return 0;
        // Because here we have crossed the boundary of the grid
    }

    int left = gridUniquePaths(i, j-1);
    int up = gridUniquePaths(i-1, j);

    return left+up;


}

int main()
{
    int m = 3;
    int n = 7;  

    cout<<gridUniquePaths(m-1,n-1);


}