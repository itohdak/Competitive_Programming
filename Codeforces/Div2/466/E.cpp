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
  int n, c; cin >> n >> c;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<ll> dp(n+1);
  vector<ll> mx(n+1);
  multiset<ll> st;
  rep(i, n) {
    st.insert(A[i]);
    if((int)st.size() < c) continue;
    chmax(dp[i+1], mx[i-c+1]+(*st.begin()));
    chmax(mx[i+1], max(dp[i+1], mx[i]));
    assert(st.find(A[i-c+1]) != st.end());
    st.erase(st.find(A[i-c+1]));
  }
  // cout << dp << endk;
  // cout << mx << endk;
  cout << accumulate(all(A), 0LL) - mx[n] << endk;
  return 0;
}
