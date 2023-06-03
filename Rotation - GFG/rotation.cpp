//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int nums[], int n) {
	    // code here
        int lo=0,hi=n-1;
        int ans=1e8,ind=-1;
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(nums[mid]>=nums[lo] and nums[mid]<=nums[hi])
            {
                if(nums[lo]<ans)
                {
                    ans=nums[lo];ind=lo;
                }
                break;
            }
            if(nums[mid]>=nums[lo])
            {
                if(nums[lo]<ans)
                {
                    ans=nums[lo];ind=lo;
                }
                lo=mid+1;
            }
            else
            {
                if(nums[mid]<ans)
                {
                    ans=nums[mid],ind=mid;
                }
                hi=mid-1;
            }
        }
        return ind;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends