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
  vector<ll> T0, T1, T2;
  rep(i, n) {
    ll t; int a, b; cin >> t >> a >> b;
    if(a && b) T2.push_back(t);
    else if(a) T0.push_back(t);
    else if(b) T1.push_back(t);
  }
  sort(all(T0));
  sort(all(T1));
  sort(all(T2));
  int n0 = T0.size(), n1 = T1.size(), n2 = T2.size();
  vector<ll> sum0(n0+1), sum1(n1+1), sum2(n2+1);
  rep(i, n0) sum0[i+1] = sum0[i] + T0[i];
  rep(i, n1) sum1[i+1] = sum1[i] + T1[i];
  rep(i, n2) sum2[i+1] = sum2[i] + T2[i];
  ll ans = longinf;
  rep(i, n2+1) {
    if(0<=k-i && k-i<=n0 && k-i<=n1) chmin(ans, sum2[i]+sum0[k-i]+sum1[k-i]);
  }
  cout << (ans==longinf ? -1 : ans) << endk;
  return 0;
}
