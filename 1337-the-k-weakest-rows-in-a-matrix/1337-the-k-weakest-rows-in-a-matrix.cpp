class Solution {
public:
        static bool cmp(vector <int> a, vector <int> b){
        return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector <vector <int> > v;
        vector <int> ans;
        
        for(int i=0; i<mat.size(); i++){
            int cnt = 0;
            for(int j=0; j<mat[i].size(); j++){
                if(mat[i][j] == 1) cnt++;
            }
            v.push_back({cnt, i});
        }
        
        sort(v.begin(), v.end(), cmp);
        
        for(int i=0; i<k; i++) ans.push_back(v[i][1]);
        
        return ans; 
    }
};