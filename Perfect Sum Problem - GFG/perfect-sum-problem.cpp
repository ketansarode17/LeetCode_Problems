//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define mod 1000000007 
class Solution{
private:
int helper(int arr[],int n,int rem,int ind,vector<vector<int>>&dp)
{
    if(rem<0)return 0;
    if(ind==n)
    {
        if(!rem)return 1;
        return 0;
    }
    if(dp[ind][rem]!=-1)return dp[ind][rem];
    int ans=helper(arr,n,rem-arr[ind],ind+1,dp)%mod;
    ans=(ans%mod+helper(arr,n,rem,ind+1,dp)%mod)%mod;
    return dp[ind][rem]=ans;
}
	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return helper(arr,n,sum,0,dp)%mod;
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends