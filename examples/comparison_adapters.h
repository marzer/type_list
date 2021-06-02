// This file is a part of marzer/type_list and is subject to the the terms of the MIT license.
// Copyright (c) Mark Gillard <mark.gillard@outlook.com.au>
// See https://github.com/marzer/type_list/blob/master/LICENSE for the full license text.
// SPDX-License-Identifier: MIT

#pragma once
#ifndef USE_STD_TUPLE
	#define USE_STD_TUPLE 0
#endif
#if USE_STD_TUPLE
	#include "comparison_adapter_std_tuple.h"
#else
	#include "comparison_adapter_type_list.h"
#endif

namespace mz
{
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

#if 0 // adapter sanity checks

	static_assert(type_list_length<make_type_list<0, 100>> == 100);

	static_assert(std::is_same_v<type_list_select<make_type_list<0, 100>, 0>, index_tag<0>>);
	static_assert(std::is_same_v<type_list_select<make_type_list<0, 100>, 5>, index_tag<5>>);
	static_assert(std::is_same_v<type_list_select<make_type_list<0, 100>, 10>, index_tag<10>>);
	static_assert(std::is_same_v<type_list_select<make_type_list<0, 100>, 60>, index_tag<60>>);
	static_assert(std::is_same_v<type_list_select<make_type_list<0, 100>, 70>, index_tag<70>>);

	static_assert(std::is_same_v<type_list_slice<make_type_list<0, 100>, 0, 1>, make_type_list<0, 1>>);
	static_assert(std::is_same_v<type_list_slice<make_type_list<0, 100>, 5, 1>, make_type_list<5, 1>>);
	static_assert(std::is_same_v<type_list_slice<make_type_list<0, 100>, 10, 1>, make_type_list<10, 1>>);
	static_assert(std::is_same_v<type_list_slice<make_type_list<0, 100>, 60, 1>, make_type_list<60, 1>>);
	static_assert(std::is_same_v<type_list_slice<make_type_list<0, 100>, 70, 1>, make_type_list<70, 1>>);

	static_assert(std::is_same_v<type_list_slice<make_type_list<0, 100>, 0, 5>, make_type_list<0, 5>>);
	static_assert(std::is_same_v<type_list_slice<make_type_list<0, 100>, 5, 5>, make_type_list<5, 5>>);
	static_assert(std::is_same_v<type_list_slice<make_type_list<0, 100>, 10, 5>, make_type_list<10, 5>>);
	static_assert(std::is_same_v<type_list_slice<make_type_list<0, 100>, 60, 5>, make_type_list<60, 5>>);
	static_assert(std::is_same_v<type_list_slice<make_type_list<0, 100>, 70, 5>, make_type_list<70, 5>>);

#endif

}
