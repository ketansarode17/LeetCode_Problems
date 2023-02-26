//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int check(int node,vector<int>&vis,vector<int>&temp,vector<vector<int>>&graph)
  {
      //cout<<node<<endl;
      temp.push_back(node);
      vis[node]=1;
      int cnt=1;
      for(auto it:graph[node])
      {
          if(!vis[it])
          {
              cnt+=check(it,vis,temp,graph);
          }
      }
      return cnt;
  }
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
        // code here
        int ans=0;
        vector<int>vis(V+1,0);
        for(int i=1;i<=V;i++)
        {
            if(!vis[i])
            {
                vector<int>temp;
                int cnt=check(i,vis,temp,adj),f=1;
                //cout<<cnt<<endl;
                for(auto it:temp)
                {
                    if(adj[it].size()!=cnt-1)
                    {
                        f=0;break;
                    }
                }
                if(f)ans++;
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
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends