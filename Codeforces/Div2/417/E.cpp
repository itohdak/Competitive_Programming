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
  int n; cin >> n;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<vector<int>> G(n);
  rep(i, n-1) {
    int p; cin >> p;
    p--;
    G[p].push_back(i+1);
  }
  vector<int> parity(n);
  int leaf_parity;
  auto dfs = [&](auto dfs, int cur) -> void {
    if(G[cur].empty()) leaf_parity = parity[cur];
    for(int ne: G[cur]) {
      parity[ne] = 1-parity[cur];
      dfs(dfs, ne);
    }
  };
  parity[0] = 0;
  dfs(dfs, 0);
  vector<map<ll, int>> P(2);
  vector<int> cnt(2);
  rep(i, n) {
    P[parity[i]][A[i]]++;
    cnt[parity[i]]++;
  }
  ll XOR = 0;
  for(auto ele: P[leaf_parity]) if(ele.second&1) XOR ^= ele.first;
  ll ans = 0;
  for(auto ele: P[leaf_parity]) {
    if(P[1-leaf_parity].count(XOR^ele.first)) {
      ans += 1LL * ele.second * P[1-leaf_parity][XOR^ele.first];
    }
  }
  if(XOR == 0) {
    ans += 1LL * cnt[leaf_parity] * (cnt[leaf_parity]-1) / 2;
    ans += 1LL * cnt[1-leaf_parity] * (cnt[1-leaf_parity]-1) / 2;
  }
  cout << ans << endk;
  return 0;
}
