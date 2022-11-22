// This file is a part of marzer/type_list and is subject to the the terms of the MIT license.
// Copyright (c) Mark Gillard <mark.gillard@outlook.com.au>
// See https://github.com/marzer/type_list/blob/master/LICENSE for the full license text.
// SPDX-License-Identifier: MIT
#pragma once

#include <mz/type_list.hpp>

namespace mz
{
	template <typename List, size_t Index>
	using type_list_select = typename List::template select<Index>;

	template <typename List, size_t Start, size_t Length>
	using type_list_slice = typename List::template slice<Start, Length>;

	template <typename List>
	inline constexpr size_t type_list_length = List::length;
}
