class Solution {
public:
    int search(vector<int>& A, int target) {
        int low{0},high{(int)A.size()-1},mid=low+(high-low)/2;
        while(low <= high)
        {
            mid = low + (high - low) / 2;
            if(target==A[mid]) return mid;
            
            // numbers are rotated and the mid is in left part
            if(A[mid]>A[high])
            {
                if(target < A[mid] && target >= A[low])
                    high=mid-1;
                else low=mid+1;
            }
            // numbers are rotated and is present on right part.
            else if(A[mid]<A[low])
            {
                if(target > A[mid] && target <= A[high])
                    low=mid+1;
                else high=mid-1;
            }
            else //regular binary search
            {
                if(target < A[mid]) high=mid-1;
                else low=mid+1;
            }
        }
        return -1;
    }
};