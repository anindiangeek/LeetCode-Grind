// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
     bool TwoSum(int A[], int size, int TargetSum, int j)
    {
        int start = j, end = size - 1;
        while (start < end)
        {
            int CurrentSum = A[start] + A[end];
            if (CurrentSum == TargetSum)
                return true;
            else if (CurrentSum < TargetSum)
                ++start;
            else
                --end;
        }
        return false;
    }

    bool find3Numbers(int A[], int size, int X)
    {
        sort(A, A + size);
        for (int i = 0; i < size-3; i++)
        {
            int TargetSum = X - A[i];
            // function call to Two sum for Y;
            if (TwoSum(A, size, TargetSum, i + 1))
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