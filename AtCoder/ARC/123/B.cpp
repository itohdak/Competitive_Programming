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
  vector<ll> B(n); rep(i, n) cin >> B[i];
  vector<ll> C(n); rep(i, n) cin >> C[i];
  int ans = 0;
  sort(all(A));
  sort(all(B));
  sort(all(C));
  int j = 0, k = 0;
  rep(i, n) {
    int nextj = lower_bound(B.begin()+j, B.end(), A[i]+1) - B.begin();
    if(nextj == n) break;
    int nextk = lower_bound(C.begin()+k, C.end(), B[nextj]+1) - C.begin();
    if(nextk == n) break;
    ans++;
    j = nextj+1;
    k = nextk+1;
  }
  cout << ans << endk;
  return 0;
}
