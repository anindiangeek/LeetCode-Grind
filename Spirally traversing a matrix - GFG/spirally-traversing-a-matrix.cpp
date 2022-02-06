// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<int> answer;
        int Left{0}, Right{(int)matrix[0].size() - 1}, Top{0}, Bottom{(int)matrix.size() - 1};

        while (Left <= Right and Top <= Bottom)
        {
            for (int i = Left; i <= Right; ++i)
                answer.push_back(matrix[Top][i]);
            ++Top;

            for (int i = Top; i <= Bottom; ++i)
                answer.push_back(matrix[i][Right]);
            --Right;

            if (Top > Bottom or Left > Right)
                break;

            for (int i = Right; i >= Left; --i)
                answer.push_back(matrix[Bottom][i]);
            --Bottom;

            for (int i = Bottom; i >= Top; --i)
                answer.push_back(matrix[i][Left]);
            ++Left;
        }
        return answer;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends