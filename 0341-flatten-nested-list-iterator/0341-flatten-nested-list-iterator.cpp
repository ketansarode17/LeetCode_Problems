/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
vector<int>ans;
int ptr=0;
void helper(vector<NestedInteger>vc,vector<int>&ans)
{
    if(!vc.size())return;
    for(int i=0;i<vc.size();i++)
    {
        if(vc[i].isInteger())
        {
            ans.push_back(vc[i].getInteger());
        }
        else
        {
            helper(vc[i].getList(),ans);
        }
    }
}
    NestedIterator(vector<NestedInteger> &nestedList) {
       helper(nestedList,ans);
    }
    
    int next() {
        return ans[ptr++];
    }
    
    bool hasNext() {
        if(ans.size())return ptr<=ans.size()-1;
        return false;   
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */