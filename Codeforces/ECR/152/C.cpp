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
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  int n, m; cin >> n >> m;
  string s; cin >> s;
  vector<int> L(m), R(m);
  rep(i, m) {
    cin >> L[i] >> R[i];
    L[i]--;
  }
  vector<int> cnt(n+1);
  vector<vector<int>> P(2);
  P[0].push_back(-1);
  P[1].push_back(-1);
  rep(i, n) {
    P[s[i]-'0'].push_back(i);
    cnt[i+1] = cnt[i] + (s[i]-'0');
  }
  P[0].push_back(n);
  P[1].push_back(n);
  set<pair<int, int>> st;
  bool add = false;
  rep(i, m) {
    int l = L[i], r = R[i];
    int n1 = cnt[r]-cnt[l];
    if(cnt[r]-cnt[r-n1] == n1) {
      add = true;
      continue;
    }
    int l2 = *(--upper_bound(all(P[1]), l-1))+1;
    int r2 = *lower_bound(all(P[0]), r);
    st.insert({l2, r2});
  }
  cout << add+st.size() << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
