//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    private:
    vector<pair<int,int>>movements=
    {
      {0,1},{0,-1},{1,0},{-1,0}  
    };
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int m=grid.size(),n=grid[0].size();
	    vector<vector<int>>ans(m,vector<int>(n,0));
	    vector<vector<bool>>isOne(m,vector<bool>(n,false));
	    queue<pair<int,pair<int,int>>>q;
	    for(int i=0;i<m;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(grid[i][j])
	            {
	                q.push({0,{i,j}});
	                isOne[i][j]=true;
	            }
	        }
	    }
	    while(!q.empty())
	    {
	        int steps=q.front().first;
	        int i=q.front().second.first;
	        int j=q.front().second.second;
	        q.pop();
	        for(auto it:movements)
	        {
	            int x=it.first+i,y=it.second+j;
	            if(x>=0&&x<m&&y>=0&&y<n)
	            {
	                if(!isOne[x][y]&&!grid[x][y])
	                {
	                    isOne[x][y]=true;
	                    ans[x][y]=steps+1;
	                    q.push({steps+1,{x,y}});
	                }
	            }
	        }
	    }
	    return ans;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends