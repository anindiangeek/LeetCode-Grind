// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

//Function to generate binary numbers from 1 to N using a queue.
vector<string> generate(int N)
{
	vector<string> v;
    queue<string> q;
    
    q.push("1");
    while(N--)
    {
        string child1=q.front();
        v.push_back(child1);
        q.pop();
        string second_child=child1;
        
        child1+='0';
        q.push(child1);
        second_child +='1';
        q.push(second_child);
    }
    return v;
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends