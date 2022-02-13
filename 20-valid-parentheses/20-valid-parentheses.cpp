class Solution {
public:
    bool isValid(string s) {
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
            else
                return false;
        } 
    }
    
    return stk.empty() ? true : false;
    }
};