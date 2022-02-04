// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	bool fascinating(int n) {
	    string s=to_string(n);
	    s+=to_string(n*2);
	    s+=(to_string(n*3));
	    sort(s.begin(),s.end());
	    
	    for(int i=0;i<s.length();i++)
	        if(s[i]!=char(i+49))
	           return false;
	   return true;
	    
	    
	    
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.fascinating(n);
        if (ans) {
            cout << "Fascinating\n";
        } else {
            cout << "Not Fascinating\n";
        }
    }
    return 0;
}  // } Driver Code Ends