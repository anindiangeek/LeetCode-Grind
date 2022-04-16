// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long divide(long long dividend, long long divisor) 
    {
         if (dividend == divisor)
            return 1ll;

        // if any of the number is negative or then we will have a negative answer.
        // checking if they have same sign then they will not have signed answer.
        bool NotSign = (dividend < 0) == (divisor < 0);

        dividend = abs(dividend);
        divisor = abs(divisor);

        long long quotient{0};

        while (dividend >= divisor)
        {
            long long temp{0};
            while (dividend > (divisor << temp + 1))
                temp++;
            quotient += (1 << temp);
            dividend -= (divisor << temp);
        }
        
        return !NotSign ? -1ll * quotient : quotient;
    }
};

// { Driver Code Starts.
int main() {
	int t;
	cin >> t;

	while (t--)
	{

		long long a, b;
		cin >> a >> b;
		
		Solution ob;
		cout << ob.divide(a, b) << "\n";
	}

	return 0;
}
  // } Driver Code Ends