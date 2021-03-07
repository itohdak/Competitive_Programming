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
  int n, k; cin >> n >> k;
  vector<int> S(n);
  map<int, int> cnt;
  rep(i, n) {
    cin >> S[i];
    cnt[S[i]]++;
  }
  auto bsearch = [&]() {
    auto test = [&](int mid) {
      int sum = 0;
      for(auto ele: cnt) {
        sum += ele.second / mid;
      }
      return sum >= k;
    };
    int ok = 0, ng = inf;
    while(ng - ok > 1) {
      int mid = (ok + ng) / 2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  int ret = bsearch();
  vector<int> ans;
  for(auto ele: cnt) {
    rep(i, ele.second / ret) ans.push_back(ele.first);
  }
  rep(i, k) cout << ans[i] << ' ';
  cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
