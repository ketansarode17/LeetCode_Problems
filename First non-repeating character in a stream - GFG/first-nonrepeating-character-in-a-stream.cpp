//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string s){
		    // Code here
		    vector<pair<int,int>>hash(26,{-1,0});
		    int n=s.size();
		    string res="";
		    for(int i=0;i<n;i++)
		    {
		        if(hash[s[i]-'a'].first==-1)hash[s[i]-'a'].first=i;
		        hash[s[i]-'a'].second++;
		        int cnt=0,prev=INT_MAX,ans=-1;
		        for(int i=0;i<26;i++)
		        {
		            if(hash[i].second==1 and prev>hash[i].first)
		            {
		                prev=hash[i].first;
		                ans=i;
		            }
		        }
		        if(ans==-1)res+="#";
		        else 
		        res+=('a'+ans);
		    }
		    return res;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends