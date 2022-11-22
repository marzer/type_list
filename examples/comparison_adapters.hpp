// This file is a part of marzer/type_list and is subject to the the terms of the MIT license.
// Copyright (c) Mark Gillard <mark.gillard@outlook.com.au>
// See https://github.com/marzer/type_list/blob/master/LICENSE for the full license text.
// SPDX-License-Identifier: MIT
#pragma once

#ifndef USE_STD_TUPLE
	#define USE_STD_TUPLE 0
#endif
#if USE_STD_TUPLE
	#include "comparison_adapter_std_tuple.hpp"
#else
	#include "comparison_adapter_type_list.hpp"
#endif
#include <utility>

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
}
