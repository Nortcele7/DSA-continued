#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int houseRobber(vector<int> arr)
{
    int n = arr.size();

    if(n==0)
    {
        return 0;
    }

    if(n==1)
    {
        return arr[0];
    }

    int curr;
    int prev2 = arr[0];
    int prev = max(arr[1], arr[0]);
    int pick;
    int not_pick;

    for(int i=2; i<n; i++)
    {
        pick = arr[i]+prev2;
        not_pick = 0+prev;
        curr = max(pick, not_pick);
        prev2 = prev;
        prev = curr;

    }

    return prev;

}

int houseRobber2(vector<int> arr)
{
   vector<int> temp1, temp2;
   
   int n = arr.size();

   for(int i=0; i<n; i++)
   {
    if(i!=n-1)
    {
        temp1.push_back(arr[i]);
    }
    if(i!=0)
    {
        temp2.push_back(arr[i]);
    }
   }

   int ans1 = houseRobber(temp1);
   int ans2 = houseRobber(temp2);

   return max(ans1, ans2);
   
}

int main()
{
    vector<int> arr = {2,3,2};

    cout<<houseRobber2(arr);



}