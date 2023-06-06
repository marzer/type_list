// This file is a part of marzer/type_list and is subject to the the terms of the MIT license.
// Copyright (c) Mark Gillard <mark.gillard@outlook.com.au>
// See https://github.com/marzer/type_list/blob/master/LICENSE for the full license text.
// SPDX-License-Identifier: MIT

#include <mz/type_list.hpp>
#include <type_traits>
#include <utility>

using namespace mz;

template <size_t N>
using index_tag = std::integral_constant<size_t, N>;

template <size_t Start, typename>
struct type_list_maker;

template <size_t Start, size_t... Seq>
struct type_list_maker<Start, std::index_sequence<Seq...>>
{
	using type = type_list<index_tag<Start + Seq>...>;
};

template <size_t Start, size_t Length>
using make_type_list = typename type_list_maker<Start, std::make_index_sequence<Length>>::type;

using test_type_list = make_type_list<0, 100>;

static_assert(test_type_list::length == 100);

static_assert(std::is_same_v<test_type_list::first, index_tag<0>>);

static_assert(std::is_same_v<test_type_list::select<0>, index_tag<0>>);
static_assert(std::is_same_v<test_type_list::select<1>, index_tag<1>>);
static_assert(std::is_same_v<test_type_list::select<2>, index_tag<2>>);
static_assert(std::is_same_v<test_type_list::select<3>, index_tag<3>>);
static_assert(std::is_same_v<test_type_list::select<4>, index_tag<4>>);
static_assert(std::is_same_v<test_type_list::select<5>, index_tag<5>>);
static_assert(std::is_same_v<test_type_list::select<6>, index_tag<6>>);
static_assert(std::is_same_v<test_type_list::select<7>, index_tag<7>>);
static_assert(std::is_same_v<test_type_list::select<8>, index_tag<8>>);
static_assert(std::is_same_v<test_type_list::select<9>, index_tag<9>>);
static_assert(std::is_same_v<test_type_list::select<10>, index_tag<10>>);
static_assert(std::is_same_v<test_type_list::select<60>, index_tag<60>>);
static_assert(std::is_same_v<test_type_list::select<70>, index_tag<70>>);
static_assert(std::is_same_v<test_type_list::select<99>, index_tag<99>>);

static_assert(std::is_same_v<test_type_list::slice<0, 1>, make_type_list<0, 1>>);
static_assert(std::is_same_v<test_type_list::slice<1, 1>, make_type_list<1, 1>>);
static_assert(std::is_same_v<test_type_list::slice<2, 1>, make_type_list<2, 1>>);
static_assert(std::is_same_v<test_type_list::slice<3, 1>, make_type_list<3, 1>>);
static_assert(std::is_same_v<test_type_list::slice<4, 1>, make_type_list<4, 1>>);
static_assert(std::is_same_v<test_type_list::slice<5, 1>, make_type_list<5, 1>>);
static_assert(std::is_same_v<test_type_list::slice<6, 1>, make_type_list<6, 1>>);
static_assert(std::is_same_v<test_type_list::slice<7, 1>, make_type_list<7, 1>>);
static_assert(std::is_same_v<test_type_list::slice<8, 1>, make_type_list<8, 1>>);
static_assert(std::is_same_v<test_type_list::slice<9, 1>, make_type_list<9, 1>>);
static_assert(std::is_same_v<test_type_list::slice<10, 1>, make_type_list<10, 1>>);
static_assert(std::is_same_v<test_type_list::slice<60, 1>, make_type_list<60, 1>>);
static_assert(std::is_same_v<test_type_list::slice<70, 1>, make_type_list<70, 1>>);
static_assert(std::is_same_v<test_type_list::slice<99, 1>, make_type_list<99, 1>>);

static_assert(std::is_same_v<test_type_list::slice<0, 5>, make_type_list<0, 5>>);
static_assert(std::is_same_v<test_type_list::slice<1, 5>, make_type_list<1, 5>>);
static_assert(std::is_same_v<test_type_list::slice<2, 5>, make_type_list<2, 5>>);
static_assert(std::is_same_v<test_type_list::slice<3, 5>, make_type_list<3, 5>>);
static_assert(std::is_same_v<test_type_list::slice<4, 5>, make_type_list<4, 5>>);
static_assert(std::is_same_v<test_type_list::slice<5, 5>, make_type_list<5, 5>>);
static_assert(std::is_same_v<test_type_list::slice<6, 5>, make_type_list<6, 5>>);
static_assert(std::is_same_v<test_type_list::slice<7, 5>, make_type_list<7, 5>>);
static_assert(std::is_same_v<test_type_list::slice<8, 5>, make_type_list<8, 5>>);
static_assert(std::is_same_v<test_type_list::slice<9, 5>, make_type_list<9, 5>>);
static_assert(std::is_same_v<test_type_list::slice<10, 5>, make_type_list<10, 5>>);
static_assert(std::is_same_v<test_type_list::slice<60, 5>, make_type_list<60, 5>>);
static_assert(std::is_same_v<test_type_list::slice<70, 5>, make_type_list<70, 5>>);

static_assert(test_type_list::index_of<index_tag<0>> == 0);
static_assert(test_type_list::index_of<index_tag<1>> == 1);
static_assert(test_type_list::index_of<index_tag<2>> == 2);
static_assert(test_type_list::index_of<index_tag<3>> == 3);
static_assert(test_type_list::index_of<index_tag<4>> == 4);
static_assert(test_type_list::index_of<index_tag<5>> == 5);
static_assert(test_type_list::index_of<index_tag<6>> == 6);
static_assert(test_type_list::index_of<index_tag<7>> == 7);
static_assert(test_type_list::index_of<index_tag<8>> == 8);
static_assert(test_type_list::index_of<index_tag<9>> == 9);
static_assert(test_type_list::index_of<index_tag<10>> == 10);
static_assert(test_type_list::index_of<index_tag<60>> == 60);
static_assert(test_type_list::index_of<index_tag<70>> == 70);
static_assert(test_type_list::index_of<index_tag<99>> == 99);

static_assert(std::is_same_v<type_list<>::flatten,						 //
							 type_list<>>);
static_assert(std::is_same_v<type_list<type_list<>>::flatten,			 //
							 type_list<>>);
static_assert(std::is_same_v<type_list<type_list<type_list<>>>::flatten, //
							 type_list<>>);
static_assert(std::is_same_v<type_list<float>::flatten,					 //
							 type_list<float>>);
static_assert(std::is_same_v<type_list<type_list<float>>::flatten,		 //
							 type_list<float>>);
static_assert(std::is_same_v<type_list<float, int>::flatten,			 //
							 type_list<float, int>>);
static_assert(std::is_same_v<type_list<type_list<float>, int>::flatten,	 //
							 type_list<float, int>>);
static_assert(std::is_same_v<type_list<type_list<int>, type_list<float, type_list<double, char>>>::flatten,
							 type_list<int, float, double, char>>);

static_assert(std::is_same_v<type_list<>::remove<void>,															   //
							 type_list<>>);
static_assert(std::is_same_v<type_list<void>::remove<void>,														   //
							 type_list<>>);
static_assert(std::is_same_v<type_list<void, void>::remove<void>,												   //
							 type_list<>>);
static_assert(std::is_same_v<type_list<int, void, float, void, void, void, double, void>::remove<void>,			   //
							 type_list<int, float, double>>);
static_assert(std::is_same_v<type_list<int, type_list<void>, float, void, void, void, double, void>::remove<void>, //
							 type_list<int, type_list<void>, float, double>>);

static_assert(std::is_same_v<type_list<>::append<void>,								  //
							 type_list<void>>);
static_assert(std::is_same_v<type_list<int>::append<void>,							  //
							 type_list<int, void>>);
static_assert(std::is_same_v<type_list<int, char>::append<void>,					  //
							 type_list<int, char, void>>);
static_assert(std::is_same_v<type_list<int, float, double>::append<bool, char, void>, //
							 type_list<int, float, double, bool, char, void>>);

static_assert(std::is_same_v<type_list<>::prepend<void>,							   //
							 type_list<void>>);
static_assert(std::is_same_v<type_list<int>::prepend<void>,							   //
							 type_list<void, int>>);
static_assert(std::is_same_v<type_list<int, char>::prepend<void>,					   //
							 type_list<void, int, char>>);
static_assert(std::is_same_v<type_list<int, float, double>::prepend<bool, char, void>, //
							 type_list<bool, char, void, int, float, double>>);

static_assert(type_list<bool, char, int>::contains<bool>);
static_assert(type_list<bool, char, int>::contains<char>);
static_assert(type_list<bool, char, int>::contains<int>);
static_assert(!type_list<bool, char, int>::contains<float>);

static_assert(type_list<bool, char>::contains<bool>);
static_assert(type_list<bool, char>::contains<char>);
static_assert(!type_list<bool, char>::contains<int>);
static_assert(!type_list<bool, char>::contains<float>);

static_assert(type_list<bool>::contains<bool>);
static_assert(!type_list<bool>::contains<char>);
static_assert(!type_list<bool>::contains<int>);
static_assert(!type_list<bool>::contains<float>);

static_assert(!type_list<>::contains<bool>);
static_assert(!type_list<>::contains<char>);
static_assert(!type_list<>::contains<int>);
static_assert(!type_list<>::contains<float>);

int main()
{
	return 0;
}
