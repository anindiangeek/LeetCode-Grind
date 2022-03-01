class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> v(n+1,0);
        for(int i=0;i<=n;i++)
        {
            int p=i,ans=0;
            while(p)
            {
               if(p%2==1) ans++;
               p/=2;
            }
            v[i]=ans;
        }
        return v;
    }
};