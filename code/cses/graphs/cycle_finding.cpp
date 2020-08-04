#include <bits/stdc++.h>
using namespace std;
 
#define vec vector
#define P pair
#define MAXX 1e15
 
using ll = long long;
 
ll n, m;
 
vec<tuple<ll,ll,ll>> edges;
 
vec<ll> dist;
vec<ll> p;
 
void bellman_ford(){
	dist[1] = 0; ll u,v,w,x;
	for(ll i = 0; i < n; ++i) {
	    x = -1;
		for(auto &t : edges){
			tie(u,v,w) = t;
			if(dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				p[v] = u;
				x = v;
			}
		}
	}
	vector<ll> path;
	if(x != -1) {
		ll cur = p[x];
		for(ll i=0; i<n; ++i){
			cur = p[cur];
		}
		
		ll y = cur;
	
		bool flag = true;
		while(flag || y != cur){
		    
			path.push_back(y);
			y = p[y];
			flag = false;
		}
		path.push_back(cur);
		reverse(path.begin(), path.end());
		cout <<"YES\n";
		for(auto &i : path){
			cout << i << " ";
		}
		cout <<"\n";
	} else {
		cout <<"NO\n";
	}
}
 
int main(){
 
   
    cin >> n >> m;
	
	dist.resize(n + 5, MAXX);
	p.resize(n + 5);
 
	
	edges.resize(m);
	
	ll u, v, w;
	for(ll i=0; i<m; ++i) {
		cin >> u >> v >> w;
		edges[i] = {u,v,w};
	}
	bellman_ford();
    return 0;
}
