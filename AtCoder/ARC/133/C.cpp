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
  int h, w; ll k; cin >> h >> w >> k;
  vector<ll> A(h), B(w);
  rep(i, h) cin >> A[i];
  rep(j, w) cin >> B[j];
  ll suma = accumulate(all(A), 0LL);
  ll sumb = accumulate(all(B), 0LL);
  if(suma % k != sumb % k) {
    cout << -1 << endk;
    return 0;
  }
  rep(i, h) A[i] = ((k-1)*w-A[i])%k;
  rep(j, w) B[j] = ((k-1)*h-B[j])%k;
  cout << (k-1)*h*w - max(accumulate(all(A), 0LL), accumulate(all(B), 0LL)) << endk;
  return 0;
}
