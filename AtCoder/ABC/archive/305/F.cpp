#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,(n)-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<bool> vis(n);
  vector<vector<int>> G(n);
  vector<int> path;
  int cur = 0;
  while(1) {
    int k; cin >> k;
    if(k == -1) {
      assert(false);
      break;
    }
    vector<int> V(k);
    rep(i, k) {
      cin >> V[i];
      V[i]--;
      if(!vis[V[i]]) {
	G[cur].push_back(V[i]);
	G[V[i]].push_back(cur);
      }
    }
    vis[cur] = true;
    int next = -1;
    for(int nx: G[cur]) {
      if(vis[nx]) continue;
      next = nx;
      break;
    }
    if(next != -1) {
      cout << next+1 << endl;
      if(next == n-1) {
	string ok;
	cin >> ok;
	assert(ok == "OK");
	break;
      } else {
	path.push_back(cur);
	cur = next;
      }
    } else {
      cout << path.back()+1 << endl;
      cur = path.back();
      path.pop_back();
    }
  }
  return 0;
}
