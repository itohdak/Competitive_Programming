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
  vector<int> A(n);
  rep(i, n) cin >> A[i];
  int r = n-1;
  set<int> st;
  st.insert(A[r]);
  while(r > 0 && A[r-1] > A[r]) {
    st.insert(A[r-1]);
    r--;
  }
  int mx = st.size();
  int mxl = 0, mxr = r;
  rep(i, n) {
    if(i && A[i] <= A[i-1]) break;
    while(r < n && st.count(A[i])) st.erase(A[r++]);
    if(st.count(A[i])) break;
    st.insert(A[i]);
    if((int)st.size() > mx) {
      mx = st.size();
      mxl = i+1;
      mxr = r;
    }
  }
  deque<pair<int, char>> q;
  rep(i, mxl) q.push_back({A[i], 'L'});
  REP(i, mxr, n) q.push_back({A[i], 'R'});
  string ans;
  while(!q.empty()) {
    if(q.back().first >= q.front().first) {
      ans += q.front().second;
      q.pop_front();
    } else {
      ans += q.back().second;
      q.pop_back();
    }
  }
  assert(mx == ans.size());
  cout << ans.size() << endk;
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
