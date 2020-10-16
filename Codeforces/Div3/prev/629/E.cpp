#include <bits/stdc++.h>
// #include "/home/itohdak/Codeforces/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

vector<vector<int>> G;
vector<int> D;
vector<int> P;
vector<int> Tin, Tout;
int T;
void dfs(int tmp, int par, int val) {
  P[tmp] = par;
  D[tmp] = val;
  Tin[tmp] = T++;
  for(int ne: G[tmp]) {
    if(ne != par) {
      dfs(ne, tmp, val+1);
    }
  }
  Tout[tmp] = T++;
}
bool in(int v, int u) {
  return Tin[v] <= Tin[u] && Tout[u] <= Tout[v];
}
int main() {
  int N, M;
  cin >> N >> M;
  G = vector<vector<int>>(N);
  D = vector<int>(N);
  P = vector<int>(N);
  Tin = vector<int>(N);
  Tout = vector<int>(N);
  rep(i, N-1) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(0, -1, 0);
  rep(i, M) {
    int K;
    cin >> K;
    int mx = 0;
    int mxd = 0;
    vector<int> V(K);
    rep(k, K) {
      cin >> V[k];
      V[k]--;
      if(D[V[k]] > mxd) {
	mxd = D[V[k]];
	mx = V[k];
      }
    }
    for(auto &v: V) if(v != mx && P[v] != -1) v = P[v];
    bool ok = true;
    for(int v: V) if(!in(v, mx)) ok = false;
    cout << (ok ? "YES" : "NO") << endl;
  }
  return 0;
}
