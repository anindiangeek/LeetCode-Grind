// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m)
    {
        sort(a.begin(), a.end());

        int Start = 0, End = m - 1;

        long long answer = INT64_MAX;

        /*
		Another way of implementing the same thing.

        for (int i = 0; i + m - 1 < n; i++)
            answer = min(a[i + m - 1] - a[i], answer);

        */

        while (End < n)
            answer = min(a[End++] - a[Start++], answer);

        return answer;
    }   
};

// { Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}  // } Driver Code Ends