//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int solve(int a, int b, int c) {
        // code here
        int ans=0;
        vector<int>vc={a,b,c};
        sort(vc.begin(),vc.end());
        int maxi=vc[2];
        int bins=(maxi/2+(maxi%2!=0))+1;
        if(vc[0]+vc[1]>=bins-2)return (a+b+c); 
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;

        Solution ob;
        int ans = ob.solve(a, b, c);
     

        cout <<  ans << "\n";
    }
    return 0;
}
// } Driver Code Ends