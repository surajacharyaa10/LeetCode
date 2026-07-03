class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();

        vector<vector<pair<int,int>>> g(n);
        vector<int> indeg(n,0);

        int mx = 0;
        for(auto &e: edges){
            g[e[0]].push_back({e[1], e[2]});
            indeg[e[1]]++;
            mx = max(mx, e[2]);
        }

        queue<int> q;
        for(int i=0;i<n;i++)
            if(indeg[i]==0) q.push(i);

        vector<int> topo;
        while(!q.empty()){
            int u=q.front(); q.pop();
            topo.push_back(u);
            for(auto &[v,w]:g[u]){
                if(--indeg[v]==0) q.push(v);
            }
        }

        auto check = [&](int lim)->bool{
            const long long INF = (1LL<<60);
            vector<long long> dist(n, INF);
            dist[0]=0;

            for(int u: topo){
                if(dist[u]==INF) continue;

                if(u!=0 && u!=n-1 && !online[u]) continue;

                for(auto &[v,w]: g[u]){
                    if(w<lim) continue;
                    if(v!=n-1 && v!=0 && !online[v]) continue;
                    if(dist[v] > dist[u]+w)
                        dist[v]=dist[u]+w;
                }
            }

            return dist[n-1]<=k;
        };

        int lo=0, hi=mx;
        while(lo<hi){
            int mid = lo + (hi-lo+1)/2;
            if(check(mid))
                lo=mid;
            else
                hi=mid-1;
        }

        return check(lo) ? lo : -1;
    }
};