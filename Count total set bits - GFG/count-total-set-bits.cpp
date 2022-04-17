// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
         n = n + 1;
        int CurrentSection{2}; // E D C B A

        // we already know the answer of A is n/2.

        int SetBits = n / 2;

        while (CurrentSection <= n)
        {
            // total number of pairs of 0 & 1 in this section.
            int Pairs = n / CurrentSection;

            SetBits += (Pairs / 2) * CurrentSection; // set pairs * power of 2.

            SetBits += (Pairs & 1) ? (n % CurrentSection) : 0; // if there were odd pairs

            CurrentSection <<= 1; // changing section. i.e multiplying it by 2^1.
        }

        return SetBits;
    }
};


// { Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}
  // } Driver Code Ends