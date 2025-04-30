class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>> adj; // u-->(v, w)
        // build graphs
        for(auto x: times){
            adj[x[0]].emplace_back(x[1], x[2]);
        }

        // Dijksra setup
        vector<int> dist(n+1, INT_MAX); // intially the distance of ecah node is infinite
        dist[k] = 0; // start have zero distance
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> pq;
        pq.emplace(0, k); // (dist, node)
        while(!pq.empty()){
            auto [currentDist, node] = pq.top(); pq.pop();
            if(currentDist > dist[node]) continue; // dist[node] may have a large distance

            for(auto &[nei, w]: adj[node]){
                if(dist[nei] > dist[node]+w){
                    // if the nei has greater then we need to reduce it to small
                    dist[nei] = dist[node]+w;
                    pq.emplace(dist[nei], nei);
                }
            }

        }
        int maxTime = *max_element(dist.begin()+1, dist.end());
        return maxTime == INT_MAX ? -1 : maxTime;
    }
};