// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
     // nearest smaller element to right
    /* Array of Indices */
    vector<int> Right(long long arr[], int n)
    {
        vector<int> v(n);
        // {value, index}
        stack<pair<long long, int>> s;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && s.top().first >= arr[i])
                s.pop();

            v[i] = s.empty() ? n : s.top().second;
            s.push({arr[i], i});
        }
        return v;
    }
    // nearest smaller element to left
    /* Array of Indices */
    vector<int> Left(long long arr[], int n)
    {
        vector<int> v(n);
        // {value, index}
        stack<pair<long long, int>> s;

        for (int i =0; i < n; i++)
        {
            while (!s.empty() && s.top().first >= arr[i])
                s.pop();

            v[i] = s.empty() ? -1 : s.top().second;
            s.push({arr[i], i});
        }
        return v;
    }

    long long getMaxArea(long long arr[], int n)
    {
        vector<int> NSL = Left(arr, n);
        vector<int> NSR = Right(arr, n);

        long long answer = INT_MIN;

        for (int i = 0; i < n; i++)
        { // height * width
            long long area = arr[i] * (NSR[i] - NSL[i] - 1);
            answer = max(answer, area);
        }

        return answer;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends