//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void f(int x,int y,vector<vector<int>>&m, vector<string>&ans, string &s,vector<vector<int>>&vis){
       int n = m.size();
       if(x==n-1 && y==n-1){
           ans.push_back(s);
           return;
       }
       
       vis[x][y]=1;
       int dx[]={-1,1,0,0};
       int dy[]={0,0,-1,1};
       char dir[]={'U','D','L','R'};
       for(int k=0;k<4;k++){
           int r = x + dx[k];
           int c = y + dy[k];
           char direction=dir[k];
           if(r>=0 && r<n && c>=0 && c<n && !vis[r][c] && m[r][c]){
               s.push_back(direction);
               vis[r][c]=1;
               f(r,c,m,ans,s,vis);
               vis[r][c]=0;
               s.pop_back();
           }
       }
       vis[x][y]=0;
       return ;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
         if(m[0][0]==0 || m[n-1][n-1]==0){
          return {"-1"};
       }
       
       vector<string>ans;
       string s="";
       vector<vector<int>>vis(n,vector<int>(n,0));
       f(0,0,m,ans,s,vis);
       return ans;
    }
};


    
    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends