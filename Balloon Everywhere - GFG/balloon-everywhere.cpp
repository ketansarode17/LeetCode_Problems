//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    int maxInstance(string s){
        vector<int>vc(27);
        for(int i=0;i<s.size();i++)
        {
            vc[s[i]-'a']++;
        }
        //for(int i=0;i<27;i++)cout<<vc[i]<<endl;
        int poss=1e9;
        poss=min(poss,vc[1]);poss=min(poss,vc[0]);
        poss=min(poss,vc['l'-'a']/2);poss=min(poss,vc['o'-'a']/2);
        poss=min(poss,vc['n'-'a']);
        return poss;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends