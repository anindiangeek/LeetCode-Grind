// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxLength(string x){
        int answer = 0;
        int Left{0},Right{0};
        //left represents --> ( & right --> )
        for(char c : x)
        {
            if(c=='(') Left++;
            else Right++;
            
            if(Left == Right) answer=max(answer,Left*2);
            else if(Right>Left) Left = Right = 0;
        }
        Left=Right=0;
        reverse(x.begin(),x.end());
        
        for(char c : x)
        {
            if(c=='(') Right++;
            else Left++;
            
            if(Left == Right) answer=max(answer,Left*2);
            else if(Right>Left) Left = Right = 0;
        }
        
        return answer;
  
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.maxLength(S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends