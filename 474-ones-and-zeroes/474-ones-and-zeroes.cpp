class Solution {
public:
    vector<vector<int>>g;
    int dp[601][101][101];
    int solve(int m,int n,int ind){
        if(ind>=g.size() || (m<=0 && n<=0)) return 0;
        if(dp[ind][m][n]!=-1) return dp[ind][m][n];
        if(g[ind][0]>m || g[ind][1]>n) return dp[ind][m][n]=solve(m,n,ind+1);
        return dp[ind][m][n]=max(1+solve(m-g[ind][0],n-g[ind][1],ind+1),solve(m,n,ind+1));
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        for(auto&i:strs){
            int o=0,z=0;
            for(auto&j:i){
                if(j=='0')z++;
                else o++;
            }
            g.push_back({z,o});
        }
        memset(dp,-1,sizeof(dp));
        return solve(m,n,0);
    }
};
