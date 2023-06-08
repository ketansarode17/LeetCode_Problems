//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int arr[], long long int n)  
    {
        // code here
        long long int xor_=0;
        for(int i=0;i<n;i++){xor_^=arr[i];}
        long long int res1=0,res2=0;
        int pos=-1;
        for(int i=0;i<32;i++)
        {
            if(xor_&(1<<i))
            {
                pos=i;break;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i]&(1<<pos))res1^=arr[i];
            else res2^=arr[i];
        }
        if(res1<res2)swap(res1,res2);
        return {res1,res2};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends