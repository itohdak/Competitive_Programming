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

string inv(string s) {
  int n = s.size();
  string ret(n, '0');
  rep(i, s.size()) if(s[i] == '0') ret[i] = '1';
  return ret;
}
void solve() {
  int n, k; cin >> n >> k;
  string s; cin >> s;
  unordered_set<string> st;
  int mx = 20;
  if(k > mx) {
    int cnt1 = 0;
    rep(i, k-mx) if(s[i] == '1') cnt1++;
    rep(i, n-k+1) {
      if(cnt1 == k-mx) st.insert(inv(s.substr(i+k-mx, mx)));
      if(s[i] == '1') cnt1--;
      if(s[i+k-mx] == '1') cnt1++;
    }
    rep(i, 1<<mx) {
      string tmp(mx, '0');
      rep(j, mx) if((i>>j)&1) tmp[mx-1-j] = '1';
      if(!st.count(tmp)) {
        cout << "YES" << endk;
        cout << string(k-mx, '0') + tmp << endk;
        return;
      }
    }
    assert(false);
  } else {
    rep(i, n-k+1) st.insert(inv(s.substr(i, k)));
    rep(i, 1<<k) {
      string tmp(k, '0');
      rep(j, k) if((i>>j)&1) tmp[k-1-j] = '1';
      if(!st.count(tmp)) {
        cout << "YES" << endk;
        cout << tmp << endk;
        return;
      }
    }
    cout << "NO" << endk;
    return;
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
