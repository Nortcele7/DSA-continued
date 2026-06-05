#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) 
{

    int i=0;
    int n = asteroids.size();

    stack<int> st;

    while(i<n)
    {

        if(asteroids[i]>=0)
        {
            st.push(asteroids[i]);
        }

        else
        {
            while(!st.empty() && st.top()>=0 && st.top()<abs(asteroids[i]))
            {
                st.pop();
            }
            if(!st.empty() && st.top()==abs(asteroids[i]))
            {
                st.pop();
            }
            else if(st.empty() || st.top()<0)
            {
                st.push(asteroids[i]);
            }
        }

        i++;

    }

    vector<int> arr(st.size());

    while(!st.empty())
    {
        arr.push_back(st.top());
        st.pop();
    }

    reverse(arr.begin(), arr.end());

    return arr;
        
}



int main()
{

    vector<int> asteroids = {4, 7, 1, 1, 2, -3, -7, 17, 15, -16};

    vector<int> arr = asteroidCollision(asteroids);

    for(int i=0; i<arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }

    
    


}

