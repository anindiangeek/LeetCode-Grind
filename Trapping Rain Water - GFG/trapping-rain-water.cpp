// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n)
    {
        /*
            for any index i the water stroed in it is 
            
            ws = (min(maxofleft,maxofright) - arr[i]);
        */
        // using prefix sums and suffix sums
        int MaxofLeft[n]={0}; 
        int MaxofRight[n]={0};
        MaxofLeft[0]=arr[0];
        MaxofRight[n-1]=arr[n-1];
        
        for(int i=1;i<n;++i)
            MaxofLeft[i]=max(MaxofLeft[i-1],arr[i]);
        
        for(int i=n-2;i>=0;--i)
            MaxofRight[i]=max(MaxofRight[i+1],arr[i]);
        
        unsigned long long answer=0;
        for(int i=0; i<n ; i++)
        {
            answer += (((min(MaxofLeft[i],MaxofRight[i]) - arr[i]) < 0)?0:min(MaxofLeft[i],MaxofRight[i]) - arr[i]);
        }
        return answer;
        
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends