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
  ll n; int m; cin >> n >> m;
  vector<pair<ll, ll>> P(m);
  for(auto& [x, y]: P) cin >> x >> y;
  sort(all(P));
  int l = 0;
  set<ll> st;
  st.insert(n);
  while(l < m) {
    int r = l;
    while(r < m && P[r].first == P[l].first) r++;
    set<ll> rm, add;
    for(int i=l; i<r; i++) {
      int y = P[i].second;
      if(!st.count(y-1) && !st.count(y+1) && st.count(y)) rm.insert(y);
      if(!st.count(y) && (st.count(y-1) || st.count(y+1))) add.insert(y);
    }
    for(auto i: rm) st.erase(i);
    for(auto i: add) st.insert(i);
    l = r;
  }
  cout << st.size() << endk;
  return 0;
}
