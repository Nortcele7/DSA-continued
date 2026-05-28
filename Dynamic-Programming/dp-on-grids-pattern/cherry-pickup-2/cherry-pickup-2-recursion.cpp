#include<iostream>
#include<vector>
using namespace std;

int cherryPickup2(int i, int j1, int j2, vector<vector<int>> arr)
{

    if(j1<0 || j1>=arr[0].size() || j2<0 || j2>=arr[0].size())
    {
        return -1e8;
    }

    if(i==arr.size()-1)
    {
        // We should select the cell only once;
        if(j1==j2)
        {
            return arr[i][j1];
        }

        else
        {
            return arr[i][j1]+arr[i][j2];
        }
    }

    // Now when Alice moves in down Bob can move down, leftd, rightd. So, we have 9 combos
    // In this 9 combos we always move to the next row so i=>i+1
    // So we will do loop for change in j1 and j2 
    // j1=>j1-1, j1, j1+1
    // j2=>j2-1, j2, j2+1
    
    int max_val = -1e8;

    for(int dj1=-1; dj1<=1; dj1++)
    {
        for(int dj2=-1; dj2<=1; dj2++)
        {
            if(j1==j2)
            {
                max_val = max(max_val, arr[i][j1] + cherryPickup2(i+1, j1+dj1, j2+dj2, arr));
            }
            else
            {
                max_val = max(max_val, arr[i][j1] + arr[i][j2] + cherryPickup2(i+1, j1+dj1, j2+dj2, arr));
            }
        }
    }

    return max_val;

}

int main()
{
    vector<vector<int>> arr = {{3,1,1},{2,5,1},{1,5,5},{2,1,1}};

    int n = arr.size();
    int m = arr[0].size();

    cout<< cherryPickup2(0, 0, m-1, arr);





}