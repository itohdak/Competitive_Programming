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
  ll n, a, b; cin >> n >> a >> b;
  vector<ll> S(n); rep(i, n) cin >> S[i];
  ll sum = accumulate(all(S), 0LL);
  ll mx = *max_element(all(S));
  ll mn = *min_element(all(S));
  cout << fixed << setprecision(10);
  if(mx-mn == 0) cout << -1 << endk;
  else {
    ld p = (ld)b/(mx-mn);
    cout << p << ' ' << a-(ld)sum/n*p << endk;
  }
  return 0;
}
