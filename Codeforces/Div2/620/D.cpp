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
  string s; cin >> s;
  int l = 0, r = 0;
  int pos = 0, neg = 0;
  vector<pair<int, int>> posneg, negpos;
  while(l < n-1) {
    while(r < n-1 && s[r] == s[l]) r++;
    if(s[l] == '<') {
      pos = r-l;
      negpos.push_back({neg, pos});
    } else {
      neg = r-l;
      posneg.push_back({pos, neg});
    }
    l = r;
  }
  if(s[n-2] == '<') posneg.push_back({pos, 0});
  else negpos.push_back({neg, 0});
  {
    vector<int> ans(n);
    int i = 0;
    int cur = n;
    for(auto ele: posneg) {
      for(int j=i+ele.first; j>=i; j--) {
        ans[j] = cur--;
      }
      for(int j=i+ele.first+1; j<i+ele.first+ele.second; j++) {
        ans[j] = cur--;
      }
      i += ele.first + ele.second;
    }
    rep(i, n) cout << (ans[i] ? ans[i] : cur) << ' '; cout << endk;
  }
  {
    vector<int> ans(n);
    int i = 0;
    int cur = 1;
    for(auto ele: negpos) {
      for(int j=i+ele.first; j>=i; j--) {
        ans[j] = cur++;
      }
      for(int j=i+ele.first+1; j<i+ele.first+ele.second; j++) {
        ans[j] = cur++;
      }
      i += ele.first + ele.second;
    }
    rep(i, n) cout << (ans[i] ? ans[i] : cur) << ' '; cout << endk;
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
