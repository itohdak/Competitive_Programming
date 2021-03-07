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
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  int n; cin >> n;
  vector<ll> A(n);
  rep(i, n) cin >> A[i];
  vector<ll> remL(n+1), remR(n+1);
  vector<bool> okL(n+1), okR(n+1);
  okL[0] = true;
  rep(i, n) {
    remL[i+1] = A[i] - remL[i];
    if(okL[i] && remL[i+1] >= 0) okL[i+1] = true;
  }
  if(okL[n] && remL[n] == 0) {
    cout << "YES" << endk;
    return;
  }
  okR[n] = true;
  rrep(i, n) {
    remR[i] = A[i] - remR[i+1];
    if(okR[i+1] && remR[i] >= 0) okR[i] = true;
  }
  // cout << remL << endk;
  // cout << okL << endk;
  // cout << remR << endk;
  // cout << okR << endk;
  rep(i, n) {
    if(okL[i] && i+2<=n && okR[i+2]) {
      ll a1 = remL[i], a2 = A[i+1], a3 = A[i], a4 = remR[i+2];
      if(a1 <= a2 && a3 >= a4 && a2-a1 == a3-a4) {
        cout << "YES" << endk;
        return;
      }
    }
  }
  cout << "NO" << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
