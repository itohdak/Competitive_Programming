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
  string s, t; cin >> s >> t;
  vector<int> cntS(26), cntT(26);
  rep(i, n) {
    cntS[s[i]-'a']++;
    cntT[t[i]-'a']++;
  }
  rep(i, 26) {
    if(cntS[i] != cntT[i]) {
      cout << -1 << endk;
      return 0;
    }
  }
  vector<int> ans;
  auto shift = [&](int x) {
    ans.push_back(x);
    string a = s.substr(0, n-x), b = s.substr(n-x);
    reverse(all(b));
    s = b+a;
    // return b+a;
  };
  rep(i, n) {
    int j = 0;
    while(s[j] != t[i]) j++;
    shift(n-(j+1));
    shift(1);
    shift(n);
  }
  assert(s == t);
  cout << ans.size() << endk;
  for(int a: ans) cout << a << ' ';
  cout << endk;
  return 0;
}
