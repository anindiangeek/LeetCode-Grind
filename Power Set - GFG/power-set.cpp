// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		   vector<string> answer;
		   int n=s.length();
		   for(int i=1 ;i<(1<<n); i++)
		   {
		       string sub="";
		       for(int j=0;j<n;j++)
		           if(i & 1<<j) sub += s[j];
		       answer.push_back(sub);
		   }
		   sort(answer.begin(),answer.end());
		   return answer;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends