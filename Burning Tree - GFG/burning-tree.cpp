//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
    private:
    unordered_map<Node*,Node*>par;
    Node* bfs(Node* root,int target)
    {
        Node* res;
        queue<Node*>q;
        q.push(root);
        par[root]=NULL;
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                auto node=q.front();
                if(node->data==target)res=node;
                q.pop();
                if(node->left)
                {
                    par[node->left]=node;
                    q.push(node->left);
                }
                if(node->right)
                {
                    par[node->right]=node;
                    q.push(node->right);
                }
            }
        }
        return res;
    }
  public:
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        //get access to parent node and return the node which contains target.
        Node* node=bfs(root,target);
        //now start doing bfs from the target node.
        //using bfs because in 1 unit of time it will burn all the adjacents like parent,and childs.
        queue<Node*>q;
        q.push(node);
        unordered_map<Node*,bool>vis;
        int ans=0;
        while(!q.empty())
        {
            int n=q.size();
            ans++;
            for(int i=0;i<n;i++)
            {
                auto node=q.front();
                q.pop();
                if(par[node])
                {
                    if(vis.find(par[node])==vis.end())
                    {
                        vis[par[node]]=true;
                        q.push(par[node]);
                    }
                }
                if(node->left)
                {
                    if(vis.find(node->left)==vis.end())
                    {
                        vis[node->left]=true;
                        q.push(node->left);
                    }
                }
                if(node->right)
                {
                    if(vis.find(node->right)==vis.end())
                    {
                        vis[node->right]=true;
                        q.push(node->right);
                    }
                }
            }
        }
        return ans-1;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends