//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findXOR(int l, int r) {
        // complete the function here
        int left_part=l-1;
        if(left_part%4==0){}
        else if(left_part%4==1)
        {
            left_part=1;
        }
        else if(left_part%4==2)left_part+=1;
        else left_part=0;
        if(r%4==0){}
        else if(r%4==1)
        {
            r=1;
        }
        else if(r%4==2)r+=1;
        else r=0;
        return (left_part^r);
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        // Input

        int l, r;
        cin >> l >> r;

        Solution obj;
        cout << obj.findXOR(l, r) << endl;
    }
}
// } Driver Code Ends