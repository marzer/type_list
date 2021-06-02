// This file is a part of marzer/type_list and is subject to the the terms of the MIT license.
// Copyright (c) Mark Gillard <mark.gillard@outlook.com.au>
// See https://github.com/marzer/type_list/blob/master/LICENSE for the full license text.
// SPDX-License-Identifier: MIT

// this was the test code used in the 'Compilation speed humps: std::tuple' write-up
// (https://marzer.github.io/md_blog_2021_05_31_compilation_speed_humps_std_tuple.html)

#include <cstdint>
#include <cstdio>
#include "comparison_adapters.h"

namespace mz
{
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

	template <typename T>
	[[maybe_unused]] static void consume_type_list() noexcept
	{
		std::printf("%zu\n", type_list_length<T>);
	}
}

using namespace mz;

int main()
{
// do some arbitrary nonsense with big type_lists (extremely RAM intensive!)
#if 0
	{
		using list_1 = make_type_list<0, 1000>;
		using list_2 = type_list_slice<list_1, 600, 300>;
		using list_3 = type_list_slice<list_1, 900, 50>;
		using list_4 = type_list_slice<list_2, 100, 10>;

		consume_type_list<list_1>();
		consume_type_list<list_2>();
		consume_type_list<list_3>();
		consume_type_list<list_4>();

		using type_1 = type_list_select<list_1, 900>;
		using type_2 = type_list_select<list_1, 999>;
		using type_3 = type_list_select<list_1, 0>;
		using type_4 = type_list_select<list_1, 500>;

		using list_5 = type_list<type_1, type_2, type_3, type_4>;

		consume_type_list<list_5>();
	}

#endif

// simulating my original CI project structure
#if 1
	{
		using types = make_type_list<0, 200>;

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
#endif

	return 0;
}
