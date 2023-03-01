//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        vector<int> updateQuery(int N,int Q,vector<vector<int>> &U)
        {
            // code here
            unordered_map<int,vector<int>>add,rem;
            vector<int>ans(N);
            for(auto it:U)
            {
                add[it[0]-1].push_back(it[2]);
                rem[it[1]].push_back(it[2]);
            }
            vector<int>bits(17);
            for(int i=0;i<N;i++)
            {
                if(add.find(i)!=add.end())
                {
                    for(auto it:add[i])
                    {
                        int pos=0;
                        while(it)
                        {
                            if(it&1)bits[pos]++;
                            pos++;
                            it>>=1;
                        }
                    }
                }
                if(rem.find(i)!=rem.end())
                {
                    for(auto it:rem[i])
                    {
                        int pos=0;
                        while(it)
                        {
                            if(it&1)bits[pos]--;
                            pos++;
                            it>>=1;
                        }
                    }
                }
                int res=0;
                for(int i=0;i<17;i++)
                {
                    if(bits[i])res+=(1<<i);
                }
                ans[i]=res;
            }
            return ans;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        vector <vector <int>> u(q,vector <int>(3));
        for(int i=0;i<q;i++)
            cin>>u[i][0]>>u[i][1]>>u[i][2];
        Solution a;
        vector <int> ans=a.updateQuery(n,q,u);//<<endl;
        for(auto j:ans)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends