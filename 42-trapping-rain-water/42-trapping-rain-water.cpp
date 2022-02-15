class Solution {
public:
    int trap(vector<int>& height) {
        // Two pointers approach
        
        int Left{0},Right=height.size()-1;
        int answer{0},Max_Left{0},Max_Right{0};
        
        while(Left<Right)
        {
            if(height[Left] < height[Right])
            {
                if(height[Left] >= Max_Left)
                    Max_Left=height[Left];
                else
                    answer+= (Max_Left-height[Left]);
                ++Left;
            }
            else if( height[Left] >= height[Right] )
            {
                if(height[Right] >= Max_Right)
                    Max_Right=height[Right];     
                else
                    answer += (Max_Right-height[Right]);
                Right--;
            }
        }
        return answer;
    }
};