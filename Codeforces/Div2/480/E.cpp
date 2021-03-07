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
  int n, k; cin >> n >> k;
  vector<set<int>> G(n);
  rep(i, n-1) {
    int a, b; cin >> a >> b;
    a--; b--;
    G[a].insert(b);
    G[b].insert(a);
  }
  priority_queue<int> q;
  rep(i, n) if(G[i].size() == 1) q.push(-i);
  set<int> ans;
  while(k) {
    assert(q.size());
    int cur = q.top(); q.pop();
    cur = -cur;
    assert(G[cur].size() == 1);
    ans.insert(cur);
    int ne = *G[cur].begin();
    G[ne].erase(cur);
    if(G[ne].size() == 1) q.push(-ne);
    k--;
    // cout << G << endl;
  }
  for(int a: ans) cout << a+1 << ' ';
  cout << endk;
  return 0;
}
