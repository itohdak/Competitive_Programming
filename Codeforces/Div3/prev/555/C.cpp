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
  deque<int> q;
  rep(i, n) {
    cin >> A[i];
    q.push_back(A[i]);
  }
  int mx = 0;
  string ans;
  while(!q.empty()) {
    int a1 = q.front();
    int a2 = q.back();
    if(a1 > a2) {
      if(a2 > mx) {
        ans += 'R';
        mx = a2;
        q.pop_back();
      } else if(a1 > mx) {
        ans += 'L';
        mx = a1;
        q.pop_front();
      } else break;
    } else {
      if(a1 > mx) {
        ans += 'L';
        mx = a1;
        q.pop_front();
      } else if(a2 > mx) {
        ans += 'R';
        mx = a2;
        q.pop_back();
      } else break;
    }
  }
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
