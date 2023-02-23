//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    private:
    int mod=1000000007;
    vector<vector<bool>>vis;
    vector<vector<int>>dp;
    vector<pair<int,int>>movements=
    {
        {0,1},{1,0}
    };
    int calci(int i,int j,int n,int m,vector<vector<int>>&grid)
    {
        if(i==n-1&&j==m-1)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        vis[i][j]=1;
        int ans=0;
        for(auto it:movements)
        {
            int x=i+it.first,y=it.second+j;
            if(x>=0&&x<n&&y>=0&&y<m&&grid[x][y]&&!vis[x][y])
            {
                ans+=calci(x,y,n,m,grid)%mod;
            }
        }
        vis[i][j]=0;
        return dp[i][j]=ans%mod;
    }
  public:
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        // code here
        if(!grid[0][0])return 0;
        vis.resize(n,vector<bool>(m,0));
        dp.resize(n,vector<int>(m,-1));
        return calci(0,0,n,m,grid);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends