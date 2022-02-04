// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function returns the second
	// largest elements
    	int print2largest(int arr[], int n) {
	    int maxx=0,prev=0;
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i]>maxx)
	        {
	           prev=maxx;
	           maxx=arr[i];
	        }
	        if(arr[i]<maxx && arr[i]>prev)
	            prev=arr[i];
	    }
	    if(prev==0 or prev==maxx)
	        return -1;
	    return prev;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.print2largest(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends