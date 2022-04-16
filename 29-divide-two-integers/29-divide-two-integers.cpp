class Solution {
public:
    int divide(int dividendd, int ddivisor) 
    {
        if(dividendd==ddivisor) return 1;
        if(ddivisor==1) return dividendd;
        
      
        bool Notsign = (dividendd<0) == (ddivisor<0);
          
        if((dividendd == -2147483648 or dividendd == INT_MAX) and (ddivisor==1 or ddivisor ==-1))
            return Notsign? INT_MAX :-1*INT_MAX;
        
        unsigned int dividend = abs(dividendd);
        unsigned int divisor = abs(ddivisor);
        
        unsigned int quotient{0};
        while(dividend >= divisor)
        {
            short NearPower{0};
            while( dividend > (divisor << (NearPower+1)))
                NearPower++;
            quotient +=(1<<NearPower);
            dividend =dividend -(divisor<<NearPower);
        }
        return !Notsign? -1 * quotient : quotient;
        
    }
};