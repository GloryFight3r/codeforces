/*
 * がんばって
*/

#include <bits/stdc++.h>

using namespace std;

//basic types
using ll = long long;
using ld = long double;
using db = double;
using str = string;

using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;

using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;

#define tcT template<class T
#define tcTU tcT, class U

tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>; 
tcT> using PR = pair<T,T>;

// pairs
#define mp make_pair
#define f first
#define s second

// for vectors
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sor(x) sort(all(x))
#define rsz resize
#define ins insert
#define ft front()
#define bk back()
#define pf push_front
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound

// loops
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); i++)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

const int MOD = 1e9+7;
const int mxN = 3e5+5;
const ll INF = 1e18;
const ld PI = acos((ld)-1);
const int tSZ = (1 << 21);
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for grid problems
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

// useful functions
constexpr int pcnt(int x) { return __builtin_popcount(x); } // number of bits
constexpr int bits(int x) { return 31-__builtin_clz(x); } // log2(x) rounded down
ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down

// functions for working with MOD
ll add(ll f, ll s){ f += s; if(f >= MOD) f %= MOD; if(f < 0) f += MOD;	return f; } // add f to s and make sure it's in range
ll mul(ll f, ll s){ f *= s; if(f >= MOD) f %= MOD; return f;} // multiply f and s and make sure it's in range
ll pw(ll x, ll y) { ll ans = 1, ml = x; while(y) { if(y & 1) ans = mul(ans, ml); ml = mul(ml, ml);	y >>= 1; } return ans; } // number x to a power y
ll inv(ll x) { return pw(x, MOD - 2); } //inversion of a number

tcT> void remDup(vector<T>& x) { // sort and remove duplicates
	sort(all(x)); x.erase(unique(all(x)),end(x)); }
tcTU> void erase(T& x, const U& v) {
	auto it = x.find(v); assert(it != end(x));
	x.erase(v); }

// Input
#define tcTUU tcT, class ...U
tcT> void re(complex<T>& c);
tcTU> void re(pair<T,U>& p);
tcT> void re(vector<T>& v);
tcT, size_t SZ> void re(array<T,SZ>& a);

tcT> void re(T& x) { cin >> x; }
void re(db& d) { str t; re(t); d = stod(t); }
void re(ld& d) { str t; re(t); d = stold(t); }
tcTUU> void re(T& t, U&... u) { re(t); re(u...); }
 
tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; }
tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
tcT> void re(vector<T>& x) { trav(a,x) re(a); }
tcT, size_t SZ> void re(array<T,SZ>& x) { trav(a,x) re(a); }
tcT> void rv(int& n, vector<T>& x) { re(n); x.rsz(n); trav(a,x) re(a); }

// To_String
#define ts to_string
str ts(char c) { return str(1,c); }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
str ts(bool b) { 
	#ifdef LOCAL
		return b ? "true" : "false"; 
	#else 
		return ts((int)b);
	#endif
}
tcT> str ts(complex<T> c) { 
	stringstream ss; ss << c; return ss.str(); }
str ts(vector<bool> v) {
	str res = "{"; F0R(i,sz(v)) res += char('0'+v[i]);
	res += "}"; return res; }
template<size_t SZ> str ts(bitset<SZ> b) {
	str res = ""; F0R(i,SZ) res += char('0'+b[i]);
	return res; }
tcTU> str ts(pair<T,U> p);
tcT> str ts(T v) { // containers with begin(), end()
	#ifdef LOCAL
		bool fst = 1; str res = "{";
		for (const auto& x: v) {
			if (!fst) res += ", ";
			fst = 0; res += ts(x);
		}
		res += "}"; return res;
	#else
		bool fst = 1; str res = "";
		for (const auto& x: v) {
			if (!fst) res += " ";
			fst = 0; res += ts(x);
		}
		return res;
 
	#endif
}
tcTU> str ts(pair<T,U> p) {
	#ifdef LOCAL
		return"("+ts(p.f)+", "+ts(p.s)+")"; 
	#else
		return ts(p.f)+" "+ts(p.s);
	#endif
}
 
// Output
tcT> void pr(T v) { cout << ts(v); }
tcTUU> void pr(const T& t, const U&... u) { 
	pr(t); pr(u...); }
void ps() { pr("\n"); } // no spaces
tcTUU> void ps(const T& t, const U&... u) { 
	pr(t); if (sizeof...(u)) pr(" "); ps(u...); }
 
// File In/Out
void setIn(str s) { freopen(s.c_str(),"r", stdin); }
void setOut(str s) { freopen(s.c_str(),"w", stdout); }
void unsyncIO() { cin.tie(0)->sync_with_stdio(0); }
void setIO(str st = "") {
	unsyncIO();
	if (sz(st)) { setIn(st+".in"), setOut(st+".out"); } // If problem requires file reading
}

// DEBUG
void DBG() { cerr << "]" << endl; }
tcTUU> void DBG(const T& t, const U&... u) {
	cerr << ts(t); if (sizeof...(u)) cerr << ", ";
	DBG(u...); }
#ifdef LOCAL // compile with -DLOCAL, chk -> fake assert
	#define dbg(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
	#define chk(...) if (!(__VA_ARGS__)) cerr << "Line(" << __LINE__ << ") -> function(" \
		 << __FUNCTION__  << ") -> CHK FAILED: (" << #__VA_ARGS__ << ")" << "\n", exit(0);
#else
	#define dbg(...) 0
	#define chk(...) 0
#endif

struct segm_tree {
	int tree[tSZ];
	int lazy[tSZ];
	int mx[tSZ];
	
	segm_tree() {
		FOR(i, 0, tSZ) {
			tree[i] = lazy[i] = mx[i] = 0;
		}
	}

	void push(int node, int l, int r) {
		if(l > r) return;

		if(lazy[node] != 0) {

			tree[node] += lazy[node] * (r - l + 1);
			if(tree[node] == 0) {
				mx[node] = 0;
			}
			else {
				mx[node] = r;
			}
			if(l != r) {
				lazy[node << 1] += lazy[node];
				lazy[node << 1 | 1] += lazy[node];
			}

			lazy[node] = 0;
		}
	}

	void update(int node, int l, int r, int i, int j, int value) {
		push(node, l, r);
		if(r < i || l > j || l > r) return;

		if(r <= j && l >= i) {
			lazy[node] += value;
			push(node, l, r);
			return;
		}
		int middle = (l + r) >> 1;

		update(node << 1, l, middle, i, j, value);
		update(node << 1 | 1, middle + 1, r, i, j, value);
		tree[node] = tree[node << 1] + tree[node << 1 | 1];
		mx[node] = max(mx[node << 1], mx[node << 1 | 1]);
	}

	int query(int node, int l, int r, int i, int j) {
		if(r < i || l > j || l > r) return 0;
		push(node, l, r);

		if(r <= j && l >= i) {
			return tree[node];
		}
		int middle = (l + r) >> 1;

		return query(node << 1, l, middle, i, j) + query(node << 1 | 1, middle + 1, r, i, j);
	}

	int query(int l, int r) {
		return query(1, 1, mxN, l, r);
	}
	
	void update(int l, int r, int val) {
		update(1, 1, mxN, l, r, val);
	}
} sgm_tree;

int n, q, a[mxN];

void add(int v) {
	// find first zero from v
	
	int sm = sgm_tree.query(0, v - 1);

	int l = v, r = mxN;
	int ans = v;

	while(l <= r) {
		int middle = (l + r) >> 1;
		
		int x = sgm_tree.query(1, middle);

		if(sm + (middle - v) + 1 > x) {
			ans = middle;
			r = middle - 1;
		}
		else {
			l = middle + 1;
		}
	}

	if(ans == v) {
		sgm_tree.update(v, v, 1);
	}
	else {
		sgm_tree.update(v, ans - 1, -1);
		sgm_tree.update(ans, ans, 1);
	}
}

void sub(int v) {
	// find first one from v
	
	int sm = sgm_tree.query(1, v - 1);

	int l = v, r = mxN;
	int ans = v - 1;

	while(l <= r) {
		int middle = (l + r) >> 1;
		
		int x = sgm_tree.query(1, middle);

		if(sm == x) {
			ans = middle;
			l = middle + 1;
		}
		else {
			r = middle - 1;
		}
	}
	ans++;
	if(ans == v) {
		sgm_tree.update(v, v, -1);
	}
	else {
		sgm_tree.update(v, ans - 1, 1);
		sgm_tree.update(ans, ans, -1);
	}
}

void solve() {
	int k, v;
	FOR(i, 0, q) {
		re(k, v);
		k--;
		sub(a[k]);
		a[k] = v;
		add(a[k]);
		ps(sgm_tree.mx[1]);
	}
}

int main() {
	setIO();

	re(n, q);

	FOR(i, 0, n) {
		re(a[i]);
		add(a[i]);
	}

	solve();

	return 0;
	//read stuff at the bottom ffs
}
/* things to keep in mind
 * int overflow, array bounds
 * any special cases
 * always do something
 * WRITE STUFF DOWN
 * THINK ABOUT OTHER APPROACHES
 * DON'T NON STOP CHECK OTHERS
 * DON'T PANIC
*/
