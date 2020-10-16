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
  int n, q; cin >> n >> q;
  set<ll> st;
  rep(i, n) {
    ll p; cin >> p;
    st.insert(p);
  }
  ll pre = *st.begin();
  multiset<ll> d;
  for(auto ele: st) {
    if(ele-pre) d.insert(ele - pre);
    pre = ele;
  }
  cout << (st.empty() ? 0 : *st.rbegin() - *st.begin()) - (d.empty() ? 0 : *d.rbegin()) << endl;
  rep(_, q) {
    int t; ll x; cin >> t >> x;
    if(t) {
      auto itr1 = st.lower_bound(x+1);
      auto lb = (itr1 == st.end() ? x : *itr1);
      auto itr2 = st.upper_bound(x-1);
      auto ub = (itr2 == st.begin() ? x : *(--itr2));
      if(lb-x && x-ub) d.erase(d.find(lb-ub));
      if(lb-x) d.insert(lb-x);
      if(x-ub) d.insert(x-ub);
      st.insert(x);
    } else {
      auto itr1 = st.lower_bound(x+1);
      auto lb = (itr1 == st.end() ? x : *itr1);
      auto itr2 = st.upper_bound(x-1);
      auto ub = (itr2 == st.begin() ? x : *(--itr2));
      if(lb-x && x-ub) d.insert(lb-ub);
      if(lb-x) d.erase(d.find(lb-x));
      if(x-ub) d.erase(d.find(x-ub));
      st.erase(x);
    }
    // cout << st << endl;
    // cout << d << endl;
    cout << (st.empty() ? 0 : *st.rbegin() - *st.begin()) - (d.empty() ? 0 : *d.rbegin()) << endl;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
