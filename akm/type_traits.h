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

template<bool B>
using bool_constant = integral_constant<bool, B>;

using true_type = bool_constant<true>;
using false_type = bool_constant<false>;

template<class T, class U>
struct is_same : false_type {};

template<class T>
struct is_same<T, T> : true_type {};
/*
template<class T, class U>
inline constexpr bool is_same_v = is_same<T, U>::value;
*/

template<class T> struct remove_reference { using type = T; };
template<class T> struct remove_reference<T&> { using type = T; };
template<class T> struct remove_reference<T&&> { using type = T; };

template<class T>
using remove_reference_t = typename remove_reference<T>::type;

/*
template<class T, class U>
struct is_same 
*/
} // namespace akm

#endif
