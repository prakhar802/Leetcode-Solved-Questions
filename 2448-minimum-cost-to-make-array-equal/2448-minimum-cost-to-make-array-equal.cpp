class Solution {
public:
    int n ;
    long long findCost(vector<int>& nums,vector<int>&cost,long long mid){
         long long total=0;
         for(int i=0;i<n;i++){
             total+=(long long)abs(nums[i]-mid)*cost[i];
         } 
        return total;
    }
    
    long long minCost(vector<int>& nums, vector<int>& cost) {
        
         n = nums.size();
        long long s=*min_element(nums.begin(),nums.end());
        int e=*max_element(nums.begin(),nums.end());
        long long ans =1e9;
        while(s<=e){
            long long mid = s+(e-s)/2;
            long long cost1 = findCost(nums,cost,mid);
            long long cost2 = findCost(nums,cost,mid+1);
            if(cost1<cost2){
                e=mid-1;
            }else{
                s=mid+1;
            }
            ans=min(cost1,cost2);
        }
        return ans;
    }
};