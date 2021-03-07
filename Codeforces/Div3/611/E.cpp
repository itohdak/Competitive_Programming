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
  vector<int> X(n), cnt(n);
  rep(i, n) {
    cin >> X[i];
    X[i]--;
    cnt[X[i]]++;
  }
  set<int> st1, st2;
  rep(i, n) {
    int rem = cnt[i];
    for(int j=i-1; j<=i+1; j++) {
      if(rem == 0) break;
      if(st1.count(j)) continue;
      st1.insert(j);
      rem--;
    }
  }
  rep(i, n) {
    if(cnt[i] == 0) continue;
    bool ok = false;
    for(int j=i-1; j<=i+1; j++) {
      if(st2.count(j)) ok = true;
    }
    if(ok) continue;
    st2.insert(i+1);
  }
  cout << st2.size() << ' ' << st1.size() << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
