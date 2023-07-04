//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	   int tx = TargetPos[0] - 1; int ty = TargetPos[1] - 1;
	   int x1 = KnightPos[0] - 1; int y1 = KnightPos[1] - 1;
	   if(tx==x1 && ty==y1) return 0;
	   int ans=0;
	   queue<pair<int,int>>q;
	   q.push({x1,y1});
	   int dx[] = {1,1,-1,-1,2,-2,2,-2};
	   int dy[] = {2,-2,2,-2,1,1,-1,-1};
	   vector<vector<int>>vis(N,vector<int>(N,0));
	   vis[x1][y1]=1;
	   while(!q.empty()){
	     int size = q.size();
	     ans++;
	     while(size--){
	       auto p = q.front();
	       int x = p.first;
	       int y = p.second;
	       q.pop();
	       for(int k=0;k<8;k++){
	           int r  = x + dx[k];
	           int c = y + dy[k];
	           if(r>=0 && r<N && c>=0 && c<N && !vis[r][c]){
	               vis[r][c]=1;
	               if(r==tx && c==ty) return ans;
	               q.push({r,c});
	           }
	       }
	     }
	   }
	   return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends