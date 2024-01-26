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
  int n, m; cin >> n >> m;
  string s, t; cin >> s >> t;
  int l = 0;
  bool flag = true;
  while(l < n) {
    int i = find(all(t), s[l]) - begin(t);
    if(i == m || l - i < 0) {
      cout << "No" << endk;
      return 0;
    }
    if(!flag) {
      rep(j, i+1) {
	if(t[j] != s[l-i+j]) {
	  cout << "No" << endk;
	  return 0;
	}
      }
    }
    int next = l-i+m;
    REP(j, i, m) {
      if(l-i+j >= n) {
	cout << "No" << endk;
	return 0;
      }
      if(t[j] != s[l-i+j]) {
	next = l-i+j;
	break;
      }
    }
    if(next == l-i+m) {
      flag = true;
    } else {
      flag = false;
    }
    l = next;
  }
  cout << "Yes" << endk;
  return 0;
}
