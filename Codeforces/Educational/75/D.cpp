#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REP(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

vector<ll> L, R;
ll S;
bool test(int N, ll s) {
  vector<int> cnt(3);
  ll sum = 0;
  multiset<ll> cand;
  rep(i, N) {
    sum += L[i];
    if(R[i] < s) cnt[0]++;
    else if(s < L[i]) cnt[2]++;
    else {
      cnt[1]++;
      cand.insert(s - L[i]);
    }
  }
  if(sum > S)
    return false;
  if(cnt[0] >= (N+1)/2)
    return false;
  else if(cnt[2] >= (N+1)/2)
    return true;
  else {
    int rem = (N+1)/2 - cnt[2];
    ll remS = S - sum;
    ll candSum = 0;
    rep(i, rem) {
      auto top = cand.begin();
      candSum += *top;
      cand.erase(top);
    }
    if(remS >= candSum) return true;
    else return false;
  }
}

ll binary_search(int N, ll s) {
  ll l = 0, r = s+1;
  while(r - l > 1) {
    ll mid = (l + r) / 2;
    if(test(N, mid))
      l = mid;
    else
      r = mid;
  }
  return l;
}

int main() {
  int T;
  cin >> T;
  rep(t, T) {
    int N;
    cin >> N >> S;
    L = vector<ll>(N);
    R = vector<ll>(N);
    ll maxR = 0;
    rep(i, N) {
      cin >> L[i] >> R[i];
      maxR = max(maxR, R[i]);
    }
    cout << binary_search(N, maxR) << endl;
  }
  return 0;
}

