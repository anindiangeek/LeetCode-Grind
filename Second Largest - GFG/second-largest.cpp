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
	   int max=0,pre=0;
	   for(int i=0;i<n;i++){
	       if(arr[i]>max){
	            pre=max;
	            max=arr[i];
	       }
	       else if (arr[i]>pre && arr[i]<max){
	           pre=arr[i];
	       }
	}
	if (pre==0 or max==pre){
	    return -1;
	}else{
	return pre;
	    
	}
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