// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int findPosition(int N) {
        if (!(N && !(N & (N - 1)))) // refer check if the number is power of 2 question in Bit Manipulation.
			return -1;
		int count = 0;
		while (N)
		{
			N = N >> 1;
			count++;
		}
		return count;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}  // } Driver Code Ends