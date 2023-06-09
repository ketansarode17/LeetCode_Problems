//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToPost(string pre_exp) {
        int n=pre_exp.size();
        stack<string>st;
        for(int i=n-1;i>=0;i--)
        {
            //cout<<i<<endl;
            if((pre_exp[i]>='a' and pre_exp[i]<='z') or (pre_exp[i]>='A' and pre_exp[i]<='Z'))
            {
                string temp="";
                temp+=pre_exp[i];
                st.push(temp);
            }
            else
            {
                string s1=st.top();st.pop();
                string s2=st.top();st.pop();
                st.push(s1+s2+pre_exp[i]);
            }
        }
        return st.top();
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToPost(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends