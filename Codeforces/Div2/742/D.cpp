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
  string s; cin >> s;
  int n; cin >> n;
  int sz = s.size();
  vector<int> D(sz);
  rep(i, sz) D[i] = s[i]-'0';
  int pw = 1;
  vector<int> A;
  rrep(i, sz) {
    rep(j, D[i]) A.push_back(pw);
    pw *= 10;
  }
  reverse(all(A));
  while(A.size() < n) {
    vector<int> tmp;
    while(1) {
      if(A.back() == 1) {
        tmp.push_back(A.back());
        A.pop_back();
      } else {
        int back = A.back(); A.pop_back();
        rep(i, 10) A.push_back(back/10);
        while(tmp.size()) {
          A.push_back(tmp.back());
          tmp.pop_back();
        }
        break;
      }
    }
  }
  while(A.size() > n) {
    int back = A.back(); A.pop_back();
    int back2 = A.back(); A.pop_back();
    A.push_back(back+back2);
  }
  rep(i, n) cout << A[i] << ' '; cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
