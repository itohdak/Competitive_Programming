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
  vector<ll> A(n);
  rep(i, n) cin >> A[i];
  int M = 5000;
  vector<int> mx(M+1, -1), mn(M+1, inf);
  rep(i, n) {
    chmin(mn[A[i]], i);
    chmax(mx[A[i]], i);
  }
  vector<ll> dp(n+1);
  rep(i, n) {
    chmax(dp[i+1], dp[i]);
    if(mn[A[i]] == i) {
      ll XOR = 0;
      unordered_set<int> st;
      REP(j, i, n) {
        if(mn[A[j]] < i) break;
        if(mn[A[j]] == j) {
          XOR ^= A[j];
          st.insert(A[j]);
        }
        if(mx[A[j]] == j) {
          st.erase(A[j]);
        }
        if(st.empty()) chmax(dp[j+1], dp[i]+XOR);
      }
    }
  }
  cout << dp[n] << endk;
  return 0;
}
