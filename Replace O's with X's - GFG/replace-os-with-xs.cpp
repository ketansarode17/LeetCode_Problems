//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    private:
    vector<pair<int,int>>movements=
    {
        {0,1},{0,-1},{1,0},{-1,0}
    };
public:
    vector<vector<char>> fill(int m, int n, vector<vector<char>> mat)
    {
        // code here
        queue<pair<int,int>>q;
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((i==0||j==0||i==m-1||j==n-1)&&mat[i][j]=='O')
                {
                    q.push({i,j});
                    vis[i][j]=true;
                }
            }
        }
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            for(auto move:movements)
            {
                int x=it.first+move.first,y=move.second+it.second;
                if(x>=0&&x<m&&y>=0&&y<n)
                {
                    if(!vis[x][y]&&mat[x][y]=='O')
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
                if(mat[i][j]=='O'&&!vis[i][j])mat[i][j]='X';
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends