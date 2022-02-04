// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> getMoreAndLess(int arr[], int n, int x) 
	{
	    int a, b;
        // Lower bound implementation using binary search.
        int low = 0, high = n - 1, ans = INT_MAX, mid = 0;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (arr[mid] >= x)
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        b = (ans == INT_MAX) ? 0 : n - ans;
        // Upper bound Implementation using binary search

        low = 0, high = n, ans = INT_MAX, mid = 0;
        while (low < high)
        {
            mid = low + (high - low) / 2;
            if (arr[mid] <= x)
            {
                ans = low;
                low = mid + 1;
            }
            else
                high = mid;
        }

        a = (ans == INT_MAX) ? 0 : low;
        return {a, b};
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMoreAndLess(arr, n, x);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
  // } Driver Code Ends