//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int addMinChar(string str){    
        //code here
        list<char>forw,rever;
        int i=0;
        int ans=-1;
        for(auto it:str)
        {
            i++;
            forw.push_back(it);
            rever.push_front(it);
            if(forw==rever)ans=i;
        }
        return str.size()-ans;
    }
};

//{ Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin >> str;
        
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends