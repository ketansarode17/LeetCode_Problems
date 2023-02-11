//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int getMinimumDays(int n,string s, vector<int> &p) {
        // code here
        set<pair<int,int>>st;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
                st.insert({i,i+1});
                st.insert({i+1,i});
            }
        }
        if(!st.size())return 0;
        for(int i=0;i<n;i++)
        {
            if(st.count({p[i],p[i]+1})||st.count({p[i]+1,p[i]}))
            {
                st.erase({p[i],p[i]+1});
                st.erase({p[i]+1,p[i]});
            }
            if(p[i]!=0&&(st.count({p[i],p[i]-1})||st.count({p[i]-1,p[i]})))
            {
                st.erase({p[i],p[i]-1});
                st.erase({p[i]-1,p[i]});
            }
            if(!st.size())return i+1;
        }
        return n;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        string S;cin>>S;
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        int res = obj.getMinimumDays(N,S, P);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends