#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n; int k; cin >> n >> k;
  if(__builtin_popcountll(n) > k) {
    cout << "No" << endk;
    return 0;
  }
  vector<int> cnt(121);
  for(int i=60; i>=0; i--) {
    if((n>>i)&1) cnt[i+60]++;
  }
  int tmp = accumulate(all(cnt), 0);
  {
    int i = 60;
    while(tmp < k) {
      if(cnt[60+i] == 0) {
        i--;
        continue;
      } else {
        if(tmp + cnt[60+i] > k) {
          break;
        } else {
          cnt[60+i-1] += cnt[60+i] * 2;
          tmp += cnt[60+i];
          cnt[60+i] = 0;
          i--;
        }
      }
    }
  }
  vector<int> ans;
  for(int i=120; i>=0; i--) rep(_, cnt[i]) ans.push_back(i);
  assert(tmp == accumulate(all(cnt), 0));
  ll rem = k - tmp;
  vector<int> v;
  for(int i=60; i>=0; i--) {
    if((rem>>i)&1) v.push_back(i);
  }
  cout << rem << endl;
  cout << cnt << endl;
  // cout << ans << endl;
  cout << v << endl;
  rep(i, v.size()) {
    cnt[ans.back()]--;
    cnt[ans.back()-v[i]-1] += 1<<(v[i]+1);
    cout << ans.back() << endl;
    ans.pop_back();
  }
  cout << cnt << endl;
  cout << accumulate(all(cnt), 0) << endl;
  cout << "Yes" << endk;
  assert(accumulate(all(cnt), 0) == k);
  for(int i=120; i>=0; i--) rep(_, cnt[i]) cout << i-60 << ' ';
  cout << endk;
  return 0;
}
