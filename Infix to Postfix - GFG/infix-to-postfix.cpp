//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    private:
    int precedence(char x)
    {
        if(x=='^')return 3;
        if(x=='*' or x=='/')return 2;
        if(x=='+' or x=='-')return 1;
        return 0;
    }
  public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        // Your code here
        int n=s.size();
        string res="";
        stack<char>st;
        for(int i=0;i<n;i++)
        {
            if((s[i]>='a' and s[i]<='z') or (s[i]>='A' and s[i]<='Z') or(s[i]>='0' and s[i]<='7'))res+=s[i];
            else if(s[i]=='(')st.push('(');
            else if(s[i]==')')
            {
                while(st.top()!='(')
                {
                    res+=st.top();
                    st.pop();
                }
                st.pop();
            }
            else
            {
                if(st.empty())st.push(s[i]);
                else if(precedence(s[i])>precedence(st.top()))st.push(s[i]);
                else
                {
                    while(!st.empty() and precedence(st.top())>=precedence(s[i]))
                    {
                        res+=st.top();st.pop();
                    }
                    st.push(s[i]);
                }
            }
        }
        while(!st.empty())
        {
            res+=st.top();
            st.pop();
        }
        return res;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends