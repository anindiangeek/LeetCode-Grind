class Solution {
public:
    int longestValidParentheses(string x) {
        int answer = 0;
        int Left{0},Right{0};
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