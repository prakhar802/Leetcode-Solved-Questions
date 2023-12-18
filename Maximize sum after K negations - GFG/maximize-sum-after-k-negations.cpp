//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        int neg=0;
        for(int i=0;i<n;i++){
            if(a[i]<0) neg++;
        }
        int mini = min(neg,k);
        long long sum=0;
        if(k>neg){
           k-=neg;
           k = k%2==1 ? 1 : 0; 
        }else k=0;
        
        sort(a,a+n);
        for(int i=0;i<n;i++){
            if(mini>0) {
                a[i] = -a[i];
                mini--;
            }
        }
        sort(a,a+n);
        if(k==1) a[0]=-a[0];
        
        sum = accumulate(a,a+n,0LL);
        return sum;
    }
};

//{ Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, k;
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.maximizeSum(a, n, k)<<endl;
     }
	
	return 0;
}
// } Driver Code Ends