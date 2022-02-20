// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        vector<int> answer((int)n-k+1,INT_MAX);
        int start{0}, end = {start + k - 1};
        deque<int> q;
        for(int i=0;i<n;i++)
        {
            while(!q.empty() && q.front()<=i-k)
                q.pop_front();
                
            while(!q.empty() && arr[q.back()]<arr[i])
                q.pop_back();
                
            q.push_back(i);
            
            if(i-k+1>=0)
                answer[i-k+1]=arr[q.front()];
        }
        return answer;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}  // } Driver Code Ends