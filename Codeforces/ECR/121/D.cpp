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
  vector<int> A(n); rep(i, n) cin >> A[i];
  map<int, int> cnt;
  rep(i, n) cnt[A[i]]++;
  vector<int> B;
  for(auto [_, c]: cnt) B.push_back(c);
  int m = B.size();
  vector<int> cum(m+1);
  rep(i, m) cum[i+1] = cum[i] + B[i];
  vector<ll> pw(21);
  pw[0] = 1;
  rep(i, 20) pw[i+1] = pw[i]*2;
  ll ans = longinf;
  rep(i, 21) rep(j, 21) rep(k, 21) {
    ll tmp = 0;
    int p1 = 0;
    int p2 = upper_bound(all(cum), cum[p1]+pw[i]) - begin(cum);
    p2--;
    int p3 = upper_bound(all(cum), cum[p2]+pw[j]) - begin(cum);
    p3--;
    if(cum[m]-cum[p3] > pw[k]) continue;
    tmp += pw[i]-(cum[p2]-cum[p1]);
    tmp += pw[j]-(cum[p3]-cum[p2]);
    tmp += pw[k]-(cum[m]-cum[p3]);
    if(ans > tmp) {
      chmin(ans, tmp);
      // cout << "===" << endk;
      // cout << i << ' ' << j << ' ' << k << endk;
      // cout << p1 << ' ' << p2 << ' ' << p3 << endk;
      // cout << cum << endk;
      // cout << pw[i]-(cum[p2]-cum[p1]) << ' ' << pw[j]-(cum[p3]-cum[p2]) << ' ' << pw[k]-(cum[m]-cum[p3]) << endk;
    }
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
