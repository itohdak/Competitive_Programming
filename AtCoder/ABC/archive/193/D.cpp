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
  ll k; cin >> k;
  string s, t; cin >> s >> t;
  vector<ll> cnt(10), cntOrg(10);
  vector<ll> cnt1(10), cnt2(10);
  rep(i, 4) {
    cnt[s[i]-'0']++;
    cnt1[s[i]-'0']++;
    cnt[t[i]-'0']++;
    cnt2[t[i]-'0']++;
  }
  copy(all(cnt), begin(cntOrg));
  vector<ll> pw(10);
  pw[0] = 1;
  rep(i, 10) if(i) pw[i] = pw[i-1] * 10;
  ll win = 0, a = 0;
  for(ll i=1; i<=9; i++) {
    cnt[i]++;
    cnt1[i]++;
    for(ll j=1; j<=9; j++) {
      cnt[j]++;
      cnt2[j]++;
      if(cnt[i] <= k && cnt[j] <= k) {
        ll score1 = 0, score2 = 0;
        for(ll k=1; k<=9; k++) {
          score1 += k * pw[cnt1[k]];
          score2 += k * pw[cnt2[k]];
        }
        if(score1 > score2) {
          if(i == j) win += (k-cntOrg[i]) * (k-cntOrg[i]-1);
          else       win += (k-cntOrg[i]) * (k-cntOrg[j]);
          // cout << i << ' ' << j << endk;
          // cout << cnt1 << ' ' << cnt2 << endk;
          // cout << score1 << ' ' << score2 << endk;
        }
        if(i == j) a += (k-cntOrg[i]) * (k-cntOrg[i]-1);
        else       a += (k-cntOrg[i]) * (k-cntOrg[j]);
      }
      cnt[j]--;
      cnt2[j]--;
    }
    cnt[i]--;
    cnt1[i]--;
  }
  // cout << win << ' ' << a << endk;
  cout << fixed << setprecision(20) << (ld)1 * win / a << endk;
  return 0;
}
