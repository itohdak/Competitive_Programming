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
  vector<int> B(7); rep(i, 7) cin >> B[i];
  rep(i, 7) REP(j, i+1, 7) REP(k, j+1, 7) {
    vector<int> A = {B[i], B[j], B[k]};
    vector<int> B_;
    rep(l, 1<<3) {
      if(l == 0) continue;
      int sum = 0;
      rep(m, 3) {
        if((l>>m)&1) sum += A[m];
      }
      B_.push_back(sum);
    }
    sort(all(B_));
    bool ok = true;
    rep(l, 7) if(B[l] != B_[l]) ok = false;
    if(ok) {
      cout << A[0] << ' ' << A[1] << ' ' << A[2] << endk;
      return;
    }
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
