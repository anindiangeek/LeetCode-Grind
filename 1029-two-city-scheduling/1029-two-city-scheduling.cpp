class Solution {
        public:
    vector<vector<vector<int>>> dp;
    int hat(vector<vector<int>>& cost,int a,int b,int index)
    {
        if (a==0 &&  b==0)  return 0;
        if (dp[a][b][index]!=-1)  return dp[a][b][index];
        if (a==0)
        {
            int ans=0;
            for (int i=index;i<cost.size();i++)  ans+=cost[i][1];
            return dp[a][b][index]= ans;
        }
        if (b==0)
        {
            int ans=0;
            for (int i=index;i<cost.size();i++)  ans+=cost[i][0];
            return dp[a][b][index]= ans; 
        }
        
    return dp[a][b][index]= min(hat(cost,a-1,b,index+1)+cost[index][0],hat(cost,a,b-1,index+1)+cost[index][1]);
        
        
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        int n= costs.size()/2;
        dp.resize(n+1,vector<vector<int>>(n+1,vector<int>(2*(n+1),-1)));
        
        return hat(costs,n,n,0);
        
    }
};