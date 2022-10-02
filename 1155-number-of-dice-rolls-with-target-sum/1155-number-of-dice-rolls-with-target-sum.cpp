class Solution {
public:
    int mod=1e9+7;
	int numRollsToTarget(int n, int k, int tar) {
		vector<int>prev(tar+1,0),curr(tar+1,0);
		prev[0]=1;
		for(int i=n-1;i>=0;i--){
			for(int t=0;t<=tar;t++){
				long long p=0;
				for(int j=1;j<=k;j++){
					if(t>=j) p+=prev[t-j]%mod;
				}
				curr[t]=p%mod;
			}
			prev=curr;
		}
		return prev[tar];
	}
};