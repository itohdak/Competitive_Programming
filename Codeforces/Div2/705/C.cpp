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
  string s; cin >> s;
  if(n%k) {
    cout << -1 << endk;
    return;
  }
  vector<int> cnt(26);
  rep(i, n) cnt[s[i]-'a']++;
  {
    bool ok = true;
    rep(i, 26) if(cnt[i]%k) ok = false;
    if(ok) {
      cout << s << endk;
      return;
    }
  }
  rrep(i, n) {
    cnt[s[i]-'a']--;
    for(char c=s[i]+1; c<='z'; c++) {
      cnt[c-'a']++;
      int need = 0;
      rep(j, 26) need += (cnt[j]+k-1)/k*k-cnt[j];
      if(n-i-1 >= need) {
        s[i] = c;
        int tmp = n-1;
        rrep(j, 26) {
          while((cnt[j]+k-1)/k*k-cnt[j]) {
            s[tmp--] = char('a'+j);
            cnt[j]++;
          }
        }
        assert(tmp >= i);
        for(int j=tmp; j>=i+1; j--) s[j] = 'a';
        cout << s << endk;
        return;
      }
      cnt[c-'a']--;
    }
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
