#ifndef TMP_H
#define TMP_H

template <int N>
struct int_{
	typedef int_ type;
	enum{ value=N };
};

template <bool condition,class T,class U>
struct if_{
	typedef U type;
};

template <class T,class U>
struct if_<true,T,U>{
	typedef T type;
};

template <int N,int C>
struct gcd_impl{
	typedef typename if_<(N%C==0),
						  int_<C>,
						  gcd_impl<C,N%C>>::type type;

	enum{ value=type::value };
};

template <int N,int C>
struct gcd{
	typedef typename if_<(N>C),
						  gcd_impl<N,C>,
					     gcd_impl<C,N>>::type type;
	enum{ value=type::value };
};


#endif //tmp.h
