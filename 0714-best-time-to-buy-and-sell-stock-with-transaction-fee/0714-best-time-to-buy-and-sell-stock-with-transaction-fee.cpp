class Solution {
public:
    int n;
    int dp[50001][2];
    int solve(int i,int buy,vector<int> &prices,int fee){
        if(i==n) return 0;
        int profit=0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy==1){
            int consider = solve(i+1,0,prices,fee) - prices[i];
            int notConsider = solve(i+1,1,prices,fee);
            profit=max({profit,consider,notConsider});
        }
        else{
           int consider = solve(i+1,1,prices,fee) + prices[i] - fee;
           int notConsider = solve(i+1,0,prices,fee); 
            profit=max({profit,consider,notConsider});
        }
        return dp[i][buy]=profit;
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        n = prices.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,1,prices,fee);
    }
};