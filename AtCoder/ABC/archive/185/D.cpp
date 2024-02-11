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
  ll n, m; cin >> n >> m;
  vector<ll> A(m); rep(i, m) cin >> A[i];
  if(m == 0) {
    cout << 1 << endk;
    return 0;
  }
  sort(all(A));
  vector<ll> D;
  rep(i, m-1) if(A[i+1] - A[i] - 1) D.push_back(A[i+1] - A[i] - 1);
  if(A[0] - 1) D.push_back(A[0] - 1);
  if(n - A[m-1]) D.push_back(n - A[m-1]);
  ll mn = (D.size() ? *min_element(all(D)) : 0);
  ll ans = 0;
  rep(i, D.size()) ans += (D[i]+mn-1) / mn;
  cout << ans << endk;
  return 0;
}
