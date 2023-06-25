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
  vector<vector<int>> A(n, vector<int>(5));
  rep(i, n) rep(j, 5) cin >> A[i][j];
  rep(i, 5) REP(j, i+1, 5) {
    vector<int> cnt(3);
    bool ok = true;
    rep(k, n) {
      if(A[k][i] && A[k][j]) cnt[2]++;
      else if(A[k][i]) cnt[0]++;
      else if(A[k][j]) cnt[1]++;
      else {
        ok = false;
        break;
      }
    }
    if(!ok) continue;
    if(cnt[0] <= n/2 && cnt[1] <= n/2) {
      cout << "YES" << endk;
      return;
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
