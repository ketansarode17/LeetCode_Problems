//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
    private:
    vector<pair<int,int>>move=
    {
        {1,0},{-1,0},{0,1},{0,-1}
    };
public:
    int minIteration(int n,int m, int x, int y){    
        // code here
        int iter=0;
        queue<pair<int,int>>q;
        int xmove[4]={0,0,1,-1};
        int ymove[4]={1,-1,0,0};
        q.push({x-1,y-1});
        vector<vector<int>>vis(n,vector<int>(m));
        vis[x-1][y-1]=true;
        while(!q.empty())
        {
            int n1=q.size();
            iter++;
            for(int i=0;i<n1;i++)
            {
                for(auto it:move)
                {
                    int x1=it.first+q.front().first,y1=it.second+q.front().second;
                    if(x1>=0&&x1<n&&y1>=0&&y1<m&&!vis[x1][y1])
                    {
                        vis[x1][y1]=1;
                        q.push({x1,y1});
                    }
                }
                q.pop();
            }
        }
        return --iter;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends