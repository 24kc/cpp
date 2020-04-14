#ifndef _TYPE_TRAITS_H_
#define _TYPE_TRAITS_H_

namespace akm {

template<class T, T v>
struct integral_constant {
	static constexpr T value = v;
	using value_type = T;
	using type = integral_constant;
	constexpr operator value_type() const noexcept { return value; }
	constexpr value_type operator()() const noexcept { return value; }
};
/*
template<class T, class U>
struct is_same 
*/
} // namespace akm

#endif
