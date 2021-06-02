// This file is a part of marzer/type_list and is subject to the the terms of the MIT license.
// Copyright (c) Mark Gillard <mark.gillard@outlook.com.au>
// See https://github.com/marzer/type_list/blob/master/LICENSE for the full license text.
// SPDX-License-Identifier: MIT

#pragma once
#include <tuple>

namespace mz
{
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
}
