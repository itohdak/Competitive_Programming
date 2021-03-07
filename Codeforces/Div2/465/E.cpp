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
  string e; cin >> e;
  int p, m; cin >> p >> m;
  int n = e.size();
  deque<int> q;
  vector<int> L;
  map<int, int> mp, mp2;
  rep(i, n) {
    if(e[i] == '(') {
      q.push_back(i);
      L.push_back(i);
    } else if(e[i] == ')') {
      mp[q.back()] = i;
      mp2[i] = q.back();
      q.pop_back();
    }
  }
  map<pair<int, int>, vector<int>> dpmax, dpmin;
  auto dfs = [&](auto dfs, int l, int r) -> void {
    // cout << "entering " << l << ' ' << r << endl;
    if(r-l > 3) {
      if(e[l] == '(') dfs(dfs, l+1, mp[l]);
      if(e[r-1] == ')') dfs(dfs, mp2[r-1]+1, r-1);
      vector<int> vmax(p+1, -inf), vmin(p+1, inf);
      rep(i, p+1) {
        if(e[l] != '(' && i) continue;
        int amax = (e[l] == '(' ? dpmax[{l+1, mp[l]}][i] : e[l]-'0');
        int amin = (e[l] == '(' ? dpmin[{l+1, mp[l]}][i] : e[l]-'0');
        rep(j, p+1) {
          if(e[r-1] != ')' && j) continue;
          int bmax = (e[r-1] == ')' ? dpmax[{mp2[r-1]+1, r-1}][j] : e[r-1]-'0');
          int bmin = (e[r-1] == ')' ? dpmin[{mp2[r-1]+1, r-1}][j] : e[r-1]-'0');
          // if(l == 12) {
          //   cout << i << ' ' << j << endk;
          //   cout << l+1 << ' ' << mp[l] << endk;
          //   cout << amax << ' ' << amin << endk;
          //   cout << bmax << ' ' << bmin << endk;
          // }
          if(i+j+1 <= p) {
            chmax(vmax[i+j+1], amax+bmax);
            chmin(vmin[i+j+1], amin+bmin);
          }
          if(i+j <= p) {
            chmax(vmax[i+j], amax-bmin);
            chmin(vmin[i+j], amin-bmax);
          }
        }
      }
      dpmax[{l, r}] = vmax;
      dpmin[{l, r}] = vmin;
    } else {
      vector<int> vmax(p+1, -inf), vmin(p+1, inf);
      int a = e[l]-'0', b = e[r-1]-'0';
      chmax(vmax[0], a-b);
      chmin(vmin[0], a-b);
      chmax(vmax[1], a+b);
      chmin(vmin[1], a+b);
      dpmax[{l, r}] = vmax;
      dpmin[{l, r}] = vmin;
    }
    // cout << "end of " << l << ' ' << r << endl;
    // cout << dpmax << endl << dpmin << endl;
  };
  dfs(dfs, 1, n-1);
  cout << dpmax[{1, n-1}][p] << endk;
  return 0;
}
