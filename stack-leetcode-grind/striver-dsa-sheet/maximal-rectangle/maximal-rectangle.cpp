#include<iostream>
#include<vector>
#include<stack>
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
        while(!st.empty() && arr[st.top()]>=arr[i])
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

int largestRectangleinHistogram(vector<int>& arr)
{

    int n = arr.size();

    vector<int> nse = findNSE(arr);
    vector<int> pse = findPSE(arr);

    int height;
    int width;
    int area;
    int max_area = 0;

    for(int i=0; i<n; i++)
    {
        height = arr[i];
        width = nse[i] - pse[i] - 1;
        area = height * width;
        max_area = max(max_area, area);
    }

    return max_area;

}

int main()
{
    vector<vector<int>> mat = {{1,0,1,0,1},{1,0,1,1,1},{1,1,1,1,1},{1,0,0,1,0}};

    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> histogram_matrix(n, vector<int>(m));

    int sum = 0;

    for(int j=0; j<m; j++)
    {
        sum = 0;
        for(int i=0; i<n; i++)
        {
            if(mat[i][j]==0)
            {
                sum = 0;
            }
            else
            {
            sum += mat[i][j];
            }
            histogram_matrix[i][j] = sum;
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<histogram_matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    int max_area = 0;
    int area;

    for(int i=0; i<n; i++)
    {
        area = largestRectangleinHistogram(histogram_matrix[i]);
        max_area = max(max_area, area);
    }

    cout<<max_area;

}