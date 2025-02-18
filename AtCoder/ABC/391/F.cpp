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
  int n, k; cin >> n >> k;
  vector<int> A(n), B(n), C(n);
  rep(i, n) cin >> A[i];
  rep(i, n) cin >> B[i];
  rep(i, n) cin >> C[i];
  sort(all(A), greater<int>());
  sort(all(B), greater<int>());
  sort(all(C), greater<int>());
  priority_queue<tuple<ll, int, int, int>> Q;
  auto func = [](int a, int b, int c) -> ll {
    return 1LL*a*b + 1LL*b*c + 1LL*c*a;
  };
  set<tuple<int, int, int>> st;
  Q.push({func(A[0], B[0], C[0]), 0, 0, 0});
  st.insert({0, 0, 0});
  ll ans = 0;
  rep(i, k) {
    auto [val, a, b, c] = Q.top(); Q.pop();
    if(a+1 < n && !st.count({a+1, b, c})) {
      Q.push({func(A[a+1], B[b], C[c]), a+1, b, c});
      st.insert({a+1, b, c});
    }
    if(b+1 < n && !st.count({a, b+1, c})) {
      Q.push({func(A[a], B[b+1], C[c]), a, b+1, c});
      st.insert({a, b+1, c});
    }
    if(c+1 < n && !st.count({a, b, c+1})) {
      Q.push({func(A[a], B[b], C[c+1]), a, b, c+1});
      st.insert({a, b, c+1});
    }
    ans = val;
  }
  cout << ans << endk;
  return 0;
}
