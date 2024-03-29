//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++) dp[i][0] = M[i][0];
        
        for(int j=1;j<m;j++){
            for(int i=0;i<n;i++){
                int left=0,dl=0,dr=0;
                if(i-1>=0 && j-1>=0) dl = dp[i-1][j-1];
                if(i>=0 && j-1>=0) left = dp[i][j-1];
                if(i+1<n && j-1>=0) dr = dp[i+1][j-1];
                int max_value = max({left,dr,dl});
                dp[i][j] = M[i][j] + max_value;
            }
        }
        int maxi = INT_MIN;
        
        for(int i=0;i<n;i++) maxi = max(maxi,dp[i][m-1]);
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends