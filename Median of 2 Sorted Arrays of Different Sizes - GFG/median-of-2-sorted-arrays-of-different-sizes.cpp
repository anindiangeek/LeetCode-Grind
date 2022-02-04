// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int LengthFirst = nums1.size(), LengthSecond = nums2.size();

        if (LengthFirst > LengthSecond)
            return MedianOfArrays(nums2, nums1);

        if (LengthFirst + LengthSecond == 1)
            return (double)(nums1.size() > nums2.size()) ? nums1[0] : nums2[0];

        int low = 0, high = LengthFirst;

        while (low <= high)
        {
            int FirstPartitionIndex = (low + high) / 2;

            int SecondPartitionIndex = (LengthFirst + LengthSecond + 1) / 2 - FirstPartitionIndex;
            // i+j (size of left part) = m-i + n-j (size of right part)

            // left side calulations
            int MaxLeftFirst = (FirstPartitionIndex == 0) ? INT_MIN : nums1[FirstPartitionIndex - 1];
            int MaxLeftSecond = (SecondPartitionIndex == 0) ? INT_MIN : nums2[SecondPartitionIndex - 1];

            // right side calulations
            int MinRightFirst = (FirstPartitionIndex == LengthFirst) ? INT_MAX : nums1[FirstPartitionIndex];
            int MinRightSecond = (SecondPartitionIndex == LengthSecond) ? INT_MAX : nums2[SecondPartitionIndex];

            if (MaxLeftFirst <= MinRightSecond and MaxLeftSecond <= MinRightFirst)
            {
                if ((LengthFirst + LengthSecond) & 1)
                    return (double)max(MaxLeftFirst, MaxLeftSecond);

                return ((double)max(MaxLeftFirst, MaxLeftSecond) + min(MinRightFirst, MinRightSecond)) / 2;
            }
            else if (MaxLeftFirst > MinRightSecond)
                high = FirstPartitionIndex - 1;
            else
                low = FirstPartitionIndex + 1;
        }
        return -1;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends