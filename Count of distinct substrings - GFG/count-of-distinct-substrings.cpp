//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int countDistinctSubstring(string s);

int main()
{
 int t,l,i,j;
 int temp;
    cin>>t;
 while(t--){
 string s;
  cin>>s;
  cout<<countDistinctSubstring(s)<<endl;

 }
}


// } Driver Code Ends

struct Node
{
    Node* links[26];
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
    void put(char ch,Node* node)
    {
        links[ch-'a']=node;
    }
};
class Trie
{
    private:Node* root;
    public:
        Trie()
        {
            root=new Node();
        }
    int insert(string s)
    {
        int n=s.size(),count=0;
        for(int i=0;i<n;i++)
        {
            string temp="";
            Node* node=root;
            for(int j=i;j<n;j++)
            {
                if(!node->get(s[j]))
                {
                    count++;
                    node->put(s[j],new Node());
                }
                node=node->get(s[j]);
            }
        }
        return count+1;
    }
};
/*You are required to complete this method */
int countDistinctSubstring(string s)
{
    //Your code here
    Trie trie;
    return trie.insert(s);
}