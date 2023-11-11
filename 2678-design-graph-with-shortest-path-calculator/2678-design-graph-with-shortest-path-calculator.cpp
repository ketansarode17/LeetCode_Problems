class Graph {
public:
vector<pair<int,int>>graph[101];
int helper(int source,int node2,vector<bool>&vis)
{
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>>> pq;
    int n=vis.size();
	vector<int> distTo(n,INT_MAX);
	distTo[source] = 0;
	pq.push(make_pair(0,source));	
	while( !pq.empty() ){
		int dist = pq.top().first;
		int prev = pq.top().second;
		pq.pop();
		vector<pair<int,int> >::iterator it;
		for( it = graph[prev].begin() ; it != graph[prev].end() ; it++){
			int next = it->first;
			int nextDist = it->second;
			if( distTo[next] > distTo[prev] + nextDist){
				distTo[next] = distTo[prev] + nextDist;
				pq.push(make_pair(distTo[next], next));
			}
		}
    }
    return distTo[node2];
}
int nodes;
    Graph(int n, vector<vector<int>>& edges) {
        nodes=n;
        for(auto it:edges)
        {
            graph[it[0]].emplace_back(it[1],it[2]);
        }
    }
    
    void addEdge(vector<int> edge) {
        graph[edge[0]].emplace_back(edge[1],edge[2]);
    }
    
    int shortestPath(int node1, int node2) {
        vector<bool>vis(nodes,false);
        int ans=helper(node1,node2,vis);
        return ans==INT_MAX?-1:ans;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */