// This file is a part of marzer/type_list and is subject to the the terms of the MIT license.
// Copyright (c) Mark Gillard <mark.gillard@outlook.com.au>
// See https://github.com/marzer/type_list/blob/master/LICENSE for the full license text.
// SPDX-License-Identifier: MIT

#pragma once
#include <cstdint>
#include <type_traits>
#include <utility>

// forgive me for the macro crimes I am about to commit

#define MZ_COMMA		  ,
#define MZ_CONCAT_1(x, y) x##y
#define MZ_CONCAT(x, y)	  MZ_CONCAT_1(x, y)

#define MZ_FOR_EACH_FORCE_UNROLL(x) x // without this msvc treats forwarded __VA_ARGS__ as a single token

#define MZ_FOR_EACH_IMPL_0(fn, x)		fn(x)
#define MZ_FOR_EACH_IMPL_1(fn, x, ...)	fn(x) MZ_FOR_EACH_IMPL_0(fn, __VA_ARGS__)
#define MZ_FOR_EACH_IMPL_2(fn, x, ...)	fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_1(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_3(fn, x, ...)	fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_2(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_4(fn, x, ...)	fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_3(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_5(fn, x, ...)	fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_4(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_6(fn, x, ...)	fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_5(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_7(fn, x, ...)	fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_6(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_8(fn, x, ...)	fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_7(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_9(fn, x, ...)	fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_8(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_10(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_9(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_11(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_10(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_12(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_11(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_13(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_12(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_14(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_13(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_15(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_14(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_16(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_15(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_17(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_16(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_18(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_17(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_19(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_18(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_20(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_19(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_21(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_20(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_22(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_21(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_23(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_22(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_24(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_23(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_25(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_24(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_26(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_25(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_27(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_26(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_28(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_27(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_29(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_28(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_30(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_29(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_31(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_30(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_32(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_31(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_33(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_32(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_34(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_33(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_35(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_34(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_36(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_35(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_37(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_36(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_38(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_37(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_39(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_38(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_40(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_39(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_41(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_40(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_42(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_41(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_43(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_42(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_44(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_43(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_45(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_44(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_46(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_45(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_47(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_46(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_48(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_47(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_49(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_48(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_50(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_49(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_51(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_50(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_52(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_51(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_53(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_52(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_54(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_53(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_55(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_54(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_56(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_55(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_57(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_56(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_58(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_57(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_59(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_58(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_60(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_59(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_61(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_60(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_62(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_61(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_63(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_62(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_64(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_63(fn, __VA_ARGS__))
#define MZ_FOR_EACH_IMPL_65(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_64(fn, __VA_ARGS__))

#define MZ_FOR_EACH_IMPL_SELECT(_0,                                                                                    \
								_1,                                                                                    \
								_2,                                                                                    \
								_3,                                                                                    \
								_4,                                                                                    \
								_5,                                                                                    \
								_6,                                                                                    \
								_7,                                                                                    \
								_8,                                                                                    \
								_9,                                                                                    \
								_10,                                                                                   \
								_11,                                                                                   \
								_12,                                                                                   \
								_13,                                                                                   \
								_14,                                                                                   \
								_15,                                                                                   \
								_16,                                                                                   \
								_17,                                                                                   \
								_18,                                                                                   \
								_19,                                                                                   \
								_20,                                                                                   \
								_21,                                                                                   \
								_22,                                                                                   \
								_23,                                                                                   \
								_24,                                                                                   \
								_25,                                                                                   \
								_26,                                                                                   \
								_27,                                                                                   \
								_28,                                                                                   \
								_29,                                                                                   \
								_30,                                                                                   \
								_31,                                                                                   \
								_32,                                                                                   \
								_33,                                                                                   \
								_34,                                                                                   \
								_35,                                                                                   \
								_36,                                                                                   \
								_37,                                                                                   \
								_38,                                                                                   \
								_39,                                                                                   \
								_40,                                                                                   \
								_41,                                                                                   \
								_42,                                                                                   \
								_43,                                                                                   \
								_44,                                                                                   \
								_45,                                                                                   \
								_46,                                                                                   \
								_47,                                                                                   \
								_48,                                                                                   \
								_49,                                                                                   \
								_50,                                                                                   \
								_51,                                                                                   \
								_52,                                                                                   \
								_53,                                                                                   \
								_54,                                                                                   \
								_55,                                                                                   \
								_56,                                                                                   \
								_57,                                                                                   \
								_58,                                                                                   \
								_59,                                                                                   \
								_60,                                                                                   \
								_61,                                                                                   \
								_62,                                                                                   \
								_63,                                                                                   \
								_64,                                                                                   \
								_65,                                                                                   \
								fn,                                                                                    \
								...)                                                                                   \
	fn

#define MZ_FOR_EACH(fn, ...)                                                                                           \
	MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_SELECT(__VA_ARGS__,                                                      \
													 MZ_FOR_EACH_IMPL_65,                                              \
													 MZ_FOR_EACH_IMPL_64,                                              \
													 MZ_FOR_EACH_IMPL_63,                                              \
													 MZ_FOR_EACH_IMPL_62,                                              \
													 MZ_FOR_EACH_IMPL_61,                                              \
													 MZ_FOR_EACH_IMPL_60,                                              \
													 MZ_FOR_EACH_IMPL_59,                                              \
													 MZ_FOR_EACH_IMPL_58,                                              \
													 MZ_FOR_EACH_IMPL_57,                                              \
													 MZ_FOR_EACH_IMPL_56,                                              \
													 MZ_FOR_EACH_IMPL_55,                                              \
													 MZ_FOR_EACH_IMPL_54,                                              \
													 MZ_FOR_EACH_IMPL_53,                                              \
													 MZ_FOR_EACH_IMPL_52,                                              \
													 MZ_FOR_EACH_IMPL_51,                                              \
													 MZ_FOR_EACH_IMPL_50,                                              \
													 MZ_FOR_EACH_IMPL_49,                                              \
													 MZ_FOR_EACH_IMPL_48,                                              \
													 MZ_FOR_EACH_IMPL_47,                                              \
													 MZ_FOR_EACH_IMPL_46,                                              \
													 MZ_FOR_EACH_IMPL_45,                                              \
													 MZ_FOR_EACH_IMPL_44,                                              \
													 MZ_FOR_EACH_IMPL_43,                                              \
													 MZ_FOR_EACH_IMPL_42,                                              \
													 MZ_FOR_EACH_IMPL_41,                                              \
													 MZ_FOR_EACH_IMPL_40,                                              \
													 MZ_FOR_EACH_IMPL_39,                                              \
													 MZ_FOR_EACH_IMPL_38,                                              \
													 MZ_FOR_EACH_IMPL_37,                                              \
													 MZ_FOR_EACH_IMPL_36,                                              \
													 MZ_FOR_EACH_IMPL_35,                                              \
													 MZ_FOR_EACH_IMPL_34,                                              \
													 MZ_FOR_EACH_IMPL_33,                                              \
													 MZ_FOR_EACH_IMPL_32,                                              \
													 MZ_FOR_EACH_IMPL_31,                                              \
													 MZ_FOR_EACH_IMPL_30,                                              \
													 MZ_FOR_EACH_IMPL_29,                                              \
													 MZ_FOR_EACH_IMPL_28,                                              \
													 MZ_FOR_EACH_IMPL_27,                                              \
													 MZ_FOR_EACH_IMPL_26,                                              \
													 MZ_FOR_EACH_IMPL_25,                                              \
													 MZ_FOR_EACH_IMPL_24,                                              \
													 MZ_FOR_EACH_IMPL_23,                                              \
													 MZ_FOR_EACH_IMPL_22,                                              \
													 MZ_FOR_EACH_IMPL_21,                                              \
													 MZ_FOR_EACH_IMPL_20,                                              \
													 MZ_FOR_EACH_IMPL_19,                                              \
													 MZ_FOR_EACH_IMPL_18,                                              \
													 MZ_FOR_EACH_IMPL_17,                                              \
													 MZ_FOR_EACH_IMPL_16,                                              \
													 MZ_FOR_EACH_IMPL_15,                                              \
													 MZ_FOR_EACH_IMPL_14,                                              \
													 MZ_FOR_EACH_IMPL_13,                                              \
													 MZ_FOR_EACH_IMPL_12,                                              \
													 MZ_FOR_EACH_IMPL_11,                                              \
													 MZ_FOR_EACH_IMPL_10,                                              \
													 MZ_FOR_EACH_IMPL_9,                                               \
													 MZ_FOR_EACH_IMPL_8,                                               \
													 MZ_FOR_EACH_IMPL_7,                                               \
													 MZ_FOR_EACH_IMPL_6,                                               \
													 MZ_FOR_EACH_IMPL_5,                                               \
													 MZ_FOR_EACH_IMPL_4,                                               \
													 MZ_FOR_EACH_IMPL_3,                                               \
													 MZ_FOR_EACH_IMPL_2,                                               \
													 MZ_FOR_EACH_IMPL_1,                                               \
													 MZ_FOR_EACH_IMPL_0)(fn, __VA_ARGS__))

#define MZ_COUNT_VA_ARGS_IMPL(_1_,                                                                                     \
							  _2_,                                                                                     \
							  _3_,                                                                                     \
							  _4_,                                                                                     \
							  _5_,                                                                                     \
							  _6_,                                                                                     \
							  _7_,                                                                                     \
							  _8_,                                                                                     \
							  _9_,                                                                                     \
							  _10_,                                                                                    \
							  _11_,                                                                                    \
							  _12_,                                                                                    \
							  _13_,                                                                                    \
							  _14_,                                                                                    \
							  _15_,                                                                                    \
							  _16_,                                                                                    \
							  _17_,                                                                                    \
							  _18_,                                                                                    \
							  _19_,                                                                                    \
							  _20_,                                                                                    \
							  _21_,                                                                                    \
							  _22_,                                                                                    \
							  _23_,                                                                                    \
							  _24_,                                                                                    \
							  _25_,                                                                                    \
							  _26_,                                                                                    \
							  _27_,                                                                                    \
							  _28_,                                                                                    \
							  _29_,                                                                                    \
							  _30_,                                                                                    \
							  _31_,                                                                                    \
							  _32_,                                                                                    \
							  _33_,                                                                                    \
							  _34_,                                                                                    \
							  _35_,                                                                                    \
							  _36_,                                                                                    \
							  _37_,                                                                                    \
							  _38_,                                                                                    \
							  _39_,                                                                                    \
							  _40_,                                                                                    \
							  _41_,                                                                                    \
							  _42_,                                                                                    \
							  _43_,                                                                                    \
							  _44_,                                                                                    \
							  _45_,                                                                                    \
							  _46_,                                                                                    \
							  _47_,                                                                                    \
							  _48_,                                                                                    \
							  _49_,                                                                                    \
							  _50_,                                                                                    \
							  _51_,                                                                                    \
							  _52_,                                                                                    \
							  _53_,                                                                                    \
							  _54_,                                                                                    \
							  _55_,                                                                                    \
							  _56_,                                                                                    \
							  _57_,                                                                                    \
							  _58_,                                                                                    \
							  _59_,                                                                                    \
							  _60_,                                                                                    \
							  _61_,                                                                                    \
							  _62_,                                                                                    \
							  _63_,                                                                                    \
							  _64_,                                                                                    \
							  _65_,                                                                                    \
							  count,                                                                                   \
							  ...)                                                                                     \
	count

#define MZ_COUNT_VA_ARGS_IMPL_EXPANDER(args) MZ_COUNT_VA_ARGS_IMPL args

#define MZ_COUNT_VA_ARGS(...)                                                                                          \
	MZ_COUNT_VA_ARGS_IMPL_EXPANDER((__VA_ARGS__,                                                                       \
									65,                                                                                \
									64,                                                                                \
									63,                                                                                \
									62,                                                                                \
									61,                                                                                \
									60,                                                                                \
									59,                                                                                \
									58,                                                                                \
									57,                                                                                \
									56,                                                                                \
									55,                                                                                \
									54,                                                                                \
									53,                                                                                \
									52,                                                                                \
									51,                                                                                \
									50,                                                                                \
									49,                                                                                \
									48,                                                                                \
									47,                                                                                \
									46,                                                                                \
									45,                                                                                \
									44,                                                                                \
									43,                                                                                \
									42,                                                                                \
									41,                                                                                \
									40,                                                                                \
									39,                                                                                \
									38,                                                                                \
									37,                                                                                \
									36,                                                                                \
									35,                                                                                \
									34,                                                                                \
									33,                                                                                \
									32,                                                                                \
									31,                                                                                \
									30,                                                                                \
									29,                                                                                \
									28,                                                                                \
									27,                                                                                \
									26,                                                                                \
									25,                                                                                \
									24,                                                                                \
									23,                                                                                \
									22,                                                                                \
									21,                                                                                \
									20,                                                                                \
									19,                                                                                \
									18,                                                                                \
									17,                                                                                \
									16,                                                                                \
									15,                                                                                \
									14,                                                                                \
									13,                                                                                \
									12,                                                                                \
									11,                                                                                \
									10,                                                                                \
									9,                                                                                 \
									8,                                                                                 \
									7,                                                                                 \
									6,                                                                                 \
									5,                                                                                 \
									4,                                                                                 \
									3,                                                                                 \
									2,                                                                                 \
									1,                                                                                 \
									0))

#define MZ_MAKE_INDEXED_TPARAM(N) MZ_COMMA typename MZ_CONCAT(T, N)
#define MZ_MAKE_INDEXED_TARG(N)	  MZ_COMMA MZ_CONCAT(T, N)
#define MZ_0_TO_15				  0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15
#define MZ_0_TO_31				  MZ_0_TO_15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31
#define MZ_0_TO_47				  MZ_0_TO_31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47
#define MZ_0_TO_63				  MZ_0_TO_47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63

namespace mz
{
	using std::size_t;

	template <typename... T>
	struct type_list;

	namespace impl
	{
		inline constexpr size_t type_list_spec_max = 63;

		enum class type_list_selector_spec : int
		{
			first,
			skip_page,
			by_index
		};

		// clang-format off

		// selector
		template <typename List, size_t N, type_list_selector_spec Specialization = (
			N == 0 ? type_list_selector_spec::first : (
			N > type_list_spec_max ? type_list_selector_spec::skip_page : (
			type_list_selector_spec::by_index
		)))>
		struct type_list_selector_;

		// clang-format on

		// selector - first element
		template <typename T0, typename... T, size_t N>
		struct type_list_selector_<type_list<T0, T...>, N, type_list_selector_spec::first>
		{
			using type = T0;
		};

		// selector - skip whole pages (multiples of type_list_spec_max)
		template <typename List, size_t N>
		struct type_list_selector_<List, N, type_list_selector_spec::skip_page>
		{
			// invokes the skip_page specialization of the slicer then selects by (now offset) index
			using type = typename type_list_selector_<typename List::template slice<type_list_spec_max>,
													  N - type_list_spec_max>::type;
		};

		// selector - low-index elements
#define MAKE_SELECTOR_1(N, N0, ...)                                                                                    \
	template <typename T##N0 MZ_FOR_EACH(MZ_MAKE_INDEXED_TPARAM, __VA_ARGS__), typename... T>                          \
	struct type_list_selector_<type_list<T##N0 MZ_FOR_EACH(MZ_MAKE_INDEXED_TARG, __VA_ARGS__), T...>,                  \
							   N,                                                                                      \
							   type_list_selector_spec::by_index>                                                      \
	{                                                                                                                  \
		using type = T##N;                                                                                             \
	}
#define MAKE_SELECTOR(...) MAKE_SELECTOR_1(__VA_ARGS__)

		template <typename T0, typename T1, typename... T>
		struct type_list_selector_<type_list<T0, T1, T...>, 1, type_list_selector_spec::by_index>
		{
			using type = T1;
		};

		MAKE_SELECTOR(2, 0, 1, 2);
		MAKE_SELECTOR(3, 0, 1, 2, 3);
		MAKE_SELECTOR(4, 0, 1, 2, 3, 4);
		MAKE_SELECTOR(5, 0, 1, 2, 3, 4, 5);
		MAKE_SELECTOR(6, 0, 1, 2, 3, 4, 5, 6);
		MAKE_SELECTOR(7, 0, 1, 2, 3, 4, 5, 6, 7);
		MAKE_SELECTOR(8, 0, 1, 2, 3, 4, 5, 6, 7, 8);
		MAKE_SELECTOR(9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
		MAKE_SELECTOR(10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
		MAKE_SELECTOR(11, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
		MAKE_SELECTOR(12, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12);
		MAKE_SELECTOR(13, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13);
		MAKE_SELECTOR(14, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14);
		MAKE_SELECTOR(15, MZ_0_TO_15);
		MAKE_SELECTOR(16, MZ_0_TO_15, 16);
		MAKE_SELECTOR(17, MZ_0_TO_15, 16, 17);
		MAKE_SELECTOR(18, MZ_0_TO_15, 16, 17, 18);
		MAKE_SELECTOR(19, MZ_0_TO_15, 16, 17, 18, 19);
		MAKE_SELECTOR(20, MZ_0_TO_15, 16, 17, 18, 19, 20);
		MAKE_SELECTOR(21, MZ_0_TO_15, 16, 17, 18, 19, 20, 21);
		MAKE_SELECTOR(22, MZ_0_TO_15, 16, 17, 18, 19, 20, 21, 22);
		MAKE_SELECTOR(23, MZ_0_TO_15, 16, 17, 18, 19, 20, 21, 22, 23);
		MAKE_SELECTOR(24, MZ_0_TO_15, 16, 17, 18, 19, 20, 21, 22, 23, 24);
		MAKE_SELECTOR(25, MZ_0_TO_15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25);
		MAKE_SELECTOR(26, MZ_0_TO_15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26);
		MAKE_SELECTOR(27, MZ_0_TO_15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27);
		MAKE_SELECTOR(28, MZ_0_TO_15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28);
		MAKE_SELECTOR(29, MZ_0_TO_15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29);
		MAKE_SELECTOR(30, MZ_0_TO_15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30);
		MAKE_SELECTOR(31, MZ_0_TO_31);
		MAKE_SELECTOR(32, MZ_0_TO_31, 32);
		MAKE_SELECTOR(33, MZ_0_TO_31, 32, 33);
		MAKE_SELECTOR(34, MZ_0_TO_31, 32, 33, 34);
		MAKE_SELECTOR(35, MZ_0_TO_31, 32, 33, 34, 35);
		MAKE_SELECTOR(36, MZ_0_TO_31, 32, 33, 34, 35, 36);
		MAKE_SELECTOR(37, MZ_0_TO_31, 32, 33, 34, 35, 36, 37);
		MAKE_SELECTOR(38, MZ_0_TO_31, 32, 33, 34, 35, 36, 37, 38);
		MAKE_SELECTOR(39, MZ_0_TO_31, 32, 33, 34, 35, 36, 37, 38, 39);
		MAKE_SELECTOR(40, MZ_0_TO_31, 32, 33, 34, 35, 36, 37, 38, 39, 40);
		MAKE_SELECTOR(41, MZ_0_TO_31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41);
		MAKE_SELECTOR(42, MZ_0_TO_31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42);
		MAKE_SELECTOR(43, MZ_0_TO_31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43);
		MAKE_SELECTOR(44, MZ_0_TO_31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44);
		MAKE_SELECTOR(45, MZ_0_TO_31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45);
		MAKE_SELECTOR(46, MZ_0_TO_31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46);
		MAKE_SELECTOR(47, MZ_0_TO_47);
		MAKE_SELECTOR(48, MZ_0_TO_47, 48);
		MAKE_SELECTOR(49, MZ_0_TO_47, 48, 49);
		MAKE_SELECTOR(50, MZ_0_TO_47, 48, 49, 50);
		MAKE_SELECTOR(51, MZ_0_TO_47, 48, 49, 50, 51);
		MAKE_SELECTOR(52, MZ_0_TO_47, 48, 49, 50, 51, 52);
		MAKE_SELECTOR(53, MZ_0_TO_47, 48, 49, 50, 51, 52, 53);
		MAKE_SELECTOR(54, MZ_0_TO_47, 48, 49, 50, 51, 52, 53, 54);
		MAKE_SELECTOR(55, MZ_0_TO_47, 48, 49, 50, 51, 52, 53, 54, 55);
		MAKE_SELECTOR(56, MZ_0_TO_47, 48, 49, 50, 51, 52, 53, 54, 55, 56);
		MAKE_SELECTOR(57, MZ_0_TO_47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57);
		MAKE_SELECTOR(58, MZ_0_TO_47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58);
		MAKE_SELECTOR(59, MZ_0_TO_47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59);
		MAKE_SELECTOR(60, MZ_0_TO_47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60);
		MAKE_SELECTOR(61, MZ_0_TO_47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61);
		MAKE_SELECTOR(62, MZ_0_TO_47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62);
		MAKE_SELECTOR(63, MZ_0_TO_63);

#undef MAKE_SELECTOR_1
#undef MAKE_SELECTOR

		// selector - helper typedef
		template <typename List, size_t N>
		using type_list_select_ = typename type_list_selector_<List, N>::type;

		enum class type_list_slicer_spec : int
		{
			empty,
			first,
			all,
			single_by_index,
			prefix,
			skip_first_N,
			skip_page,
			big_range
		};

		// clang-format off

		// slicer
		template <typename List, size_t Start, size_t Length, type_list_slicer_spec Specialization = (
			List::length == 0 || Length == 0 ? type_list_slicer_spec::empty : (
			Start == 0 && Length == 1 ? type_list_slicer_spec::first : (
			Start == 0 && List::length == Length ? type_list_slicer_spec::all : (
			Start > type_list_spec_max ? type_list_slicer_spec::skip_page : (
			Length == 1 ? type_list_slicer_spec::single_by_index : (
			Start == 0 && Length <= type_list_spec_max+1 ? type_list_slicer_spec::prefix : (
			Start > 0 ? type_list_slicer_spec::skip_first_N : (
			type_list_slicer_spec::big_range
		))))))))>
		struct type_list_slicer_;

		// clang-format on

		// slicer - empty range
		template <typename List, size_t Start, size_t Length>
		struct type_list_slicer_<List, Start, Length, type_list_slicer_spec::empty>
		{
			using type = type_list<>;
		};

		// slicer - first element
		template <typename T0, typename... T, size_t Start, size_t Length>
		struct type_list_slicer_<type_list<T0, T...>, Start, Length, type_list_slicer_spec::first>
		{
			using type = type_list<T0>;
		};

		// slicer - all (range is entire list)
		template <typename List, size_t Start, size_t Length>
		struct type_list_slicer_<List, Start, Length, type_list_slicer_spec::all>
		{
			using type = List;
		};

		// slicer - skip whole pages (multiples of type_list_spec_max)
		template <typename List, size_t Start, size_t Length>
		struct type_list_slicer_<List, Start, Length, type_list_slicer_spec::skip_page>
		{
			// invokes the skip_first_N specialization repeatedly until Start is <= type_list_spec_max
			using type = typename type_list_slicer_<typename List::template slice<type_list_spec_max>,
													Start - type_list_spec_max,
													Length>::type;
		};

		// slicer - low-index elements

#define MAKE_SINGLE_ELEMENT_SLICER_1(N, N0, ...)                                                                       \
	template <typename T##N0 MZ_FOR_EACH(MZ_MAKE_INDEXED_TPARAM, __VA_ARGS__), typename... T>                          \
	struct type_list_slicer_<type_list<T##N0 MZ_FOR_EACH(MZ_MAKE_INDEXED_TARG, __VA_ARGS__), T...>,                    \
							 N,                                                                                        \
							 1,                                                                                        \
							 type_list_slicer_spec::single_by_index>                                                   \
	{                                                                                                                  \
		using type = type_list<T##N>;                                                                                  \
	}
#define MAKE_SINGLE_ELEMENT_SLICER(...) MAKE_SINGLE_ELEMENT_SLICER_1(__VA_ARGS__)

		template <typename T0, typename T1, typename... T>
		struct type_list_slicer_<type_list<T0, T1, T...>, 1, 1, type_list_slicer_spec::single_by_index>
		{
			using type = type_list<T1>;
		};

		MAKE_SINGLE_ELEMENT_SLICER(2, 0, 1, 2);
		MAKE_SINGLE_ELEMENT_SLICER(3, 0, 1, 2, 3);
		MAKE_SINGLE_ELEMENT_SLICER(4, 0, 1, 2, 3, 4);
		MAKE_SINGLE_ELEMENT_SLICER(5, 0, 1, 2, 3, 4, 5);
		MAKE_SINGLE_ELEMENT_SLICER(6, 0, 1, 2, 3, 4, 5, 6);
		MAKE_SINGLE_ELEMENT_SLICER(7, 0, 1, 2, 3, 4, 5, 6, 7);
		MAKE_SINGLE_ELEMENT_SLICER(8, 0, 1, 2, 3, 4, 5, 6, 7, 8);
		MAKE_SINGLE_ELEMENT_SLICER(9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
		MAKE_SINGLE_ELEMENT_SLICER(10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
		MAKE_SINGLE_ELEMENT_SLICER(11, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
		MAKE_SINGLE_ELEMENT_SLICER(12, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12);
		MAKE_SINGLE_ELEMENT_SLICER(13, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13);
		MAKE_SINGLE_ELEMENT_SLICER(14, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14);
		MAKE_SINGLE_ELEMENT_SLICER(15, MZ_0_TO_15);
		MAKE_SINGLE_ELEMENT_SLICER(16, MZ_0_TO_15, 16);
		MAKE_SINGLE_ELEMENT_SLICER(17, MZ_0_TO_15, 16, 17);
		MAKE_SINGLE_ELEMENT_SLICER(18, MZ_0_TO_15, 16, 17, 18);
		MAKE_SINGLE_ELEMENT_SLICER(19, MZ_0_TO_15, 16, 17, 18, 19);
		MAKE_SINGLE_ELEMENT_SLICER(20, MZ_0_TO_15, 16, 17, 18, 19, 20);
		MAKE_SINGLE_ELEMENT_SLICER(21, MZ_0_TO_15, 16, 17, 18, 19, 20, 21);
		MAKE_SINGLE_ELEMENT_SLICER(22, MZ_0_TO_15, 16, 17, 18, 19, 20, 21, 22);
		MAKE_SINGLE_ELEMENT_SLICER(23, MZ_0_TO_15, 16, 17, 18, 19, 20, 21, 22, 23);
		MAKE_SINGLE_ELEMENT_SLICER(24, MZ_0_TO_15, 16, 17, 18, 19, 20, 21, 22, 23, 24);
		MAKE_SINGLE_ELEMENT_SLICER(25, MZ_0_TO_15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25);
		MAKE_SINGLE_ELEMENT_SLICER(26, MZ_0_TO_15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26);
		MAKE_SINGLE_ELEMENT_SLICER(27, MZ_0_TO_15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27);
		MAKE_SINGLE_ELEMENT_SLICER(28, MZ_0_TO_15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28);
		MAKE_SINGLE_ELEMENT_SLICER(29, MZ_0_TO_15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29);
		MAKE_SINGLE_ELEMENT_SLICER(30, MZ_0_TO_15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30);
		MAKE_SINGLE_ELEMENT_SLICER(31, MZ_0_TO_31);
		MAKE_SINGLE_ELEMENT_SLICER(32, MZ_0_TO_31, 32);
		MAKE_SINGLE_ELEMENT_SLICER(33, MZ_0_TO_31, 32, 33);
		MAKE_SINGLE_ELEMENT_SLICER(34, MZ_0_TO_31, 32, 33, 34);
		MAKE_SINGLE_ELEMENT_SLICER(35, MZ_0_TO_31, 32, 33, 34, 35);
		MAKE_SINGLE_ELEMENT_SLICER(36, MZ_0_TO_31, 32, 33, 34, 35, 36);
		MAKE_SINGLE_ELEMENT_SLICER(37, MZ_0_TO_31, 32, 33, 34, 35, 36, 37);
		MAKE_SINGLE_ELEMENT_SLICER(38, MZ_0_TO_31, 32, 33, 34, 35, 36, 37, 38);
		MAKE_SINGLE_ELEMENT_SLICER(39, MZ_0_TO_31, 32, 33, 34, 35, 36, 37, 38, 39);
		MAKE_SINGLE_ELEMENT_SLICER(40, MZ_0_TO_31, 32, 33, 34, 35, 36, 37, 38, 39, 40);
		MAKE_SINGLE_ELEMENT_SLICER(41, MZ_0_TO_31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41);
		MAKE_SINGLE_ELEMENT_SLICER(42, MZ_0_TO_31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42);
		MAKE_SINGLE_ELEMENT_SLICER(43, MZ_0_TO_31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43);
		MAKE_SINGLE_ELEMENT_SLICER(44, MZ_0_TO_31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44);
		MAKE_SINGLE_ELEMENT_SLICER(45, MZ_0_TO_31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45);
		MAKE_SINGLE_ELEMENT_SLICER(46, MZ_0_TO_31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46);
		MAKE_SINGLE_ELEMENT_SLICER(47, MZ_0_TO_47);
		MAKE_SINGLE_ELEMENT_SLICER(48, MZ_0_TO_47, 48);
		MAKE_SINGLE_ELEMENT_SLICER(49, MZ_0_TO_47, 48, 49);
		MAKE_SINGLE_ELEMENT_SLICER(50, MZ_0_TO_47, 48, 49, 50);
		MAKE_SINGLE_ELEMENT_SLICER(51, MZ_0_TO_47, 48, 49, 50, 51);
		MAKE_SINGLE_ELEMENT_SLICER(52, MZ_0_TO_47, 48, 49, 50, 51, 52);
		MAKE_SINGLE_ELEMENT_SLICER(53, MZ_0_TO_47, 48, 49, 50, 51, 52, 53);
		MAKE_SINGLE_ELEMENT_SLICER(54, MZ_0_TO_47, 48, 49, 50, 51, 52, 53, 54);
		MAKE_SINGLE_ELEMENT_SLICER(55, MZ_0_TO_47, 48, 49, 50, 51, 52, 53, 54, 55);
		MAKE_SINGLE_ELEMENT_SLICER(56, MZ_0_TO_47, 48, 49, 50, 51, 52, 53, 54, 55, 56);
		MAKE_SINGLE_ELEMENT_SLICER(57, MZ_0_TO_47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57);
		MAKE_SINGLE_ELEMENT_SLICER(58, MZ_0_TO_47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58);
		MAKE_SINGLE_ELEMENT_SLICER(59, MZ_0_TO_47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59);
		MAKE_SINGLE_ELEMENT_SLICER(60, MZ_0_TO_47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60);
		MAKE_SINGLE_ELEMENT_SLICER(61, MZ_0_TO_47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61);
		MAKE_SINGLE_ELEMENT_SLICER(62, MZ_0_TO_47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62);
		MAKE_SINGLE_ELEMENT_SLICER(63, MZ_0_TO_63);

#undef MAKE_SINGLE_ELEMENT_SLICER_1
#undef MAKE_SINGLE_ELEMENT_SLICER

		// slicer - prefixes

#define MAKE_PREFIX_SLICER_1(N0, ...)                                                                                  \
	template <typename T##N0 MZ_FOR_EACH(MZ_MAKE_INDEXED_TPARAM, __VA_ARGS__), typename... T>                          \
	struct type_list_slicer_<type_list<T##N0 MZ_FOR_EACH(MZ_MAKE_INDEXED_TARG, __VA_ARGS__), T...>,                    \
							 0,                                                                                        \
							 MZ_COUNT_VA_ARGS(__VA_ARGS__) + 1,                                                        \
							 type_list_slicer_spec::prefix>                                                            \
	{                                                                                                                  \
		using type = type_list<T0 MZ_FOR_EACH(MZ_MAKE_INDEXED_TARG, __VA_ARGS__)>;                                     \
	}
#define MAKE_PREFIX_SLICER(...) MAKE_PREFIX_SLICER_1(__VA_ARGS__)

		template <typename T0, typename T1, typename... T>
		struct type_list_slicer_<type_list<T0, T1, T...>, 0, 2, type_list_slicer_spec::prefix>
		{
			using type = type_list<T0, T1>;
		};

		MAKE_PREFIX_SLICER(0, 1, 2);
		MAKE_PREFIX_SLICER(0, 1, 2, 3);
		MAKE_PREFIX_SLICER(0, 1, 2, 3, 4);
		MAKE_PREFIX_SLICER(0, 1, 2, 3, 4, 5);
		MAKE_PREFIX_SLICER(0, 1, 2, 3, 4, 5, 6);
		MAKE_PREFIX_SLICER(0, 1, 2, 3, 4, 5, 6, 7);
		MAKE_PREFIX_SLICER(0, 1, 2, 3, 4, 5, 6, 7, 8);
		MAKE_PREFIX_SLICER(0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
		MAKE_PREFIX_SLICER(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
		MAKE_PREFIX_SLICER(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
		MAKE_PREFIX_SLICER(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12);
		MAKE_PREFIX_SLICER(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13);
		MAKE_PREFIX_SLICER(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14);
		MAKE_PREFIX_SLICER(MZ_0_TO_15);
		MAKE_PREFIX_SLICER(MZ_0_TO_15, 16);
		MAKE_PREFIX_SLICER(MZ_0_TO_15, 16, 17);
		MAKE_PREFIX_SLICER(MZ_0_TO_15, 16, 17, 18);
		MAKE_PREFIX_SLICER(MZ_0_TO_15, 16, 17, 18, 19);
		MAKE_PREFIX_SLICER(MZ_0_TO_15, 16, 17, 18, 19, 20);
		MAKE_PREFIX_SLICER(MZ_0_TO_15, 16, 17, 18, 19, 20, 21);
		MAKE_PREFIX_SLICER(MZ_0_TO_15, 16, 17, 18, 19, 20, 21, 22);
		MAKE_PREFIX_SLICER(MZ_0_TO_15, 16, 17, 18, 19, 20, 21, 22, 23);
		MAKE_PREFIX_SLICER(MZ_0_TO_15, 16, 17, 18, 19, 20, 21, 22, 23, 24);
		MAKE_PREFIX_SLICER(MZ_0_TO_15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25);
		MAKE_PREFIX_SLICER(MZ_0_TO_15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26);
		MAKE_PREFIX_SLICER(MZ_0_TO_15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27);
		MAKE_PREFIX_SLICER(MZ_0_TO_15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28);
		MAKE_PREFIX_SLICER(MZ_0_TO_15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29);
		MAKE_PREFIX_SLICER(MZ_0_TO_15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30);
		MAKE_PREFIX_SLICER(MZ_0_TO_31);
		MAKE_PREFIX_SLICER(MZ_0_TO_31, 32);
		MAKE_PREFIX_SLICER(MZ_0_TO_31, 32, 33);
		MAKE_PREFIX_SLICER(MZ_0_TO_31, 32, 33, 34);
		MAKE_PREFIX_SLICER(MZ_0_TO_31, 32, 33, 34, 35);
		MAKE_PREFIX_SLICER(MZ_0_TO_31, 32, 33, 34, 35, 36);
		MAKE_PREFIX_SLICER(MZ_0_TO_31, 32, 33, 34, 35, 36, 37);
		MAKE_PREFIX_SLICER(MZ_0_TO_31, 32, 33, 34, 35, 36, 37, 38);
		MAKE_PREFIX_SLICER(MZ_0_TO_31, 32, 33, 34, 35, 36, 37, 38, 39);
		MAKE_PREFIX_SLICER(MZ_0_TO_31, 32, 33, 34, 35, 36, 37, 38, 39, 40);
		MAKE_PREFIX_SLICER(MZ_0_TO_31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41);
		MAKE_PREFIX_SLICER(MZ_0_TO_31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42);
		MAKE_PREFIX_SLICER(MZ_0_TO_31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43);
		MAKE_PREFIX_SLICER(MZ_0_TO_31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44);
		MAKE_PREFIX_SLICER(MZ_0_TO_31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45);
		MAKE_PREFIX_SLICER(MZ_0_TO_31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46);
		MAKE_PREFIX_SLICER(MZ_0_TO_47);
		MAKE_PREFIX_SLICER(MZ_0_TO_47, 48);
		MAKE_PREFIX_SLICER(MZ_0_TO_47, 48, 49);
		MAKE_PREFIX_SLICER(MZ_0_TO_47, 48, 49, 50);
		MAKE_PREFIX_SLICER(MZ_0_TO_47, 48, 49, 50, 51);
		MAKE_PREFIX_SLICER(MZ_0_TO_47, 48, 49, 50, 51, 52);
		MAKE_PREFIX_SLICER(MZ_0_TO_47, 48, 49, 50, 51, 52, 53);
		MAKE_PREFIX_SLICER(MZ_0_TO_47, 48, 49, 50, 51, 52, 53, 54);
		MAKE_PREFIX_SLICER(MZ_0_TO_47, 48, 49, 50, 51, 52, 53, 54, 55);
		MAKE_PREFIX_SLICER(MZ_0_TO_47, 48, 49, 50, 51, 52, 53, 54, 55, 56);
		MAKE_PREFIX_SLICER(MZ_0_TO_47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57);
		MAKE_PREFIX_SLICER(MZ_0_TO_47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58);
		MAKE_PREFIX_SLICER(MZ_0_TO_47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59);
		MAKE_PREFIX_SLICER(MZ_0_TO_47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60);
		MAKE_PREFIX_SLICER(MZ_0_TO_47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61);
		MAKE_PREFIX_SLICER(MZ_0_TO_47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62);
		MAKE_PREFIX_SLICER(MZ_0_TO_63);

#undef MAKE_PREFIX_SLICER_1
#undef MAKE_PREFIX_SLICER

		// slicer - skip first N

#define MAKE_SKIP_N_SLICER_1(N, N0, N1, ...)                                                                           \
	template <typename T##N0,                                                                                          \
			  typename T##N1 MZ_FOR_EACH(MZ_MAKE_INDEXED_TPARAM, __VA_ARGS__),                                         \
			  typename... T,                                                                                           \
			  size_t Length>                                                                                           \
	struct type_list_slicer_<type_list<T##N0, T##N1 MZ_FOR_EACH(MZ_MAKE_INDEXED_TARG, __VA_ARGS__), T...>,             \
							 N,                                                                                        \
							 Length,                                                                                   \
							 type_list_slicer_spec::skip_first_N>                                                      \
	{                                                                                                                  \
		using type = typename type_list_slicer_<type_list<T##N, T...>, 0, Length>::type;                               \
	}
#define MAKE_SKIP_N_SLICER(...) MAKE_SKIP_N_SLICER_1(__VA_ARGS__)

		template <typename T0, typename T1, typename... T, size_t Length>
		struct type_list_slicer_<type_list<T0, T1, T...>, 1, Length, type_list_slicer_spec::skip_first_N>
		{
			using type = typename type_list_slicer_<type_list<T1, T...>, 0, Length>::type;
		};

		template <typename T0, typename T1, typename T2, typename... T, size_t Length>
		struct type_list_slicer_<type_list<T0, T1, T2, T...>, 2, Length, type_list_slicer_spec::skip_first_N>
		{
			using type = typename type_list_slicer_<type_list<T2, T...>, 0, Length>::type;
		};

		MAKE_SKIP_N_SLICER(3, 0, 1, 2, 3);
		MAKE_SKIP_N_SLICER(4, 0, 1, 2, 3, 4);
		MAKE_SKIP_N_SLICER(5, 0, 1, 2, 3, 4, 5);
		MAKE_SKIP_N_SLICER(6, 0, 1, 2, 3, 4, 5, 6);
		MAKE_SKIP_N_SLICER(7, 0, 1, 2, 3, 4, 5, 6, 7);
		MAKE_SKIP_N_SLICER(8, 0, 1, 2, 3, 4, 5, 6, 7, 8);
		MAKE_SKIP_N_SLICER(9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
		MAKE_SKIP_N_SLICER(10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
		MAKE_SKIP_N_SLICER(11, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
		MAKE_SKIP_N_SLICER(12, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12);
		MAKE_SKIP_N_SLICER(13, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13);
		MAKE_SKIP_N_SLICER(14, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14);
		MAKE_SKIP_N_SLICER(15, MZ_0_TO_15);
		MAKE_SKIP_N_SLICER(16, MZ_0_TO_15, 16);
		MAKE_SKIP_N_SLICER(17, MZ_0_TO_15, 16, 17);
		MAKE_SKIP_N_SLICER(18, MZ_0_TO_15, 16, 17, 18);
		MAKE_SKIP_N_SLICER(19, MZ_0_TO_15, 16, 17, 18, 19);
		MAKE_SKIP_N_SLICER(20, MZ_0_TO_15, 16, 17, 18, 19, 20);
		MAKE_SKIP_N_SLICER(21, MZ_0_TO_15, 16, 17, 18, 19, 20, 21);
		MAKE_SKIP_N_SLICER(22, MZ_0_TO_15, 16, 17, 18, 19, 20, 21, 22);
		MAKE_SKIP_N_SLICER(23, MZ_0_TO_15, 16, 17, 18, 19, 20, 21, 22, 23);
		MAKE_SKIP_N_SLICER(24, MZ_0_TO_15, 16, 17, 18, 19, 20, 21, 22, 23, 24);
		MAKE_SKIP_N_SLICER(25, MZ_0_TO_15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25);
		MAKE_SKIP_N_SLICER(26, MZ_0_TO_15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26);
		MAKE_SKIP_N_SLICER(27, MZ_0_TO_15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27);
		MAKE_SKIP_N_SLICER(28, MZ_0_TO_15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28);
		MAKE_SKIP_N_SLICER(29, MZ_0_TO_15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29);
		MAKE_SKIP_N_SLICER(30, MZ_0_TO_15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30);
		MAKE_SKIP_N_SLICER(31, MZ_0_TO_31);
		MAKE_SKIP_N_SLICER(32, MZ_0_TO_31, 32);
		MAKE_SKIP_N_SLICER(33, MZ_0_TO_31, 32, 33);
		MAKE_SKIP_N_SLICER(34, MZ_0_TO_31, 32, 33, 34);
		MAKE_SKIP_N_SLICER(35, MZ_0_TO_31, 32, 33, 34, 35);
		MAKE_SKIP_N_SLICER(36, MZ_0_TO_31, 32, 33, 34, 35, 36);
		MAKE_SKIP_N_SLICER(37, MZ_0_TO_31, 32, 33, 34, 35, 36, 37);
		MAKE_SKIP_N_SLICER(38, MZ_0_TO_31, 32, 33, 34, 35, 36, 37, 38);
		MAKE_SKIP_N_SLICER(39, MZ_0_TO_31, 32, 33, 34, 35, 36, 37, 38, 39);
		MAKE_SKIP_N_SLICER(40, MZ_0_TO_31, 32, 33, 34, 35, 36, 37, 38, 39, 40);
		MAKE_SKIP_N_SLICER(41, MZ_0_TO_31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41);
		MAKE_SKIP_N_SLICER(42, MZ_0_TO_31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42);
		MAKE_SKIP_N_SLICER(43, MZ_0_TO_31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43);
		MAKE_SKIP_N_SLICER(44, MZ_0_TO_31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44);
		MAKE_SKIP_N_SLICER(45, MZ_0_TO_31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45);
		MAKE_SKIP_N_SLICER(46, MZ_0_TO_31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46);
		MAKE_SKIP_N_SLICER(47, MZ_0_TO_47);
		MAKE_SKIP_N_SLICER(48, MZ_0_TO_47, 48);
		MAKE_SKIP_N_SLICER(49, MZ_0_TO_47, 48, 49);
		MAKE_SKIP_N_SLICER(50, MZ_0_TO_47, 48, 49, 50);
		MAKE_SKIP_N_SLICER(51, MZ_0_TO_47, 48, 49, 50, 51);
		MAKE_SKIP_N_SLICER(52, MZ_0_TO_47, 48, 49, 50, 51, 52);
		MAKE_SKIP_N_SLICER(53, MZ_0_TO_47, 48, 49, 50, 51, 52, 53);
		MAKE_SKIP_N_SLICER(54, MZ_0_TO_47, 48, 49, 50, 51, 52, 53, 54);
		MAKE_SKIP_N_SLICER(55, MZ_0_TO_47, 48, 49, 50, 51, 52, 53, 54, 55);
		MAKE_SKIP_N_SLICER(56, MZ_0_TO_47, 48, 49, 50, 51, 52, 53, 54, 55, 56);
		MAKE_SKIP_N_SLICER(57, MZ_0_TO_47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57);
		MAKE_SKIP_N_SLICER(58, MZ_0_TO_47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58);
		MAKE_SKIP_N_SLICER(59, MZ_0_TO_47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59);
		MAKE_SKIP_N_SLICER(60, MZ_0_TO_47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60);
		MAKE_SKIP_N_SLICER(61, MZ_0_TO_47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61);
		MAKE_SKIP_N_SLICER(62, MZ_0_TO_47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62);
		MAKE_SKIP_N_SLICER(63, MZ_0_TO_63);
		MAKE_SKIP_N_SLICER(64, MZ_0_TO_63, 64);

#undef MAKE_SKIP_N_SLICER_1
#undef MAKE_SKIP_N_SLICER

		// clang-format on

		// slicer - arbitrary ranges with length > (type_list_spec_max + 1)
		template <typename, size_t, typename>
		struct type_list_index_sequence_slicer_;
		template <typename List, size_t Start, size_t... Seq>
		struct type_list_index_sequence_slicer_<List, Start, std::index_sequence<Seq...>>
		{
			using type = type_list<type_list_select_<List, Start + Seq>...>;
		};
		template <typename List, size_t Start, size_t Length>
		struct type_list_slicer_<List, Start, Length, type_list_slicer_spec::big_range>
			: type_list_index_sequence_slicer_<List, Start, std::make_index_sequence<Length>>
		{};

		// slicer - helper typedef
		template <typename List, size_t Start, size_t Length>
		using type_list_slice_ = typename type_list_slicer_<List, Start, Length>::type;

	}

	template <>
	struct type_list<>
	{
		static constexpr size_t length = 0;

		// select and slice are clearly nonsensical in this case
		// but templates will break if they're not here

		template <size_t Index>
		using select = impl::type_list_select_<type_list<>, Index>;

		template <size_t Start, size_t Length = (length - Start)>
		using slice = impl::type_list_slice_<type_list<>, Start, Length>;
	};

	template <typename T>
	struct type_list<T>
	{
		static constexpr size_t length = 1;

		using first = T;
		using type	= first;

		template <size_t Index>
		using select = impl::type_list_select_<type_list<T>, Index>;

		template <size_t Start, size_t Length = (length - Start)>
		using slice = impl::type_list_slice_<type_list<T>, Start, Length>;
	};

	template <typename T0, typename... T>
	struct type_list<T0, T...>
	{
		static constexpr size_t length = 1 + sizeof...(T);

		using first = T0;
		using type	= first;

		template <size_t Index>
		using select = impl::type_list_select_<type_list<T0, T...>, Index>;

		template <size_t Start, size_t Length = (length - Start)>
		using slice = impl::type_list_slice_<type_list<T0, T...>, Start, Length>;
	};
}

#undef MZ_COMMA
#undef MZ_CONCAT_1
#undef MZ_CONCAT

#undef MZ_FOR_EACH_FORCE_UNROLL
#undef MZ_FOR_EACH_IMPL_0
#undef MZ_FOR_EACH_IMPL_1
#undef MZ_FOR_EACH_IMPL_2
#undef MZ_FOR_EACH_IMPL_3
#undef MZ_FOR_EACH_IMPL_4
#undef MZ_FOR_EACH_IMPL_5
#undef MZ_FOR_EACH_IMPL_6
#undef MZ_FOR_EACH_IMPL_7
#undef MZ_FOR_EACH_IMPL_8
#undef MZ_FOR_EACH_IMPL_9
#undef MZ_FOR_EACH_IMPL_10
#undef MZ_FOR_EACH_IMPL_11
#undef MZ_FOR_EACH_IMPL_12
#undef MZ_FOR_EACH_IMPL_13
#undef MZ_FOR_EACH_IMPL_14
#undef MZ_FOR_EACH_IMPL_15
#undef MZ_FOR_EACH_IMPL_16
#undef MZ_FOR_EACH_IMPL_17
#undef MZ_FOR_EACH_IMPL_18
#undef MZ_FOR_EACH_IMPL_19
#undef MZ_FOR_EACH_IMPL_20
#undef MZ_FOR_EACH_IMPL_21
#undef MZ_FOR_EACH_IMPL_22
#undef MZ_FOR_EACH_IMPL_23
#undef MZ_FOR_EACH_IMPL_24
#undef MZ_FOR_EACH_IMPL_25
#undef MZ_FOR_EACH_IMPL_26
#undef MZ_FOR_EACH_IMPL_27
#undef MZ_FOR_EACH_IMPL_28
#undef MZ_FOR_EACH_IMPL_29
#undef MZ_FOR_EACH_IMPL_30
#undef MZ_FOR_EACH_IMPL_31
#undef MZ_FOR_EACH_IMPL_32
#undef MZ_FOR_EACH_IMPL_33
#undef MZ_FOR_EACH_IMPL_34
#undef MZ_FOR_EACH_IMPL_35
#undef MZ_FOR_EACH_IMPL_36
#undef MZ_FOR_EACH_IMPL_37
#undef MZ_FOR_EACH_IMPL_38
#undef MZ_FOR_EACH_IMPL_39
#undef MZ_FOR_EACH_IMPL_40
#undef MZ_FOR_EACH_IMPL_41
#undef MZ_FOR_EACH_IMPL_42
#undef MZ_FOR_EACH_IMPL_43
#undef MZ_FOR_EACH_IMPL_44
#undef MZ_FOR_EACH_IMPL_45
#undef MZ_FOR_EACH_IMPL_46
#undef MZ_FOR_EACH_IMPL_47
#undef MZ_FOR_EACH_IMPL_48
#undef MZ_FOR_EACH_IMPL_49
#undef MZ_FOR_EACH_IMPL_50
#undef MZ_FOR_EACH_IMPL_51
#undef MZ_FOR_EACH_IMPL_52
#undef MZ_FOR_EACH_IMPL_53
#undef MZ_FOR_EACH_IMPL_54
#undef MZ_FOR_EACH_IMPL_55
#undef MZ_FOR_EACH_IMPL_56
#undef MZ_FOR_EACH_IMPL_57
#undef MZ_FOR_EACH_IMPL_58
#undef MZ_FOR_EACH_IMPL_59
#undef MZ_FOR_EACH_IMPL_60
#undef MZ_FOR_EACH_IMPL_61
#undef MZ_FOR_EACH_IMPL_62
#undef MZ_FOR_EACH_IMPL_63
#undef MZ_FOR_EACH_IMPL_64
#undef MZ_FOR_EACH_IMPL_65
#undef MZ_FOR_EACH_IMPL_SELECT
#undef MZ_FOR_EACH

#undef MZ_COUNT_VA_ARGS_IMPL
#undef MZ_COUNT_VA_ARGS_IMPL_EXPANDER
#undef MZ_COUNT_VA_ARGS

#undef MZ_MAKE_INDEXED_TPARAM
#undef MZ_MAKE_INDEXED_TARG
#undef MZ_0_TO_15
#undef MZ_0_TO_31
#undef MZ_0_TO_47
#undef MZ_0_TO_63
