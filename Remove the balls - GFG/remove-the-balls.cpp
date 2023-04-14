//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int finLength(int n, vector<int> color, vector<int> radius) {
        vector<pair<int,int>>vc;
        for(int i=0;i<n;i++)
        {
            vc.emplace_back(color[i],radius[i]);
        }
        stack<pair<int,int>>st;
        st.push(vc[0]);
        for(int i=1;i<n;i++)
        {
            if(!st.empty() and vc[i]==st.top())
            {
                st.pop();
            }
            else
            {
                st.push(vc[i]);
            }
        }
        return st.size();
    }
};


//{ Driver Code Starts.
int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        vector<int> color(n), radius(n);
        for (int i = 0; i < n; i++) cin >> color[i];
        for (int i = 0; i < n; i++) cin >> radius[i];
        int ans = sol.finLength(n, color, radius);
        cout << ans << "\n";
    }

    return 0;
}

// } Driver Code Ends