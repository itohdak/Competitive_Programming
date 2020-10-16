#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
template<class t, class u>
ostream& operator<<(ostream& os, const pair<t, u>& p) {
  return os << "{" << p.first << ", " << p.second << "}";
}
template<class t> ostream& operator<<(ostream& os, const vector<t>& v) {
  os << "{";
  rep(i, v.size()) { if(i) os << ", "; os << v[i]; }
  return os << "}";
}
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

vector<vector<int> > G;
vector<vector<ll> > C;
vector<vector<ll> > cost;
vector<int> ans;
int comb[][3] = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};
void dfs(int tmp, int par, int dep){
  if(par == -1) {
    rep(j, 6) cost[tmp][j] = C[tmp][comb[j][dep%3]];
  } else {
    rep(j, 6) cost[tmp][j] = cost[par][j] + C[tmp][comb[j][dep%3]];
  }
  for(int c: G[tmp])
    if(c != par)
      dfs(c, tmp, dep+1);
}
void dfs2(int tmp, int par, int dep, int idx){
  ans[tmp] = comb[idx][dep%3]+1;
  for(int c: G[tmp])
    if(c != par)
      dfs2(c, tmp, dep+1, idx);
}

int main() {
  int N;
  cin >> N;
  G = vector<vector<int> >(N);
  C = vector<vector<ll> >(N, vector<ll>(3));
  rep(j, 3) rep(i, N) cin >> C[i][j];
  rep(i, N-1) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<int> e;
  bool ok = true;
  rep(i, N) {
    if(G[i].size() > 2) {
      ok = false;
      break;
    } else if(G[i].size() == 1) {
      e.push_back(i);
    }
  }
  if(!ok || e.size() != 2) {
    cout << -1 << endl;
  } else {
    cost = vector<vector<ll> >(N, vector<ll>(6));
    dfs(e[0], -1, 0);
    int mi = -1;
    ll mn = longinf;
    rep(j, 6) {
      if(cost[e[1]][j] < mn) {
        mn = cost[e[1]][j];
        mi = j;
      }
    }
    cout << mn << endl;
    ans = vector<int>(N);
    dfs2(e[0], -1, 0, mi);
    rep(i, N) cout << ans[i] << ' ';
    cout << endl;
  }
  return 0;
}

