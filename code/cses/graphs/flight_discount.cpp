#include <bits/stdc++.h>
using namespace std;
 
#define vec vector
#define P pair
#define MAXX 1e15
 
using ll = long long;
 
ll n, m;
 
vec<vec<P<ll,ll>>> front;
vec<vec<P<ll,ll>>> rev;
vec<tuple<ll,ll,ll>> edges;
 
vec<ll> dfront;
vec<ll> drev;
 
void dijkstra(ll s, vec<ll>& dist, vec<vec<P<ll,ll>>>& adjList) {
	dist[s] = 0;
	vec<bool> processed(n + 5);
	priority_queue<P<ll,ll>, vec<P<ll,ll>>, greater<P<ll,ll>>> pq;
	pq.push({0,s});
	while(!pq.empty()){
		ll u = pq.top().second; pq.pop();
		if(processed[u]) continue;
		processed[u] = true;
		for(auto &pr : adjList[u]) {
			ll v = pr.first, w = pr.second;
		
			if(dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				pq.push({dist[v],v});
			}
		}
	}
}
 
int main(){
 
   
    cin >> n >> m;
	
	dfront.resize(n + 5, MAXX);
	drev.resize(n + 5, MAXX);
	
	front.resize(n + 5);
	rev.resize(n + 5);
	edges.resize(m);
	
	ll u, v, w;
	for(ll i=0; i<m; ++i) {
		cin >> u >> v >> w;
		front[u].push_back({v,w});
		rev[v].push_back({u,w});
		edges[i] = {u,v,w};
	}
   dijkstra(1, dfront, front);
	dijkstra(n, drev, rev); 
	
	ll ans = MAXX;
	for(auto &t : edges) {
		tie(u,v,w) = t;
		ans = min(ans, dfront[u] + w/2 + drev[v]);
	}
	cout << ans << "\n";
    return 0;
}
