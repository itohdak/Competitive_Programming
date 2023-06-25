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

vector<vector<int>> pw(60);
void solve() {
  ll n; cin >> n;
  vector<int> N;
  while(n) {
    N.push_back(n%10);
    n /= 10;
  }
  reverse(all(N));
  int ans = inf;
  rep(i, 60) {
    int cnt = 0;
    int l = 0;
    int r = 0;
    while(l < N.size() || r < pw[i].size()) {
      if(r < pw[i].size()) {
        while(l < N.size() && N[l] != pw[i][r]) {
          l++;
          cnt++;
        }
        if(l == N.size()) {
          while(r < pw[i].size()) {
            r++;
            cnt++;
          }
          break;
        }
        if(N[l] == pw[i][r]) {
          l++;
          r++;
        }
      } else {
        while(l < N.size()) {
          l++;
          cnt++;
        }
      }
    }
    chmin(ans, cnt);
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll p = 1;
  rep(i, 60) {
    if(i) p *= 2;
    ll tmp = p;
    while(tmp) {
      pw[i].push_back(tmp%10);
      tmp /= 10;
    }
    reverse(all(pw[i]));
  }
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
