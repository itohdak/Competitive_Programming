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
  vector<ll> B(n); rep(i, n) cin >> B[i];
  vector<int> A(n);
  copy(all(B), begin(A));
  sort(all(A));
  A.erase(unique(all(A)), end(A));
  int idx = lower_bound(all(A), B[n-1]) - begin(A);
  int lo = (n-1)-idx;
  int hi = (n-1)-(A.size()-idx-1);
  map<ll, int> mp;
  rep(i, n) mp[B[i]]++;
  for(int i=n-1; i>0; i--) {
    auto itr = mp.lower_bound(B[i]);
    if(B[i-1] < B[i]) {
      mp[B[i]]--;
      --itr;
      if(mp[B[i]] == 0) {
        mp.erase(B[i]);
        hi--;
      } else {
        hi -= 2;
      }
      if(itr->first != B[i-1] || hi < 0) {
        cout << "NO" << endk;
        return;
      }
    } else if(B[i-1] > B[i]) {
      mp[B[i]]--;
      ++itr;
      if(mp[B[i]] == 0) {
        mp.erase(B[i]);
        lo--;
      } else {
        lo -= 2;
      }
      if(itr->first != B[i-1] || lo < 0) {
        cout << "NO" << endk;
        return;
      }
    } else {
      mp[B[i]]--;
    }
  }
  cout << "YES" << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
