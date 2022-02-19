// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
        unordered_map<char,int>m;
        queue<char>q;
		string FirstNonRepeating(string A){
		   string answer="";
		   for(int i=0;i<A.length();i++)
		   {
	            q.push(A[i]);
	            
	            m[A[i]]++;
	            
	            while(!q.empty())
	            {
	                if(m[q.front()]>1)
	                    q.pop();
	               else
	               {
	                 answer.push_back(q.front());
	                 break;
	               }
	            }
	            if(q.empty())
	                answer+="#";
		   }
		   return answer;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends