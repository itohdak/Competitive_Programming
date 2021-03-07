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
  int a, b, k; cin >> a >> b >> k;
  vector<int> A(k); rep(i, k) cin >> A[i];
  vector<int> B(k); rep(i, k) cin >> B[i];
  ll cnt = 1LL*k*(k-1)/2;
  vector<int> cntA(a), cntB(b);
  rep(i, k) cntA[A[i]-1]++;
  rep(i, k) cntB[B[i]-1]++;
  rep(i, a) cnt -= 1LL*cntA[i]*(cntA[i]-1)/2;
  rep(i, b) cnt -= 1LL*cntB[i]*(cntB[i]-1)/2;
  cout << cnt << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
