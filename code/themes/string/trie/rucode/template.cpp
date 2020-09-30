#include <bits/stdc++.h>
 
#define fi first
#define se second
 
using namespace std;
 
struct node
{
        int cnt;
        //int adj[26];
        map < int, int > adj;
        node()
        {
                cnt = 0;
                //for(int i = 0; i < 26; i++){
                //        adj[i] = -1;
                //}
        }
};
 
int last_node = 0;
node t[1000000];
vector < int > free_nodes;
 
/*
t = [0 1 2 3 ... ]
*/
void add(string s)
{
        int cur = 0;
        for(int i = 0; i < s.size(); i++){
                int ch = s[i] - 'a';
 
                if(t[cur].adj.find(ch) == t[cur].adj.end()){
                        //last_node += 1;
                        t[cur].adj[ch] = free_nodes.back();
                        free_nodes.pop_back();
                }
                //if(t[cur].adj[ch] == -1){
                //        last_node += 1;
                //        t[cur].adj[ch] = last_node;
                //}
                cur = t[cur].adj[ch];
        }
        t[cur].cnt += 1;
}
 
/*
 + abbb
 + adsa
 - jdks
*/
 
/*
 + ab
 + ab
 - ab
 - ab
 - ab
*/
 
void del(string s)
{
        int cur = 0;
        for(int i = 0; i < s.size(); i++){
                int ch = s[i] - 'a';
                if(t[cur].adj.find(ch) == t[cur].adj.end()){
                        return;
                }
                cur = t[cur].adj[ch];
        }
        if(t[cur].cnt > 0){
                t[cur].cnt -= 1;
        }
}
 
bool good(string s)
{
        int cur = 0;
        for(int i = 0; i < s.size(); i++){
                int ch = s[i] - 'a';
                if(t[cur].adj.find(ch) == t[cur].adj.end()){
                        return false;
                }
                cur = t[cur].adj[ch];
        }
        if(t[cur].cnt > 0){
                return true;
        }
        return false;
}
 
int main()
{
        ios_base::sync_with_stdio(0);
 
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
 
        for(int i = 1; i < 1000000; i++){
                free_nodes.push_back(i);
        }
 
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
                char tp;
                string s;
                cin >> tp >> s;
                if(tp == '+'){
                        add(s);
                } else if(tp == '-'){
                        del(s);
                } else{
                        cout << (good(s) ? "YES" : "NO") << "\n";
                }
        }
}
