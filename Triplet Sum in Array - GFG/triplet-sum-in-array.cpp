// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
     bool TwoSum(int A[], int n, int Y,int j)
    {
        unordered_set<int> Hash;
        for (int i = j; i < n; i++)
        {
            if (Hash.find(Y - A[i]) != Hash.end())
                return true;
            Hash.insert(A[i]);
        }
        return false;
    }

    bool find3Numbers(int A[], int n, int X)
    {
        for (int i = 0; i <= n-3; i++)
        {
            int Y = X - A[i];
            // function call to Two sum for Y;
            if (TwoSum(A, n, Y,i))
                return true;
        }
        return false;
    }

};

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}
  // } Driver Code Ends