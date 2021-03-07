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
  int n; cin >> n;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<vector<pair<ll, int>>> pos(3);
  rep(i, n) {
    if(A[i] == 0)     pos[0].push_back({A[i], i});
    else if(A[i] > 0) pos[1].push_back({A[i], i});
    else              pos[2].push_back({A[i], i});
  }
  if(pos[0].size() == 0) {
    if(pos[2].size() % 2) {
      sort(all(pos[2]), greater<pair<ll, int>>());
      cout << 2 << ' ' << pos[2][0].second+1 << endk;
      vector<int> v;
      rep(i, n) if(i != pos[2][0].second) v.push_back(i);
      rep(i, v.size()-1) {
        cout << 1 << ' ' << v[i]+1 << ' ' << v[i+1]+1 << endk;
      }
    } else {
      rep(i, n-1) {
        cout << 1 << ' ' << i+1 << ' ' << i+2 << endk;
      }
    }
  } else {
    if(pos[2].size() % 2) {
      sort(all(pos[2]), greater<pair<ll, int>>());
      set<int> st;
      st.insert(pos[0][0].second);
      rep(i, pos[0].size()-1) {
        cout << 1 << ' ' << pos[0][i].second+1 << ' ' << pos[0][i+1].second+1 << endk;
        st.insert(pos[0][i+1].second);
      }
      cout << 1 << ' ' << pos[0].back().second+1 << ' ' << pos[2][0].second+1 << endk;
      st.insert(pos[2][0].second);
      if(st.size() < n) {
        cout << 2 << ' ' << pos[2][0].second+1 << endk;
        vector<int> v;
        rep(i, n) if(!st.count(i)) v.push_back(i);
        rep(i, v.size()-1) {
          cout << 1 << ' ' << v[i]+1 << ' ' << v[i+1]+1 << endk;
        }
      }
    } else {
      set<int> st;
      st.insert(pos[0][0].second);
      rep(i, pos[0].size()-1) {
        cout << 1 << ' ' << pos[0][i].second+1 << ' ' << pos[0][i+1].second+1 << endk;
        st.insert(pos[0][i+1].second);
      }
      if(st.size() < n) {
        cout << 2 << ' ' << pos[0].back().second+1 << endk;
        vector<int> v;
        rep(i, n) if(!st.count(i)) v.push_back(i);
        rep(i, v.size()-1) {
          cout << 1 << ' ' << v[i]+1 << ' ' << v[i+1]+1 << endk;
        }
      }
    }
  }
  return 0;
}
