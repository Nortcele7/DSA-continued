#include<iostream>
#include<vector>
using namespace std;
int main()
{

    vector<vector<int>> arr1 = {{1,2,3},{4,5,6},{7,8,9}};

    int n = arr1.size();
    int m = arr1[0].size();

    vector<vector<int>> arr2(n, vector<int>(n));

    int temp;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            arr2[j][n-i-1] = arr1[i][j];
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<arr2[i][j]<<" ";
        }
        cout<<endl;
    }
    

}