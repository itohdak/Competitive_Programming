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
  int n, x, y; cin >> n >> x >> y;
  vector<int> A(n); rep(i, n) cin >> A[i];
  vector<int> B;
  rep(i, n) {
    if(A[i] < y || A[i] > x) B.push_back(i);
  }
  B.push_back(n);
  multiset<int> st;
  int r = 0;
  ll ans = 0;
  rep(l, n) {
    while(r < n) {
      if(st.size() && (*st.begin() < y || *(--st.end()) > x)) break;
      if(st.size() && (*st.begin() == y && *(--st.end()) == x)) break;
      st.insert(A[r]);
      r++;
    }
    if((st.size() && (*st.begin() == y && *(--st.end()) == x))) {
      auto itr = lower_bound(all(B), r);
      ans += *itr - r + 1;
      // cout << l << ' ' << r << endk;
    }
    st.erase(st.find(A[l]));
  }
  cout << ans << endk;
  return 0;
}