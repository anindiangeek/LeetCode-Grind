// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
     int LeftSearch(int A[], int l, int h, int key)
    {
        int low = l, high = h, mid = l + (h - l) / 2;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (key == A[mid])
                return mid;
            if (key < A[mid])
                high = mid - 1;
            else if (key > A[mid])
                low = mid + 1;
        }
        return -1;
    }
    int search(int A[], int l, int h, int key)
    {
        // we need to find the intersection point and then search in two different parts.
        // getting the intersection point.
        int low = l, high = h, mid = l + (h - l) / 2;
        while (low < high)
        {
            mid = low + (high - low) / 2;
            if (A[mid] > A[low] && A[mid] > A[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
        // BS from l-->high && low--->h
        int a = LeftSearch(A, l, high, key);
        int b = LeftSearch(A, low, h, key);
        if (a < 0)
            return b;
        else
            return a;
    }
};

// { Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}  // } Driver Code Ends