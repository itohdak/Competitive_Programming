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
  int n; cin >> n;
  vector<int> A(n); rep(i, n) cin >> A[i];
  vector<vector<int>> pos(2);
  vector<int> cnt2(n+1);
  rep(i, n) {
    pos[A[i]>0].push_back(i);
    cnt2[i+1] = cnt2[i]+(A[i]==2);
  }
  pos[0].push_back(n);
  pos[1].push_back(n);
  int ans = 0;
  int l = 0;
  while(l < n) {
    int r1 = *lower_bound(all(pos[1]), l);
    if(r1 == n) {
      ans += n-l;
      l = n;
    } else {
      int r2 = *lower_bound(all(pos[0]), r1);
      if(l == r1) {
	ans++;
	l = r2+1;
      } else {
	ans += (r1-1)-l;
	ans++;
	if(cnt2[r2]-cnt2[r1] > 0) {
	  l = r2+1;
	} else {
	  l = r2;
	}
      }
    }
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
