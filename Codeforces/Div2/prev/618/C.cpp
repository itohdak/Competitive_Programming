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
  vector<ll> orL(n+1);
  vector<ll> orR(n+1);
  ll orAll = 0;
  rep(i, n) orL[i+1] = orL[i] | A[i];
  rrep(i, n) orR[i] = orR[i+1] | A[i];
  rep(i, n) orAll |= A[i];
  ll mx = 0;
  int mxi = 0;
  rep(i, n) {
    if(orAll-(orL[i]|orR[i+1]) > mx) {
      mx = orAll-(orL[i]|orR[i+1]);
      mxi = i;
    }
  }
  cout << A[mxi] << ' ';
  rep(i, n) if(i != mxi) cout << A[i] << ' ';
  cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
