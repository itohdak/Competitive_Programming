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
  vector<int> P(n);
  vector<int> pos(n);
  set<int> st;
  rep(i, n) {
    cin >> P[i];
    P[i]--;
    pos[P[i]] = i;
    st.insert(P[i]);
  }
  vector<int> f, b;
  int r = n;
  while(st.size()) {
    int p = pos[*st.begin()];
    f.push_back(P[p]);
    st.erase(P[p]);
    for(int i=r-1; i>p; i--) {
      b.push_back(P[i]);
      st.erase(P[i]);
    }
    r = p;
  }
  reverse(all(b));
  for(auto a: f) cout << a+1 << ' ';
  for(auto a: b) cout << a+1 << ' ';
  cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
