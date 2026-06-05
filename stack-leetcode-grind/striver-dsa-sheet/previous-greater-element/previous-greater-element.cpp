#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;



int main()
{

    vector<int> arr = {4, 12, 5, 3, 1, 2, 5, 3, 1, 2, 4, 6};

    int n1 = arr.size();

    vector<int> pge(n1, -1);

    stack<int> st;

    for(int i=0; i<n1; i++)
    {
        while(!st.empty() && st.top()<=arr[i])
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

        st.push(arr[i]);
    }

    for(int va: pge)
    {
        cout<<va<<" ";
    }
    


}

