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
  int n, k; cin >> n >> k;
  string a, b; cin >> a >> b;
  vector<int> cntA(26), cntB(26);
  rep(i, n) {
    cntA[a[i]-'a']++;
    cntB[b[i]-'a']++;
  }
  rep(i, 26) {
    if(cntA[i] < cntB[i]) {
      cout << "No" << endk;
      return;
    }
    if((cntA[i]-cntB[i]) % k != 0) {
      cout << "No" << endk;
      return;
    }
    if(i < 26) cntA[i+1] += cntA[i]-cntB[i];
  }
  cout << "Yes" << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
