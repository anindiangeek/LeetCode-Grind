// { Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
         int Count = 0; // count of elements less than or equal to k
        for (int i = 0; i < n; i++)
            if (arr[i] <= k)
                Count++;

        // Calculating the elements in the current "count" sized window which are not suppossed to be there.
        int answer = 0, bad = 0;
        for (int i = 0; i < Count; i++)
            if (arr[i] > k)
                bad++;

        answer = bad;

        // using slilding window technique;
        for (int i = 0, j = Count; j < n; i++, j++)
        {
            // if the current element that left the window was bad element
            if (arr[i] > k)
                --bad;

            if (arr[j] > k)
                ++bad;

            answer = min(answer, bad);
        }
        return answer;
    }
};


// { Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}
  // } Driver Code Ends