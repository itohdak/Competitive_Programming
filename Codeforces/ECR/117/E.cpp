#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
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
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  int n; cin >> n;
  vector<int> M(n), K(n);
  map<pair<int, int>, int> cnt;
  rep(i, n) {
    cin >> M[i] >> K[i];
    M[i]--;
    cnt[{M[i], K[i]}]++;
  }
  int m = 200000;
  vector<ll> val(m);
  for(auto [p, c]: cnt) {
    val[p.first] += p.second * c;
  }
  priority_queue<pair<int, int>> q;
  rep(i, m) q.push({val[i], i});
  set<int> ans;
  ld prev = 0;
  auto calc = [&]() {
    ld ret = 0;
    rep(i, n) {
      if(!ans.count(M[i])) continue;
      int c = ans.size();
      if(K[i] >= c) ret += 1;
      else ret += (ld)K[i]/c;
    }
    return ret;
  };
  rep(i, 20) {
    auto [val, cur] = q.top();
    ans.insert(cur);
    q.pop();
    ld next = calc();
    if(next >= prev) chmax(prev, next);
    else {
      ans.erase(cur);
      break;
    }
  }
  cout << ans.size() << endk;
  for(int a: ans) cout << a+1 << ' '; cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
