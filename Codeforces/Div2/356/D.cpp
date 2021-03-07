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
  ll m; cin >> m;
  int BIG = 100050;
  vector<ll> cube;
  for(ll i=0; i<=BIG; i++) {
    cube.push_back(i*i*i);
  }
  auto bsearch = [&](ll c) {
    auto test = [&](ll mid) {
      return c + cube[mid] < cube[mid+1];
    };
    ll ok = BIG, ng = 0;
    while(ok-ng>1) {
      ll mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  priority_queue<pair<ll, int>> q;
  map<ll, int> cnt;
  map<ll, ll> par;
  set<ll> vis;
  cnt[1] = 1;
  q.push({-1, cnt[1]});
  while(q.size()) {
    auto [cur, c] = q.top(); q.pop();
    cur = -cur;
    if(vis.count(cur)) continue;
    if(cnt[cur] != c) continue;
    vis.insert(cur);
    int lb = bsearch(cur);
    int ub = upper_bound(all(cube), m-cur) - begin(cube);
    for(int j=lb; j<ub; j++) {
      ll ne = cur + cube[j];
      if(ne <= m) {
        if(!cnt.count(ne) || cnt[ne] < c + 1) {
          cnt[ne] = c + 1;
          q.push({-ne, cnt[ne]});
          par[ne] = cur;
        }
      }
    }
  }
  map<int, ll> ans;
  for(auto ele: cnt) {
    chmax(ans[ele.second], ele.first);
  }
  auto itr = --end(ans);
  cout << itr->first << ' ' << itr->second << endk;
  // ll tmp = itr->second;
  // while(tmp > 1) {
  //   cout << tmp << ' ';
  //   tmp = par[tmp];
  // }
  // cout << endk;
  return 0;
}
