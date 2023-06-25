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
  vector<string> S(3); rep(i, 3) cin >> S[i];
  set<char> st;
  rep(i, 3) {
    for(char c: S[i]) st.insert(c);
  }
  if(st.size() > 10) {
    cout << "UNSOLVABLE" << endk;
    return 0;
  }
  vector<int> num(10);
  rep(i, 10) num[i] = i;
  do {
    map<char, int> mp;
    int i = 0;
    for(char c: st) mp[c] = num[i++];
    vector<ll> N(3);
    bool ok = true;
    rep(i, 3) {
      string t = S[i];
      reverse(all(t));
      ll pw = 1;
      rep(j, t.size()) {
        if(j == t.size()-1 && mp[t[j]] == 0) {
          ok = false;
        }
        N[i] += mp[t[j]] * pw;
        pw *= 10;
      }
    }
    if(!ok) continue;
    if(N[0] + N[1] == N[2]) {
      rep(i, 3) cout << N[i] << endk;
      return 0;
    }
  } while(next_permutation(all(num)));
  cout << "UNSOLVABLE" << endk;
  return 0;
}
