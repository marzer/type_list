// This file is a part of marzer/type_list and is subject to the the terms of the MIT license.
// Copyright (c) Mark Gillard <mark.gillard@outlook.com.au>
// See https://github.com/marzer/type_list/blob/master/LICENSE for the full license text.
// SPDX-License-Identifier: MIT

// this was the test code used in the 'Compilation speed humps: std::tuple' write-up
// (https://marzer.github.io/md_blog_2021_05_31_compilation_speed_humps_std_tuple.html)

#include <cstdint>
#include <cstdio>
#include <type_traits>

#ifndef USE_STD_TUPLE
	#define USE_STD_TUPLE 0
#endif
#if USE_STD_TUPLE
	#include <tuple>
#else
	//#define MZ_HAS_TYPE_PACK_ELEMENT 0 // disables use of __type_pack_element on clang
	#include <mz/type_list.h>
#endif

namespace mz
{
#if USE_STD_TUPLE

	using std::size_t;

	template <typename... T>
	using type_list = std::tuple<T...>;

	template <typename List, size_t Index>
	using type_list_select = std::tuple_element_t<Index, List>;

	namespace impl
	{
		template <typename, size_t, typename>
		struct type_list_slicer_;

		template <typename List, size_t Start, size_t... Indices>
		struct type_list_slicer_<List, Start, std::index_sequence<Indices...>>
		{
			using type = type_list<std::tuple_element_t<Start + Indices, List>...>;
		};
	}

	template <typename List, size_t Start, size_t Length>
	using type_list_slice = typename impl::type_list_slicer_<List, Start, std::make_index_sequence<Length>>::type;

	template <typename List>
	inline constexpr size_t type_list_length = std::tuple_size_v<List>;

#else

	template <typename List, size_t Index>
	using type_list_select = typename List::template select<Index>;

	template <typename List, size_t Start, size_t Length>
	using type_list_slice = typename List::template slice<Start, Length>;

	template <typename List>
	inline constexpr size_t type_list_length = List::length;

#endif

	template <size_t Index>
	using index_tag = std::integral_constant<size_t, Index>;

	namespace impl
	{
		template <size_t, typename>
		struct type_list_maker_;

		template <size_t Start, size_t... Seq>
		struct type_list_maker_<Start, std::index_sequence<Seq...>>
		{
			using type = type_list<index_tag<Start + Seq>...>;
		};
	}

	template <size_t Start, size_t Length>
	using make_type_list = typename impl::type_list_maker_<Start, std::make_index_sequence<Length>>::type;

	namespace impl
	{
		template <typename Func, typename T, T... N>
		constexpr void for_sequence_(Func&& func, std::integer_sequence<T, N...>)
		{
			(static_cast<void>(static_cast<Func&&>(func)(std::integral_constant<T, N>{})), ...);
		}
	}

	template <auto N, typename Func>
	constexpr void for_sequence(Func&& func)
	{
		using n_type = decltype(N);
		static_assert(N >= n_type{}, "N cannot be negative.");

		if constexpr (N > n_type{})
			impl::for_sequence_(static_cast<Func&&>(func), std::make_integer_sequence<n_type, N>{});
		else
			static_cast<void>(func);
	}

#if 0 // adapter sanity checks

	static_assert(type_list_length<make_type_list<0, 200>> == 200);

	static_assert(std::is_same_v<type_list_select<make_type_list<0, 200>, 0>, index_tag<0>>);
	static_assert(std::is_same_v<type_list_select<make_type_list<0, 200>, 5>, index_tag<5>>);
	static_assert(std::is_same_v<type_list_select<make_type_list<0, 200>, 10>, index_tag<10>>);
	static_assert(std::is_same_v<type_list_select<make_type_list<0, 200>, 60>, index_tag<60>>);
	static_assert(std::is_same_v<type_list_select<make_type_list<0, 200>, 70>, index_tag<70>>);

	static_assert(std::is_same_v<type_list_slice<make_type_list<0, 200>, 0, 1>, make_type_list<0, 1>>);
	static_assert(std::is_same_v<type_list_slice<make_type_list<0, 200>, 5, 1>, make_type_list<5, 1>>);
	static_assert(std::is_same_v<type_list_slice<make_type_list<0, 200>, 10, 1>, make_type_list<10, 1>>);
	static_assert(std::is_same_v<type_list_slice<make_type_list<0, 200>, 60, 1>, make_type_list<60, 1>>);
	static_assert(std::is_same_v<type_list_slice<make_type_list<0, 200>, 70, 1>, make_type_list<70, 1>>);

	static_assert(std::is_same_v<type_list_slice<make_type_list<0, 200>, 0, 5>, make_type_list<0, 5>>);
	static_assert(std::is_same_v<type_list_slice<make_type_list<0, 200>, 5, 5>, make_type_list<5, 5>>);
	static_assert(std::is_same_v<type_list_slice<make_type_list<0, 200>, 10, 5>, make_type_list<10, 5>>);
	static_assert(std::is_same_v<type_list_slice<make_type_list<0, 200>, 60, 5>, make_type_list<60, 5>>);
	static_assert(std::is_same_v<type_list_slice<make_type_list<0, 200>, 70, 5>, make_type_list<70, 5>>);

#endif
}

int main()
{
	using namespace mz;

#ifdef __INTELLISENSE__
	using types = make_type_list<0, 20>;
#else
	using types = make_type_list<0, 200>;
#endif

	constexpr size_t slice_length = type_list_length<types> / 10u;
	constexpr size_t slice_count  = type_list_length<types> / slice_length //
								 + (type_list_length<types> % slice_length ? 1u : 0u);

	for_sequence<slice_count>(
		[](auto sidx)
		{
			constexpr size_t slice_index = decltype(sidx)::value;
			constexpr size_t slice_start = slice_index * slice_length;
			constexpr size_t slice_end	 = type_list_length<types> < slice_start + slice_length
											 ? type_list_length<types>
											 : slice_start + slice_length;

			using slice = type_list_slice<types, slice_start, slice_end - slice_start>;
			for_sequence<type_list_length<slice>>(
				[](auto idx)
				{
					std::printf("%zu\n", decltype(idx)::value);
				});
		});
}
