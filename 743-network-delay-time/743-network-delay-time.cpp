class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int , int>> adj[n + 1];         // Graph Container (Adjacency List)
   
        for(int i = 0 ; i < times.size() ; ++i){
            adj[times[i][0]].push_back(make_pair(times[i][1] , times[i][2]));   //Constructing the graph.
        }
        
        vector<bool> visited(n + 1 , false);        // Visited Array
        vector<int> distances(n + 1 , INT_MAX);     // Minimum Distance of each node from k, initialized by INT_MAX.
        if(adj[k].size() == 0){                     // If there is no outgoing edge from k, return -1.
            return -1;
        } else {                                // Standard Dijkstra Algorithm Implementation
            priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> dijkstra_queue;
            distances[k] = 0;
            int count = 0;
            dijkstra_queue.push(make_pair(0 , k));
            while(count < n && !dijkstra_queue.empty()){
                int distance = dijkstra_queue.top().first;
                int node = dijkstra_queue.top().second;
                dijkstra_queue.pop();
                if(visited[node]){
                    continue;
                }
                visited[node] = true;
                distances[node] = distance;
                count++;
                for(auto it : adj[node]){
                    int next_node = it.first;
                    int next_distance = it.second;
                    if(!visited[next_node]){
                        dijkstra_queue.push(make_pair(distance + next_distance , next_node));
                    }
                }
            }
        }
        int answer = 0;
        for(int i = 1 ; i < distances.size() ; ++i){    
            answer = max(answer , distances[i]);    // Distance of farthest node would be our answer.
        }
        if(answer == INT_MAX){      // Means we have missed some node.
            return -1;
        }
        return answer;              
    }
};