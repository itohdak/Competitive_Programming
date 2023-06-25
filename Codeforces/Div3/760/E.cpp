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
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  int n; cin >> n;
  vector<int> B(n); rep(i, n) cin >> B[i];
  ll cum = accumulate(all(B), 0LL);
  ll tmp = 1LL*n*(n+1)/2;
  if(cum%tmp) {
    cout << "NO" << endk;
    return;
  }
  cum /= tmp;
  vector<int> A(n);
  rep(i, n) {
    ll tmp = cum-(B[i]-B[(i-1+n)%n]);
    if(tmp<n || tmp%n) {
      cout << "NO" << endk;
      return;
    }
    A[i] = tmp/n;
  }
  cout << "YES" << endk;
  rep(i, n) cout << A[i] << ' '; cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
