//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long countKdivPairs(int nums[], int n, int k)
    {
       unordered_map<int,int>mp;
       for(int i=0;i<n;i++){
           nums[i]%=k;
       }
       long long ans=0;
       for(int i=0;i<n;i++){
           int a = k - nums[i];
           if(a==k) a=0;
           if(mp.find(a)!=mp.end()) ans+=mp[a];
           mp[nums[i]]++;
       }
       return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int k;
		cin >> k;

        Solution ob;
		cout << ob. countKdivPairs(a, n , k) << "\n";



	}


	return 0;
}

// } Driver Code Ends