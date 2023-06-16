//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    long long pairAndSum(int N, long long Arr[]) {
       long long ans=0;    
       for(int i=0;i<32;i++){
           long long cnt=0;
           long long mask = 1<<i;
           for(int j=0;j<N;j++){
               if(mask&Arr[j]) cnt++;
           }
           long long k = cnt*(cnt-1)/2;
           ans+= (mask*k);
       }
       return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        long long Arr[N];
        for (int i = 0; i < N; i++) {
            cin >> Arr[i];
        }
        Solution ob;
        cout << ob.pairAndSum(N, Arr) << endl;
    }
    return 0;
}
// } Driver Code Ends