//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    long long cnt_array(int n,vector<int>a,long long target)
    {
        long long i=0,j=0;
        long long ans=0,sum=0;
        while(j<n){
            sum+=a[j];
            if(sum>target){
                while(sum>target){
                    sum-=a[i++];
                   // i++;
                }
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
    
    long long countSubarray(int N,vector<int> A,long long L,long long R) {
       return cnt_array(N,A,R)-cnt_array(N,A,L-1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        long long L,R;
        cin>>N>>L>>R;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution obj;
        auto ans = obj.countSubarray(N,A,L,R);
        cout<<ans<<endl;
    }
}  
// } Driver Code Ends