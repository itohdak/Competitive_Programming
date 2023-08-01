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
  vector<int> cnt(10);
  rep(i, 5) {
    vector<int> A(n);
    rep(j, n) cin >> A[j];
    vector<int> cnt2(10);
    rep(j, n) cnt2[A[j]]++;
    // cout << cnt << endk << cnt2 << endk;
    if(i == 0) {
      cout << "- 0" << endl;
      cnt = cnt2;
    } else {
      int dec = -1, inc = -1;
      rep(j, 10) {
	if(cnt2[j] < cnt[j]) dec = j;
	if(cnt2[j] > cnt[j]) inc = j;
      }
      if(dec != -1) {
	vector<int> del;
	rep(j, n) {
	  if(A[j] != inc) {
	    del.push_back(j);
	  }
	}
	if(n-del.size() == 1) {
	  cout << "! " << find(all(A), inc)-begin(A)+1 << endl;
	  break;
	} else {
	  cout << "- ";
	  cout << del.size() << ' ';
	  for(int d: del) cout << d+1 << ' ';
	  cout << endl;
	  n -= del.size();
	  rep(j, 10) if(j != inc) cnt2[j] = 0;
	}
      } else {
	cout << "- 0" << endl;
      }
      cnt = cnt2;
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
