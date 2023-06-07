//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        // code here
        for(int i=1;i<=n;i++)
        {
            char res='A';
            for(int j=1;j<=2*n-1;j++)
            {
                if(j<n-i+1)cout<<" ";
                else if(j>=n-i+1 and j<n)
                {
                    cout<<res++;
                }
                else if(j>=n and j<=n-1+i)
                {
                    cout<<res--;
                }
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