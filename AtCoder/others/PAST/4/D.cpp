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
  string s; cin >> s;
  int x = 0, y = 0, z = 0;
  vector<int> pos;
  rep(i, n) if(s[i] == '#') pos.push_back(i);
  rep(i, pos.size()) {
    if(i == 0) {
      chmax(x, pos[i]);
    }
    if(i == pos.size()-1) {
      chmax(y, n-pos[i]-1);
    }
    if(i+1 < pos.size()) {
      chmax(z, pos[i+1]-pos[i]-1);
    }
  }
  chmax(y, z-x);
  cout << x << ' ' << y << endk;
  return 0;
}
