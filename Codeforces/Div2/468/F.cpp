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

// 抽象化したセグメント木
template<class Monoid> struct SegTree {
  using Func = function<Monoid(Monoid, Monoid)>;
  const Func F;
  const Monoid UNITY;
  int SIZE_R;
  vector<Monoid> dat;

  SegTree(int n, const Func f, const Monoid &unity): F(f), UNITY(unity) { init(n); }
  void init(int n) {
    SIZE_R = 1;
    while (SIZE_R < n) SIZE_R *= 2;
    dat.assign(SIZE_R * 2, UNITY);
  }

  /* set, a is 0-indexed */
  void set(int a, const Monoid &v) { dat[a + SIZE_R] = v; }
  void build() {
    for (int k = SIZE_R - 1; k > 0; --k)
      dat[k] = F(dat[k*2], dat[k*2+1]);
  }

  /* update a, a is 0-indexed */
  void update(int a, const Monoid &v) {
    int k = a + SIZE_R;
    dat[k] = v;
    while (k >>= 1) dat[k] = F(dat[k*2], dat[k*2+1]);
  }

  /* get [a, b), a and b are 0-indexed */
  Monoid get(int a, int b) {
    Monoid vleft = UNITY, vright = UNITY;
    for (int left = a + SIZE_R, right = b + SIZE_R; left < right; left >>= 1, right >>= 1) {
      if (left & 1) vleft = F(vleft, dat[left++]);
      if (right & 1) vright = F(dat[--right], vright);
    }
    return F(vleft, vright);
  }
  inline Monoid operator [] (int a) { return dat[a + SIZE_R]; }

  /* debug */
  void print() {
    for (int i = 0; i < SIZE_R; ++i) {
      cout << (*this)[i];
      if (i != SIZE_R-1) cout << ",";
    }
    cout << endl;
  }
};

// 最長増加部分列の長さを求める
vector<int> LIS(const vector<long long> &a) {
  int N = (int)a.size();

  // 座標圧縮
  vector<long long> aval;
  for (int i = 0; i < N; ++i) aval.push_back(a[i]);
  sort(aval.begin(), aval.end());
  aval.erase(unique(aval.begin(), aval.end()), aval.end());

  // セグメント木 (区間取得を max としたもの)
  SegTree<int> dp(N+1,
                  [](int a, int b) { return max(a, b); },
                  0);

  // 更新
  vector<int> res(N);
  for (int i = 0; i < N; ++i) {
    // if(i) res[i] = res[i-1];

    // a[i] が何番目か
    int h = lower_bound(aval.begin(), aval.end(), a[i]) - aval.begin();
    ++h; // 1-indexed にする

    // 値取得
    int A = dp.get(0, h+1);

    // 更新
    if (dp.get(h, h+1) < A + 1) {
      dp.update(h, A + 1);
      res[i] = A + 1;
    }
  }
  return res;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<ll> cnt(m+1);
  rep(i, n) {
    int l, r; cin >> l >> r;
    l--;
    cnt[l]++; cnt[r]--;
  }
  rep(i, m) cnt[i+1] += cnt[i];
  assert(cnt.back() == 0);
  cnt.pop_back();
  auto res1 = LIS(cnt);
  reverse(all(cnt));
  auto res2 = LIS(cnt);
  reverse(all(res2));
  reverse(all(cnt));
  // cout << cnt << endk;
  // cout << res1 << endk;
  // cout << res2 << endk;
  int ans = 0;
  rep(i, m) chmax(ans, res1[i]+res2[i]-1);
  cout << ans << endk;
  return 0;
}
