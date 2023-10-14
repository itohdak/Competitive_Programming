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
  string t; cin >> t;
  int tsize = t.size();
  vector<int> ans;
  rep(i, n) {
    string s; cin >> s;
    int ssize = s.size();
    int diff = abs(tsize-ssize);
    if(diff > 1) {
      continue;
    } else if(diff == 0) {
      int cnt = 0;
      rep(j, tsize) {
	if(t[j] != s[j]) cnt++;
      }
      if(cnt <= 1) {
	ans.push_back(i);
      }
    } else if(diff == 1) {
      string a = (tsize < ssize ? s : t);
      string b = (tsize < ssize ? t : s);
      int j = 0;
      while(j < b.size()) {
	if(a[j] != b[j]) break;
	j++;
      }
      while(j < b.size()) {
	if(a[j+1] != b[j]) break;
	j++;
      }
      if(j == b.size()) ans.push_back(i);
      // rep(j, a.size()) {
      // 	if(a.substr(0, j) + a.substr(j+1) == b) {
      // 	  ans.push_back(i);
      // 	  break;
      // 	}
      // }
    }
  }
  cout << ans.size() << endk;
  for(int a: ans) cout << a+1 << ' ';
  cout << endk;
  return 0;
}
