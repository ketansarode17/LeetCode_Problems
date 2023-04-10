//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxIntersections(vector<vector<int>> lines, int N) {
        // Code here
        map<int,int>freq;
        for(auto it:lines)
        {
            freq[it[0]]++;
            freq[it[1]+1]--;
        }
        int prev_ans=0;
        int maxi=-1;
        for(auto& it:freq)
        {
            it.second+=prev_ans;
            prev_ans=it.second;
            maxi=max(maxi,it.second);
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> mat(N, vector<int>(2));
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < N; i++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        cout << obj.maxIntersections(mat, N) << endl;
    }
}
// } Driver Code Ends