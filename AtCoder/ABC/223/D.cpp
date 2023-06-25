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
  vector<vector<int>> G(n);
  vector<vector<int>> H(n);
  rep(i, m) {
    int a, b; cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    H[b].push_back(a);
  }
  using P = pair<int, int>;
  priority_queue<P, vector<P>, greater<P>> q;
  vector<int> nIn(n);
  rep(i, n) q.push({nIn[i] = H[i].size(), i});
  int rem = n;
  vector<bool> done(n);
  vector<int> ans;
  while(rem > 0) {
    auto [in, cur] = q.top(); q.pop();
    if(in != 0) {
      cout << -1 << endk;
      return 0;
    }
    if(done[cur]) continue;
    done[cur] = true;
    ans.push_back(cur);
    for(int ne: G[cur]) {
      if(done[ne]) continue;
      q.push({--nIn[ne], ne});
    }
    rem--;
  }
  rep(i, n) cout << ans[i]+1 << ' ';
  cout << endk;
  return 0;
}
