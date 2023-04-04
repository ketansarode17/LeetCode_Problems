//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    // Write your code here.
    int a=0,b=0;
    int i=0,n=str.size();
    while(i<n)
    {
        char ch=str[i];
        if(ch=='a')a++;
        else b++;
        while(str[i]==ch)
        {
            i++;
        }
    }
    return 1+min(a,b);
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends