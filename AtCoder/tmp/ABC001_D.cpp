#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<string> S(n);
  rep(i, n) cin >> S[i];
  map<int, string> mp;
  rep(i, 61) {
    int tmp = i;
    string s(2, ' ');
    rep(j, 2) {
      s[1-j] = char(tmp%10+'0');
      tmp /= 10;
    }
    mp[i] = s;
  }
  multiset<pair<int, int>> st;
  rep(i, n) {
    int hs = atoi(S[i].substr(0, 2).c_str());
    int ms = atoi(S[i].substr(2, 2).c_str());
    ms = ms/5*5;
    int he = atoi(S[i].substr(5, 2).c_str());
    int me = atoi(S[i].substr(7, 2).c_str());
    me = (me+4)/5*5;
    st.insert({hs*60+ms, -1});
    st.insert({he*60+me, +1});
  }
  int cnt = 0;
  for(auto ele: st) {
    if(cnt == 0) {
      cout << mp[ele.first/60] << mp[ele.first%60] << '-';
    }
    cnt -= ele.second;
    if(cnt == 0) {
      cout << mp[ele.first/60] << mp[ele.first%60] << '\n';
    }
  }
  return 0;
}
