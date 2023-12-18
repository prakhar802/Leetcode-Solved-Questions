//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string smallestNumber(int S, int D){
       string s="";
       bool flag = true;
       for(int i=1;i<=D;i++){
           int r = D-i;
           int m = r*9;
           if(S-m>9) return "-1";
           if(S-m<=0 && flag){
               s += 1+'0';
               S-=1;
               flag=false;
           }
           else if(S-m<=0){
               s += '0';
               S-=0;
           }else{
               s += (S-m) + '0';
               S-= (S-m);
           }
       }
       return s;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends