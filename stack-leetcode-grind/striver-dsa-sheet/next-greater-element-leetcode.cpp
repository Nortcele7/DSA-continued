#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;



int main()
{

    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};

    int n1 = nums1.size();
    int n2 = nums2.size();

    stack<int> st;

    unordered_map<int,int> mp;

    for(int i=n2-1; i>=0; i--)
    {
        
        while(st.size()>0 && nums2[i]>st.top())
        {
            st.pop();
        }

        if(st.empty())
        {
            mp[nums2[i]]=-1;
        }

        else
        {
            mp[nums2[i]]=st.top();
        }

        st.push(nums2[i]);

    }

    vector<int> ans(n1);

    for(int i=0; i<n1; i++)
    {
        ans[i] = mp[nums1[i]];
    }

    for(int val: ans)
    {
        cout<<val<<" ";
    }
    


}

