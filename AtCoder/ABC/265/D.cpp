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
  int n; ll p, q, r; cin >> n >> p >> q >> r;
  vector<int> A(n); rep(i, n) cin >> A[i];
  vector<ll> cum(n+1); rep(i, n) cum[i+1] = cum[i] + A[i];
  int x = 0;
  while(x < n) {
    int y = lower_bound(all(cum), cum[x]+p) - begin(cum);
    if(y < n+1 && cum[y]-cum[x] == p) {
      int z = lower_bound(all(cum), cum[y]+q) - begin(cum);
      if(z < n+1 && cum[z]-cum[y] == q) {
        int w = lower_bound(all(cum), cum[z]+r) - begin(cum);
        if(w < n+1 && cum[w]-cum[z] == r) {
          cout << "Yes" << endk;
          return 0;
        }
      }
    }
    x++;
  }
  cout << "No" << endk;
  return 0;
}