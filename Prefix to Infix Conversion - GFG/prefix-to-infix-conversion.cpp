//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToInfix(string pre_exp) {
        // Write your code here
        int n=pre_exp.size();
        stack<string>st;
        for(int i=n-1;i>=0;i--)
        {
            if(pre_exp[i]=='*' or pre_exp[i]=='+' or pre_exp[i]=='/' or pre_exp[i]=='-' or pre_exp[i]=='^')
            {
                string s1=st.top();st.pop();
                string s2=st.top();st.pop();
                s1='('+s1+pre_exp[i]+s2+')';
                st.push(s1);
            }
            else
            {
                string temp="";
                temp+=pre_exp[i];
                st.push(temp);
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
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends