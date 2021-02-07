// credits: cf/narut

#define SFINAE(x, ...)	template <class, class = void> struct x : false_type {}; template <class T> struct x<T, void_t<__VA_ARGS__>> : true_type {};
    SFINAE(DefaultIO, decltype(cout << declval<T &>()))
    SFINAE(IsTuple, typename tuple_size<T>::type)
SFINAE(Iterable, decltype(begin(declval<T>())))
    template <class T> constexpr char Space(const T &) { return (Iterable<T>::value or IsTuple<T>::value) ? '\n' : ' '; }
    template <auto &os> struct Writer {
	template <class T> void Impl(T const &t) const {
	    if constexpr (DefaultIO<T>::value) os << t;
	    else if constexpr (Iterable<T>::value) { int i = 0; for (auto &&x : t) ((i++) ? (os << Space(x), Impl(x)) : Impl(x)); }
	    else if constexpr (IsTuple<T>::value) apply([this](auto const &... args) { int i = 0; (((i++) ? (os << ' ', Impl(args)) : Impl(args)), ...);}, t);
	    else static_assert(IsTuple<T>::value, "No matching type for print");
	}
	template <class F, class... Ts> auto &operator()(F const &f, Ts const &... ts) const { return Impl(f), ((os << ' ', Impl(ts)), ...), os << '\n', *this; }
    };
template <auto &is> struct Reader {
    template <class T> auto& Rd(T &t) const {
	if constexpr (DefaultIO<T>::value) is >> t;
	else if constexpr (Iterable<T>::value) for (auto &x : t) Rd(x);
	else if constexpr (IsTuple<T>::value) apply([this](auto &... args) { (Rd(args), ...); }, t);
	else static_assert(IsTuple<T>::value, "No matching type for read");
	return *this;
    }
    template <class T> auto operator[](T t) const { Rd(t); return t; }
    template <class... Ts> auto operator()(Ts... ts) const { (Rd(ts), ...); return tuple{move(ts)...}; }
};

#ifdef LIME
#define Debug(...) cerr << "\033[0;31m", Writer<cerr>{}(__VA_ARGS__), cerr << "\033[0m"
#define ASSERT(...) if(not(__VA_ARGS__)) throw runtime_error("local assertion failed")
#define LOCAL_ONLY(...) __VA_ARGS__
#else
#define Debug(...) 0
#define ASSERT(...) 0
#define LOCAL_ONLY(...) 0;
#endif
