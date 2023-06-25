#include <bits/stdc++.h>
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

vector<vector<int>> ans;
void Eratosthenes(int n) {
  ans.assign(n+1, vector<int>(2));
  for(int i=3; i<=n; i++) {
    ans[i][1] = 1;
  }
  for(int i=2; i<=n; i++) {
    for(int j=2; i*j<=n; j++) {
      chmax(ans[i*j][1], ans[i][0]+1);
      chmax(ans[i*j][1], ans[i][1]);
    }
    for(int j=2; (i+1)*j<=n; j++) {
      if(j == 2) {
        chmax(ans[(i+1)*j][0], ans[i][0]+1);
        chmax(ans[(i+1)*j][0], ans[i][1]);
      } else {
        chmax(ans[(i+1)*j][1], ans[i][0]+2);
        chmax(ans[(i+1)*j][1], ans[i][1]+1);
      }
    }
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t; cin >> t;
  Eratosthenes(1000000);
  rep(i, t) {
    int n; cin >> n;
    cout << "Case #" << i+1 << ": " << ans[n][1] << endk;
  }
  return 0;
}
