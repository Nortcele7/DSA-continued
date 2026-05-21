#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{

    vector<vector<int>> arr1 = {{1,2,3},{4,5,6},{7,8,9}};

    int n = arr1.size();

    // Transposing the matrix

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            swap(arr1[i][j], arr1[j][i]);
        }
    }

    for(vector<int> &row: arr1)
    {
        reverse(row.begin(), row.end());
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<arr1[i][j]<<" ";
        }
        cout<<endl;
    }

    
   
    

}