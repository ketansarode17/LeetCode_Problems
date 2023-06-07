//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
	
	void printTriangle(int n) {
	    // code here
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=1;j<2*n;j++)
	        {
	            if(j>=i and j<=2*n-i)cout<<"*";
	            else if(j<i)cout<<" ";
	            else break;
	        }
	        cout<<endl;
	    }
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        Solution ob;
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends