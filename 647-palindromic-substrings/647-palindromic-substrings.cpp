class Solution {
public:
    int countSubstrings(string s) {
        
        int n=s.size();
        if(n==1) return 1;
        
        int c=0;
        
        for(int i=0; i<n; i++) {
            /*for odd pallindromes they start with same index
			and check by adding digits from both sides*/
            
            int l=i , r=i;
            while(l>=0 && r<n) {
              
                if(s[l]==s[r])  
                    c++;
                else 
					break; //we only have to check for the digits added because initially it's already a pallindrome 
                l--;
                r++;
                
            }
            /*for even pallindromes we start from two digits and then we
			move from both direction and check for pallindromes*/
            l=i; r=i+1;
            while(l>=0 && r<n) {
              
                if(s[l]==s[r])  
                    c++;
                else break;
                l--;
                r++;  
            }
        }
        return c;
    }
};