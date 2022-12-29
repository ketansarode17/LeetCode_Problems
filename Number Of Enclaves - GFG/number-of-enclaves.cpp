//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
    vector<pair<int,int>>movements=
    {
        {0,1},{0,-1},{1,0},{-1,0}
    };
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int m=grid.size(),n=grid[0].size();
        queue<pair<int,int>>q;
        bool vis[m][n];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((i==0||j==0||j==n-1||i==m-1)&&grid[i][j])
                {
                    vis[i][j]=true;
                    q.push({i,j});
                }
                else vis[i][j]=false;
            }
        }
        int ans=0;
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            for(auto move:movements)
            {
                int x=move.first+it.first,y=it.second+move.second;
                if(x>=0&&x<m&&y>=0&&y<n)
                {
                    if(!vis[x][y]&&grid[x][y])
                    {
                        vis[x][y]=true;
                        q.push({x,y});
                    }
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]&&!vis[i][j])ans++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends