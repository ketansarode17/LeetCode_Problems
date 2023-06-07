//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printDiamond(int n) {
        // code here
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<n-i+1;j++)cout<<" ";
            for(int j=n-i+1;j<=n+i-1;j+=2)
                cout<<"* ";
            cout<<endl;
        }
        for(int i=n;i>=1;i--)
        {
            for(int j=1;j<n-i+1;j++)cout<<" ";
            for(int j=n-i+1;j<=n+i-1;j+=2)
                cout<<"* ";
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
        ob.printDiamond(n);
    }
    return 0;
}
// } Driver Code Ends