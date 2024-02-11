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
  string s; cin >> s;
  if(s[0] == '1') {
    cout << "No" << endk;
  } else {
    vector<int> v;
    map<int, int> mp = {{0, 3},
                        {1, 2}, {2, 4},
                        {3, 1}, {4, 3}, {5, 5},
                        {6, 0}, {7, 2}, {8, 4}, {9, 6}};
    rep(i, 10) {
      if(s[i] == '1') v.push_back(mp[i]);
    }
    sort(all(v));
    v.erase(unique(all(v)), end(v));
    if(v.size()) {
      bool ok = false;
      rep(i, v.size()-1) {
        if(v[i+1]-v[i] > 1) {
          ok = true;
        }
      }
      if(ok) cout << "Yes" << endk;
      else cout << "No" << endk;
    } else {
      cout << "No" << endk;
    }
  }
  return 0;
}
