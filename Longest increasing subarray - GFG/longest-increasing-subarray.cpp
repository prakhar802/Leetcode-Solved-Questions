//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    long int lenOfLongIncSubArr(long int arr[], long int n) {
        int len=1,maxi=1;
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1]){
                len++;
            }else{
                len=1;
            }
            maxi = max(maxi,len);
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long int n;
        cin >> n;
        long int arr[n], i;
        for (i = 0; i < n; i++) 
            cin >> arr[i];
        Solution obj;
        cout << obj.lenOfLongIncSubArr(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends