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
  rep(i, n) {
    cin >> A[i];
    A[i]--;
  }
  vector<int> ans(n, -1);
  set<int> st, st2;
  rep(i, n) st.insert(i);
  int cnt = 0;
  rep(i, n) {
    if(st.count(A[i])) {
      ans[i] = A[i];
      st.erase(A[i]);
      cnt++;
    } else {
      st2.insert(i);
    }
  }
  // assert(st.size() == st2.size());
  vector<int> ng;
  auto itr=st.begin(), itr2=st2.begin();
  rep(i, st.size()) {
    ans[*itr2] = *itr;
    if(*itr == *itr2) ng.push_back(*itr);
    itr++; itr2++;
  }
  if(ng.size() > 1) {
    rep(i, ng.size()) ans[ng[i]] = ng[(i+1)%ng.size()];
  } else if(ng.size() == 1) {
    int target = -1;
    rep(i, n) {
      if(ans[i] == A[ng[0]]) {
        target = i;
        break;
      }
    }
    swap(ans[ng[0]], ans[target]);
  }
  rep(i, n) assert(ans[i] != i);
  int cnt2 = 0;
  rep(i, n) if(ans[i] == A[i]) cnt2++;
  assert(cnt == cnt2);
  cout << cnt << endk;
  rep(i, n) cout << ans[i]+1 << ' ';
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
