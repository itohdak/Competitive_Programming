#include <bits/stdc++.h>
#include <print.hpp>
// #include <cassert>
// #include <numeric>
// #include <type_traits>
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

// namespace atcoder {

// namespace internal {

// #ifndef _MSC_VER
// template <class T>
// using is_signed_int128 =
//     typename std::conditional<std::is_same<T, __int128_t>::value ||
//                                   std::is_same<T, __int128>::value,
//                               std::true_type,
//                               std::false_type>::type;

// template <class T>
// using is_unsigned_int128 =
//     typename std::conditional<std::is_same<T, __uint128_t>::value ||
//                                   std::is_same<T, unsigned __int128>::value,
//                               std::true_type,
//                               std::false_type>::type;

// template <class T>
// using make_unsigned_int128 =
//     typename std::conditional<std::is_same<T, __int128_t>::value,
//                               __uint128_t,
//                               unsigned __int128>;

// template <class T>
// using is_integral = typename std::conditional<std::is_integral<T>::value ||
//                                                   is_signed_int128<T>::value ||
//                                                   is_unsigned_int128<T>::value,
//                                               std::true_type,
//                                               std::false_type>::type;

// template <class T>
// using is_signed_int = typename std::conditional<(is_integral<T>::value &&
//                                                  std::is_signed<T>::value) ||
//                                                     is_signed_int128<T>::value,
//                                                 std::true_type,
//                                                 std::false_type>::type;

// template <class T>
// using is_unsigned_int =
//     typename std::conditional<(is_integral<T>::value &&
//                                std::is_unsigned<T>::value) ||
//                                   is_unsigned_int128<T>::value,
//                               std::true_type,
//                               std::false_type>::type;

// template <class T>
// using to_unsigned = typename std::conditional<
//     is_signed_int128<T>::value,
//     make_unsigned_int128<T>,
//     typename std::conditional<std::is_signed<T>::value,
//                               std::make_unsigned<T>,
//                               std::common_type<T>>::type>::type;

// #else

// template <class T> using is_integral = typename std::is_integral<T>;

// template <class T>
// using is_signed_int =
//     typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,
//                               std::true_type,
//                               std::false_type>::type;

// template <class T>
// using is_unsigned_int =
//     typename std::conditional<is_integral<T>::value &&
//                                   std::is_unsigned<T>::value,
//                               std::true_type,
//                               std::false_type>::type;

// template <class T>
// using to_unsigned = typename std::conditional<is_signed_int<T>::value,
//                                               std::make_unsigned<T>,
//                                               std::common_type<T>>::type;

// #endif

// template <class T>
// using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;

// template <class T>
// using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;

// template <class T> using to_unsigned_t = typename to_unsigned<T>::type;

// }  // namespace internal

// }  // namespace atcoder

// namespace atcoder {

// // Reference: https://en.wikipedia.org/wiki/Fenwick_tree
// template <class T> struct fenwick_tree {
//     using U = internal::to_unsigned_t<T>;

//   public:
//     fenwick_tree() : _n(0) {}
//     fenwick_tree(int n) : _n(n), data(n) {}

//     void add(int p, T x) {
//         // cout << p << ' ' << _n << endl;
//         assert(0 <= p && p < _n);
//         p++;
//         while (p <= _n) {
//             data[p - 1] += U(x);
//             p += p & -p;
//         }
//     }

//     T sum(int l, int r) {
//         // cout << l << ' ' << r << ' ' << _n << endl;
//         assert(0 <= l && l <= r && r <= _n);
//         return sum(r) - sum(l);
//     }

//   private:
//     int _n;
//     std::vector<U> data;

//     U sum(int r) {
//         U s = 0;
//         while (r > 0) {
//             s += data[r - 1];
//             r -= r & -r;
//         }
//         return s;
//     }
// };

// }  // namespace atcoder

// using namespace atcoder;

template< typename T >
struct BinaryIndexedTree {
  vector< T > data;

  BinaryIndexedTree(int sz) {
    data.assign(++sz, 0);
  }

  T sum(int k) {
    T ret = 0;
    for(++k; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }

  void add(int k, T x) {
    for(++k; k < data.size(); k += k & -k) data[k] += x;
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s; cin >> s;
  int n = s.size();
  // vector<vector<vector<fenwick_tree<int>>>> BIT(11, vector<vector<fenwick_tree<int>>>(10, vector<fenwick_tree<int>>(26, fenwick_tree<int>(n))));
  vector<vector<vector<BinaryIndexedTree<int>>>> BIT(11, vector<vector<BinaryIndexedTree<int>>>(10, vector<BinaryIndexedTree<int>>(4, BinaryIndexedTree<int>(n))));
  string AGTC = "AGTC";
  map<char, int> mp = {{'A', 0}, {'G', 1}, {'T', 2}, {'C', 3}};
  rep(i, 11) {      // 何個飛ばし
    rep(j, i) {     // スタート
      rep(k, 4) {  // アルファベット
        for(int l=j; l<n; l+=i) { // 位置
          if(s[l] == AGTC[k]) {
            BIT[i][j][k].add(l, 1);
          }
        }
      }
    }
  }
  // rep(i, 11) rep(j, i) rep(k, 26) {
  //   int sum = BIT[i][j][k].sum(0, n);
  //   if(sum) cout << sum << endl;
  // }
  int q; cin >> q;
  rep(_, q) {
    int t; cin >> t;
    if(t == 1) {
      int x; char c; cin >> x >> c;
      x--;
      char now = s[x];
      rep(i, 11) rep(j, i) {
        if((x-j)%i == 0) {
          BIT[i][j][mp[now]].add(x, -1);
          BIT[i][j][mp[c]].add(x, 1);
        }
      }
      s[x] = c;
    } else {
      int l, r; string e;
      cin >> l >> r >> e;
      l--;
      int ans = 0;
      rep(i, e.size()) {
        // cout << e.size() << ' ' << (l+i)%e.size() << ' ' << e[i]-'A' << endl;
        if(l+i <= r) {
          // ans += BIT[e.size()][(l+i)%e.size()][e[i]-'A'].sum(l+i, r);
          ans += (BIT[e.size()][(l+i)%e.size()][mp[e[i]]].sum(r-1) - (l+i == 0 ? 0 : BIT[e.size()][(l+i)%e.size()][mp[e[i]]].sum(l+i-1)));
        }
      }
      cout << ans << endk;
    }
  }
  return 0;
}
