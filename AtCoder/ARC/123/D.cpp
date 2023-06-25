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
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<ll> dB(n), dC(n);
  REP(i, 1, n) {
    dB[i] = dB[i-1];
    dC[i] = dC[i-1];
    if(A[i-1] < A[i]) dB[i] += A[i]-A[i-1];
    else              dC[i] += A[i]-A[i-1];
  }
  vector<pair<ll, int>> D;
  ll b0 = mod, c0 = A[0]-b0;
  rep(i, n) {
    D.push_back({b0+dB[i], i});
    D.push_back({abs(c0+dC[i]), n+i});
  }
  sort(all(D));
  int j = D[n].second;
  if(j >= n) {
    c0 = -dC[j-n];
    b0 = A[0]-c0;
  } else {
    b0 = -dB[j];
    c0 = A[0]-b0;
  }
  ll ans = 0;
  rep(i, n) {
    ans += abs(b0+dB[i]);
    ans += abs(c0+dC[i]);
  }
  cout << ans << endk;
  // vector<ll> sumB(n+1), sumC(n+1);
  // rep(i, n) sumB[i+1] = sumB[i] + dB[i];
  // rep(i, n) sumC[i+1] = sumC[i] + dC[i];
  // ll ans = LONG_LONG_MAX;
  // rep(i, n) {
  //   // Bi=0の場合
  //   ll sumBp = (sumB[n]-sumB[i])-dB[i]*(n-i);
  //   ll sumBn = dB[i]*i-sumB[i];
  //   ll c0 = A[i]-dC[i];
  //   int j = lower_bound(all(dC), -c0, greater<ll>()) - dC.begin();
  //   ll sumCp = c0*j+sumC[j];
  //   ll sumCn = -(sumC[n]-sumC[j])-c0*(n-j);
  //   chmin(ans, sumBp+sumBn+sumCp+sumCn);
  // }
  // rep(i, n) {
  //   // Ci=0の場合
  //   ll sumCp = -dC[i]*i+sumC[i];
  //   ll sumCn = -(sumC[n]-sumC[i])+dC[i]*(n-i);
  //   ll b0 = A[i]-dB[i];
  //   int j = lower_bound(all(dB), -b0) - dB.begin();
  //   ll sumBp = (sumB[n]-sumB[j])+b0*(n-j);
  //   ll sumBn = -b0*j-sumB[j];
  //   chmin(ans, sumBp+sumBn+sumCp+sumCn);
  // }
  // // cout << dB << dC << endk;
  // cout << ans << endk;
  return 0;
}
