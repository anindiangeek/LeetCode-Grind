class Solution {
public:
    int numRescueBoats(vector<int>&a, int k) {
        int n=a.size();
        sort(a.begin(),a.end());
        int i=0,j=n-1;
        int count=0;
        while(i<j)
        {
            if((a[i]+a[j])>k)
            {count++;j--;}
            else {
                i++;j--;
                count++;
            }
        }
        if(i==j) count++;
        return count; 
    }
};