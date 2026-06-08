#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;

vector<int> findNGE(vector<int>& arr)
{
    int n = arr.size();

    stack<int> st;

    vector<int> nge(n);

    for(int i=n-1; i>=0; i--)
    {
        while(!st.empty() && arr[st.top()]<=arr[i])
        {
            st.pop();
        }

        if(st.empty())
        {
            nge[i]= n;
        }

        else
        {
            nge[i] = st.top();
        }

        st.push(i);

    }

    return nge;

}

vector<int> findPGE(vector<int>& arr)
{
    int n = arr.size();

    stack<int> st;

    vector<int> pge(n);

    for(int i=0; i<n; i++)
    {
        while(!st.empty() && arr[st.top()]<arr[i])
        {
            st.pop();
        }

        if(st.empty())
        {
            pge[i] = -1;
        }

        else
        {
            pge[i] = st.top();
        }

        st.push(i);

    }

    return pge;

}





int sum(vector<int>& arr)
{

    int mod = (int)(1e9 + 7);

    int total = 0;

    int n = arr.size();

    vector<int> pse = findPGE(arr);
    vector<int> nse = findNGE(arr);

    for(int i=0; i<n; i++)
    {
        int left = i - pse[i];
        int right = nse[i] - i;

        total = total+(right*left*arr[i]);

    }

    return total;


}



int main()
{

    vector<int> arr = {1,2,3};

    cout<<sum(arr);


}

