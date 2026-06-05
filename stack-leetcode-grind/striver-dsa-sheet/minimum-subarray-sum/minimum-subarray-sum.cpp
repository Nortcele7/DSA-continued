#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;

vector<int> findNSE(vector<int>& arr)
{
    int n = arr.size();

    stack<int> st;

    vector<int> nse(n);

    for(int i=n-1; i>=0; i--)
    {
        while(!st.empty() && arr[st.top()]>=arr[i])
        {
            st.pop();
        }

        if(st.empty())
        {
            nse[i] = n;
        }

        else
        {
            nse[i] = st.top();
        }

        st.push(i);

    }

    return nse;

}

vector<int> findPSE(vector<int>& arr)
{
    int n = arr.size();

    stack<int> st;

    vector<int> pse(n);

    for(int i=0; i<n; i++)
    {
        while(!st.empty() && arr[st.top()]>arr[i])
        {
            st.pop();
        }

        if(st.empty())
        {
            pse[i] = -1;
        }

        else
        {
            pse[i] = st.top();
        }

        st.push(i);

    }

    return pse;

}





int sum(vector<int>& arr)
{

    int mod = (int)(1e9 + 7);

    int total = 0;

    int n = arr.size();

    vector<int> pse = findPSE(arr);
    vector<int> nse = findNSE(arr);

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

    vector<int> arr = {3,1,2,4};

    cout<<sum(arr);


}

