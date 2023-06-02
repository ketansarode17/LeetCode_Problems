//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    private:
    Node* rev(Node* node,Node* prev)
    {
        if(!node)return prev;
        Node* next=node->next;
        node->next=prev;
        return rev(next,node);
    }
    public:
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        int carry=1;
        head=rev(head,NULL);
        Node* temp=head;
        while(temp)
        {
            int val=temp->data+carry;
            if(val>=10)
            {
                carry=val/10;
                temp->data=val%10;
                temp=temp->next;
            }
            else 
            {
                temp->data=val;
                carry=0;break;
            }
        }
        head=rev(head,NULL);
        if(carry)
        {
            Node* node=new Node(carry);
            node->next=head;
            head=node;
        }
        return head;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends