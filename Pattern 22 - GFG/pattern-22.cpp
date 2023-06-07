//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printSquare(int n) {
        // code here
        for(int i=1;i<=n;i++)
        {
            int temp=n;
            for(int j=1;j<2*n;j++)
            {
                if(j<i)cout<<temp--<<" ";
                else if(j>=i and j<2*n-i)cout<<temp<<" ";
                else cout<<temp++<<" ";
            }
            cout<<endl;
        }
        for(int i=n-1;i>=1;i--)
        {
            int temp=n;
            for(int j=1;j<2*n;j++)
            {
                if(j<i)cout<<temp--<<" ";
                else if(j>=i and j<2*n-i)cout<<temp<<" ";
                else cout<<temp++<<" ";
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
        ob.printSquare(n);
    }
    return 0;
}
// } Driver Code Ends