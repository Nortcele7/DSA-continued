class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        
        vector<pair<int, int>> vp;
        
        int n = profit.size();
        
        int m = 0;
        
        for(int i=0; i<n; i++)
        {
            vp.push_back({profit[i], deadline[i]});
            m = max(m, deadline[i]);
        }
        
        sort(vp.rbegin(), vp.rend());
        
        vector<int> arr(m+1, -1);
        
        int totalProfit = 0;
        int totalJobs = 0;
        
        for(int i=0; i<n; i++)
        {
            int profit = vp[i].first;
            int deadline = vp[i].second;
            
            for(int j=deadline; j>0; j--)
            {
                if(arr[j]==-1)
                {
                    arr[j]=0;
                    totalProfit+=profit;
                    totalJobs++;
                    break;
                }
            }
        }
        
        return {totalJobs, totalProfit};
        
        
    }
};