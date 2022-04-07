// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        if(!nums.size()) return {};
        int curr=nums[0],prev=0;
        for(int i=1;i<nums.size();i++)
            curr^=nums[i];
        
        int x=0,y=0;
        int set_bit_number=curr & ~(curr-1);
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] & set_bit_number)
               x^=nums[i];
             else
                y^=nums[i];
        }
        return {min(x,y),max(x,y)};
    }
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}  // } Driver Code Ends