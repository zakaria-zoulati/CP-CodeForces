#include <bits/stdc++.h>

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

using namespace std;
using ll = long long;

struct State {
    ll dist;
    int node;
    bool operator>(const State &other) const {
        return dist > other.dist;
    }
}; 
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int,ll>>> edges(n);
    while(m--){
        int u, v;
        cin >> u >> v;
        ll c; cin >> c;
        u--; v--;
        edges[u].push_back({v,c});
        edges[v].push_back({u,c});
    }
    vector<ll> dist(n, LLONG_MAX);
    vector<int> train_used(n,0);
    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push({0,0});
    dist[0]=0;
    for(int i=0;i<k;i++){
        int c; cin>>c; c--;
        ll s; cin>>s;
        if(s<dist[c]){
            dist[c]=s;
            pq.push({s,c});
            train_used[c]=1;
        } else if(s==dist[c]){
            train_used[c]=1;
        }
    }
    while(!pq.empty()){
        auto [d,u]=pq.top();
        pq.pop();
        if(d!=dist[u]) continue;
        for(auto [v,c]:edges[u]){
            if(dist[v]>d+c){
                dist[v]=d+c;
                pq.push({dist[v],v});
                train_used[v]=0;
            } else if(dist[v]==d+c){
                train_used[v]=0;
            }
        }
    }
    int rs=0;
    for(int i=0;i<n;i++) if(train_used[i]) rs++;
    cout<<k-rs<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
