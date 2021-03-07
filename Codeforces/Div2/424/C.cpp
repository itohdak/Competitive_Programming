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
  int k, n; cin >> k >> n;
  vector<ll> A(k); rep(i, k) cin >> A[i];
  vector<ll> B(n); rep(i, n) cin >> B[i];
  vector<ll> sum(k+1); rep(i, k) sum[i+1] = sum[i] + A[i];
  set<ll> st;
  rep(i, k) st.insert(sum[i+1]);
  set<ll> ans;
  rep(i, k) {
    bool ok = true;
    ll tmp = B[0]-sum[i+1];
    rep(j, n) {
      if(!st.count(B[j]-tmp)) ok = false;
    }
    if(ok) ans.insert(tmp);
  }
  // cout << st << endk;
  // cout << ans << endk;
  cout << ans.size() << endk;
  return 0;
}
