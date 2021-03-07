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
  vector<ll> H(n), W(n);
  map<ll, vector<pair<ll, int>>, greater<ll>> mp; // h, w, i
  multiset<tuple<ll, ll, int>> st; // w, h, i
  rep(i, n) {
    cin >> H[i] >> W[i];
    mp[H[i]].push_back({W[i], i});
    mp[W[i]].push_back({H[i], i});
    st.insert({W[i], H[i], i});
    st.insert({H[i], W[i], i});
  }
  vector<int> ans(n, -2);
  for(auto [h, ele]: mp) {
    for(auto [w, i]: ele) {
      st.erase(st.find({w, h, i}));
    }
    for(auto [w, i]: ele) {
      auto itr = st.upper_bound({w-1, h-1, inf});
      if(itr != st.begin()) {
        --itr;
        if(get<2>(*itr) == i) {
          if(itr == st.begin()) continue;
          else --itr;
        }
        ans[i] = get<2>(*itr);
      }
      // cout << i << ' ' << ans << endk;
    }
  }
  rep(i, n) cout << ans[i]+1 << ' ';
  cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
