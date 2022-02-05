// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
         int low = 0, mid = 0, high = n - 1,i=0;
        // we sort the array in single scan i.e o(n);
        while(mid<=high)
        {
            switch (a[i])
            {
            case 0:
                swap(a[low++], a[i]);
            case 1:
                mid++;
                break;
            case 2:
                swap(a[high--],a[i--]);
                break;
            }
            i++;
        }
    }
    
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

  // } Driver Code Ends