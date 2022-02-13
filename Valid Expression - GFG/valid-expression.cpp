// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
bool valid(string str);
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string str;
        getline(cin,str);
        cout<<valid(str)<<endl;
    }
    return 0;
}// } Driver Code Ends


bool valid(string s)
{
    stack<char> stk;
    for(char c : s)
    {
        // if it's a opening bracket
        if(c=='[' or c == '{' or c=='(')
            stk.push(c);
            
        else if(c==']' or c=='}' or c==')')
        {
            if(stk.empty())
                return false;
            else if ((c==')' && stk.top()=='(') or (c==']' && stk.top()=='[') or (c=='}' && stk.top()=='{'))
                stk.pop();
        } 
    }
    
    return stk.empty() ? true : false;
}