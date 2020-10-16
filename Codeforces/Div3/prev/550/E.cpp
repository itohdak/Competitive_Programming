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

vector<int> toInt(string s) {
  vector<int> ret(s.size());
  rep(i, s.size()) ret[i] = s[i]-'a';
  return ret;
}
string toString(vector<int>& v) {
  string ret(v.size(), ' ');
  rep(i, v.size()) {
    ret[i] = char('a'+v[i]);
  }
  return ret;
}
void solve() {
  int k; cin >> k;
  string s, t; cin >> s >> t;
  auto si = toInt(s), ti = toInt(t);
  vector<int> sum(k+1);
  rrep(i, k) {
    sum[i+1] += si[i] + ti[i];
    sum[i] += sum[i+1]/26;
    sum[i+1] %= 26;
  }
  vector<int> ans(k);
  int c = sum[0]*26;
  rep(i, k) {
    ans[i] = (sum[i+1]+c)/2;
    c = ((sum[i+1]+c)%2)*26;
  }
  cout << toString(ans) << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
