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
  int n, k; cin >> n >> k;
  set<int> st;
  auto query = [&]() {
    assert(st.size() == k);
    cout << "? ";
    for(int i: st) cout << i+1 << ' ';
    cout << endl;
    int pos; ll a; cin >> pos >> a;
    return make_pair(pos-1, a);
  };
  rep(i, k) st.insert(i);
  vector<pair<ll, int>> prev;
  rep(i, n-k+1) {
    auto [pos, a] = query();
    prev.push_back({a, pos});
    st.erase(pos);
    if(i != n-k) st.insert(k+i);
  }
  vector<int> unknown;
  for(int i: st) unknown.push_back(i);
  sort(all(prev));
  st.insert(prev[0].second);
  st.insert(prev[1].second);
  int small = 0, big = 0;
  for(int i: unknown) {
    st.erase(i);
    auto [pos, a] = query();
    if(pos == prev[0].second) big++;
    else small++;
    st.insert(i);
  }
  cout << "! " << small+1 << endl;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
