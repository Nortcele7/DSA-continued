#include<iostream>
#include<vector>
using namespace std;

int pascalsTriangle(int i, int j)
{
    if(j==0)
    {
        return 1;
    }
    if(j==i)
    {
        return 1;
    }

    return pascalsTriangle(i-1, j-1)+pascalsTriangle(i-1, j);
}

int main()
{

    int numRows = 5;
    vector<vector<int>> arr(numRows);

    for(int i=0; i<numRows; i++){
        for(int j=0; j<=i; j++)
        {
            arr[i].push_back(pascalsTriangle(i, j));
        }
    }

    for(int i=0; i<arr.size(); i++)
    {
        for(int j=0; j<arr[i].size(); j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}