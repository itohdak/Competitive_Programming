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

bool DPX[1005][20005];
bool DPY[1005][20005];
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, x, y; cin >> n >> x >> y;
  vector<int> A(n); rep(i, n) cin >> A[i];
  vector<int> Ax, Ay;
  rep(i, n) {
    if(i%2) {
      Ay.push_back(A[i]);
    } else {
      Ax.push_back(A[i]);
    }
  }
  int offset=10002;
  DPX[0][offset] = true;
  rep(i, Ax.size()) {
    rep(j, 20005) {
      if(!DPX[i][j]) continue;
      if(j+Ax[i] < 20005) DPX[i+1][j+Ax[i]] = true;
      if(i > 0 && j-Ax[i] >= 0) DPX[i+1][j-Ax[i]] = true;
    }
  }
  DPY[0][offset] = true;
  rep(i, Ay.size()) {
    rep(j, 20005) {
      if(!DPY[i][j]) continue;
      if(j+Ay[i] < 20005) DPY[i+1][j+Ay[i]] = true;
      if(j-Ay[i] >= 0) DPY[i+1][j-Ay[i]] = true;
    }
  }
  if(DPX[Ax.size()][offset+x] && DPY[Ay.size()][offset+y]) {
    cout << "Yes" << endk;
  } else {
    cout << "No" << endk;
  }
  return 0;
}
