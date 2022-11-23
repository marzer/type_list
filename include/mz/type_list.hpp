//----------------------------------------------------------------------------------------------------------------------
//
// mz::type_list
// https://github.com/marzer/type_list
// SPDX-License-Identifier: MIT
//
//----------------------------------------------------------------------------------------------------------------------
//         THIS FILE WAS ASSEMBLED FROM MULTIPLE HEADER FILES BY A SCRIPT - PLEASE DON'T EDIT IT DIRECTLY
//                              upstream: 2c7140f9e5c632ec99d2eb719e68739b7fc921ed
//----------------------------------------------------------------------------------------------------------------------
//
// MIT License
//
// Copyright (c) Mark Gillard <mark.gillard@outlook.com.au>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
// documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to
// permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of
// the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
// TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
//----------------------------------------------------------------------------------------------------------------------
#ifndef MZ_TYPE_LIST_HPP
#define MZ_TYPE_LIST_HPP

#define MZ_TYPE_LIST_VERSION_MAJOR 1
#define MZ_TYPE_LIST_VERSION_MINOR 0
#define MZ_TYPE_LIST_VERSION_PATCH 0

#ifndef MZ_CONCAT
	#define MZ_CONCAT_2(x, y) x##y
	#define MZ_CONCAT_1(x, y) MZ_CONCAT_2(x, y)
	#define MZ_CONCAT(x, y)	  MZ_CONCAT_1(x, y)
#endif

#ifndef MZ_CLANG
	#ifdef __clang__
		#define MZ_CLANG __clang_major__
	#else
		#define MZ_CLANG 0
	#endif
#endif

#ifndef MZ_MSVC_LIKE
	#ifdef _MSC_VER
		#define MZ_MSVC_LIKE _MSC_VER
	#else
		#define MZ_MSVC_LIKE 0
	#endif
#endif

#ifndef MZ_HAS_BUILTIN
	#ifdef __has_builtin
		#define MZ_HAS_BUILTIN(name) __has_builtin(name)
	#else
		#define MZ_HAS_BUILTIN(name) 0
	#endif
#endif

#ifndef MZ_FOR_EACH

	#define MZ_FOR_EACH_FORCE_UNROLL(x) x // without this msvc treats forwarded __VA_ARGS__ as a single token

	#define MZ_FOR_EACH_IMPL_0(fn, x)		 fn(x)
	#define MZ_FOR_EACH_IMPL_1(fn, x, ...)	 fn(x) MZ_FOR_EACH_IMPL_0(fn, __VA_ARGS__)
	#define MZ_FOR_EACH_IMPL_2(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_1(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_3(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_2(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_4(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_3(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_5(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_4(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_6(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_5(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_7(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_6(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_8(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_7(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_9(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_8(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_10(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_9(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_11(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_10(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_12(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_11(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_13(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_12(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_14(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_13(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_15(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_14(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_16(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_15(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_17(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_16(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_18(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_17(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_19(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_18(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_20(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_19(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_21(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_20(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_22(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_21(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_23(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_22(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_24(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_23(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_25(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_24(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_26(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_25(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_27(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_26(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_28(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_27(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_29(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_28(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_30(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_29(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_31(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_30(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_32(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_31(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_33(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_32(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_34(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_33(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_35(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_34(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_36(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_35(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_37(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_36(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_38(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_37(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_39(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_38(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_40(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_39(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_41(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_40(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_42(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_41(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_43(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_42(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_44(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_43(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_45(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_44(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_46(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_45(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_47(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_46(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_48(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_47(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_49(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_48(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_50(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_49(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_51(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_50(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_52(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_51(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_53(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_52(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_54(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_53(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_55(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_54(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_56(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_55(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_57(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_56(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_58(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_57(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_59(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_58(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_60(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_59(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_61(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_60(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_62(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_61(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_63(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_62(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_64(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_63(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_65(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_64(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_66(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_65(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_67(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_66(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_68(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_67(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_69(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_68(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_70(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_69(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_71(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_70(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_72(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_71(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_73(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_72(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_74(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_73(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_75(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_74(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_76(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_75(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_77(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_76(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_78(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_77(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_79(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_78(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_80(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_79(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_81(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_80(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_82(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_81(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_83(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_82(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_84(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_83(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_85(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_84(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_86(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_85(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_87(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_86(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_88(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_87(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_89(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_88(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_90(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_89(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_91(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_90(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_92(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_91(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_93(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_92(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_94(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_93(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_95(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_94(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_96(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_95(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_97(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_96(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_98(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_97(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_99(fn, x, ...)	 fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_98(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_100(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_99(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_101(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_100(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_102(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_101(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_103(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_102(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_104(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_103(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_105(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_104(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_106(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_105(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_107(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_106(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_108(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_107(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_109(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_108(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_110(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_109(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_111(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_110(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_112(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_111(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_113(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_112(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_114(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_113(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_115(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_114(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_116(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_115(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_117(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_116(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_118(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_117(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_119(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_118(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_120(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_119(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_121(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_120(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_122(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_121(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_123(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_122(fn, __VA_ARGS__))
	#define MZ_FOR_EACH_IMPL_124(fn, x, ...) fn(x) MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_123(fn, __VA_ARGS__))

	// clang-format off

	#define MZ_FOR_EACH_IMPL_SELECT(_0,  _1,  _2,  _3,  _4,  _5,  _6,  _7,  _8,  _9,  _10, _11, _12, _13, _14, _15,   \
		_16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37,  \
		_38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59,  \
		_60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81,  \
		_82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95, _96, _97, _98, _99, _100, _101, _102,    \
		_103, _104, _105, _106, _107, _108, _109, _110, _111, _112, _113, _114, _115, _116, _117, _118, _119, _120,    \
		_121, _122, _123, _124, fn,  ...) \
		fn

	#define MZ_FOR_EACH(fn, ...)                                                                                      \
		MZ_FOR_EACH_FORCE_UNROLL(MZ_FOR_EACH_IMPL_SELECT(__VA_ARGS__, MZ_FOR_EACH_IMPL_124, MZ_FOR_EACH_IMPL_123,  \
		MZ_FOR_EACH_IMPL_122, MZ_FOR_EACH_IMPL_121, MZ_FOR_EACH_IMPL_120, MZ_FOR_EACH_IMPL_119,                    \
		MZ_FOR_EACH_IMPL_118, MZ_FOR_EACH_IMPL_117, MZ_FOR_EACH_IMPL_116, MZ_FOR_EACH_IMPL_115,                    \
		MZ_FOR_EACH_IMPL_114, MZ_FOR_EACH_IMPL_113, MZ_FOR_EACH_IMPL_112, MZ_FOR_EACH_IMPL_111,                    \
		MZ_FOR_EACH_IMPL_110, MZ_FOR_EACH_IMPL_109, MZ_FOR_EACH_IMPL_108, MZ_FOR_EACH_IMPL_107,                    \
		MZ_FOR_EACH_IMPL_106, MZ_FOR_EACH_IMPL_105, MZ_FOR_EACH_IMPL_104, MZ_FOR_EACH_IMPL_103,                    \
		MZ_FOR_EACH_IMPL_102, MZ_FOR_EACH_IMPL_101, MZ_FOR_EACH_IMPL_100, MZ_FOR_EACH_IMPL_99,                     \
		MZ_FOR_EACH_IMPL_98, MZ_FOR_EACH_IMPL_97, MZ_FOR_EACH_IMPL_96, MZ_FOR_EACH_IMPL_95, MZ_FOR_EACH_IMPL_94,  \
		MZ_FOR_EACH_IMPL_93, MZ_FOR_EACH_IMPL_92, MZ_FOR_EACH_IMPL_91, MZ_FOR_EACH_IMPL_90, MZ_FOR_EACH_IMPL_89,  \
		MZ_FOR_EACH_IMPL_88, MZ_FOR_EACH_IMPL_87, MZ_FOR_EACH_IMPL_86, MZ_FOR_EACH_IMPL_85, MZ_FOR_EACH_IMPL_84,  \
		MZ_FOR_EACH_IMPL_83, MZ_FOR_EACH_IMPL_82, MZ_FOR_EACH_IMPL_81, MZ_FOR_EACH_IMPL_80, MZ_FOR_EACH_IMPL_79,  \
		MZ_FOR_EACH_IMPL_78, MZ_FOR_EACH_IMPL_77, MZ_FOR_EACH_IMPL_76, MZ_FOR_EACH_IMPL_75, MZ_FOR_EACH_IMPL_74,  \
		MZ_FOR_EACH_IMPL_73, MZ_FOR_EACH_IMPL_72, MZ_FOR_EACH_IMPL_71, MZ_FOR_EACH_IMPL_70, MZ_FOR_EACH_IMPL_69,  \
		MZ_FOR_EACH_IMPL_68, MZ_FOR_EACH_IMPL_67, MZ_FOR_EACH_IMPL_66, MZ_FOR_EACH_IMPL_65, MZ_FOR_EACH_IMPL_64,  \
		MZ_FOR_EACH_IMPL_63, MZ_FOR_EACH_IMPL_62, MZ_FOR_EACH_IMPL_61, MZ_FOR_EACH_IMPL_60, MZ_FOR_EACH_IMPL_59,  \
		MZ_FOR_EACH_IMPL_58, MZ_FOR_EACH_IMPL_57, MZ_FOR_EACH_IMPL_56, MZ_FOR_EACH_IMPL_55, MZ_FOR_EACH_IMPL_54,  \
		MZ_FOR_EACH_IMPL_53, MZ_FOR_EACH_IMPL_52, MZ_FOR_EACH_IMPL_51, MZ_FOR_EACH_IMPL_50, MZ_FOR_EACH_IMPL_49,  \
		MZ_FOR_EACH_IMPL_48, MZ_FOR_EACH_IMPL_47, MZ_FOR_EACH_IMPL_46, MZ_FOR_EACH_IMPL_45, MZ_FOR_EACH_IMPL_44,  \
		MZ_FOR_EACH_IMPL_43, MZ_FOR_EACH_IMPL_42, MZ_FOR_EACH_IMPL_41, MZ_FOR_EACH_IMPL_40, MZ_FOR_EACH_IMPL_39,  \
		MZ_FOR_EACH_IMPL_38, MZ_FOR_EACH_IMPL_37, MZ_FOR_EACH_IMPL_36, MZ_FOR_EACH_IMPL_35, MZ_FOR_EACH_IMPL_34,  \
		MZ_FOR_EACH_IMPL_33, MZ_FOR_EACH_IMPL_32, MZ_FOR_EACH_IMPL_31, MZ_FOR_EACH_IMPL_30, MZ_FOR_EACH_IMPL_29,  \
		MZ_FOR_EACH_IMPL_28, MZ_FOR_EACH_IMPL_27, MZ_FOR_EACH_IMPL_26, MZ_FOR_EACH_IMPL_25, MZ_FOR_EACH_IMPL_24,  \
		MZ_FOR_EACH_IMPL_23, MZ_FOR_EACH_IMPL_22, MZ_FOR_EACH_IMPL_21, MZ_FOR_EACH_IMPL_20, MZ_FOR_EACH_IMPL_19,  \
		MZ_FOR_EACH_IMPL_18, MZ_FOR_EACH_IMPL_17, MZ_FOR_EACH_IMPL_16, MZ_FOR_EACH_IMPL_15, MZ_FOR_EACH_IMPL_14,  \
		MZ_FOR_EACH_IMPL_13, MZ_FOR_EACH_IMPL_12, MZ_FOR_EACH_IMPL_11, MZ_FOR_EACH_IMPL_10, MZ_FOR_EACH_IMPL_9,   \
		MZ_FOR_EACH_IMPL_8, MZ_FOR_EACH_IMPL_7, MZ_FOR_EACH_IMPL_6, MZ_FOR_EACH_IMPL_5, MZ_FOR_EACH_IMPL_4,       \
		MZ_FOR_EACH_IMPL_3, MZ_FOR_EACH_IMPL_2, MZ_FOR_EACH_IMPL_1, MZ_FOR_EACH_IMPL_0)(fn, __VA_ARGS__))

	// clang-format on

#endif // MZ_FOR_EACH

#ifndef MZ_COUNT_VA_ARGS

	// clang-format off

	#define MZ_COUNT_VA_ARGS_IMPL(_1_, _2_, _3_, _4_, _5_, _6_, _7_, _8_, _9_, _10_, _11_, _12_, _13_, _14_, _15_,    \
		_16_, _17_, _18_, _19_, _20_, _21_, _22_, _23_, _24_, _25_, _26_, _27_, _28_, _29_, _30_, _31_, _32_, _33_,    \
		_34_, _35_, _36_, _37_, _38_, _39_, _40_, _41_, _42_, _43_, _44_, _45_, _46_, _47_, _48_, _49_, _50_, _51_,    \
		_52_, _53_, _54_, _55_, _56_, _57_, _58_, _59_, _60_, _61_, _62_, _63_, _64_, _65_, _66_, _67_, _68_, _69_,    \
		_70_, _71_, _72_, _73_, _74_, _75_, _76_, _77_, _78_, _79_, _80_, _81_, _82_, _83_, _84_, _85_, _86_, _87_,    \
		_88_, _89_, _90_, _91_, _92_, _93_, _94_, _95_, _96_, _97_, _98_, _99_, _100_, _101_, _102_, _103_, _104_,     \
		_105_, _106_, _107_, _108_, _109_, _110_, _111_, _112_, _113_, _114_, _115_, _116_, _117_, _118_, _119_, _120_,\
		_121_, _122_, _123_, _124_, count, ...) count

	#define MZ_COUNT_VA_ARGS_IMPL_EXPANDER(args) MZ_COUNT_VA_ARGS_IMPL args

	#define MZ_COUNT_VA_ARGS(...) MZ_COUNT_VA_ARGS_IMPL_EXPANDER((__VA_ARGS__, 124, 123, 122, 121, 120, 119, 118,    \
		117, 116, 115, 114, 113, 112, 111, 110, 109, 108, 107, 106, 105, 104, 103, 102, 101, 100, 99, 98, 97, 96, 95,  \
		94, 93, 92, 91, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67,\
		66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39,\
		38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11,\
		10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0))

	// clang-format on

#endif // MZ_COUNT_VA_ARGS

#ifndef MZ_COMMA
	#define MZ_COMMA ,
#endif

#ifndef MZ_DECLSPEC
	#if MZ_MSVC_LIKE
		#define MZ_DECLSPEC(...) __declspec(__VA_ARGS__)
	#else
		#define MZ_DECLSPEC(...)
	#endif
#endif

#ifndef MZ_EMPTY_BASES
	#if MZ_MSVC_LIKE
		#define MZ_EMPTY_BASES MZ_DECLSPEC(empty_bases)
	#else
		#define MZ_EMPTY_BASES
	#endif
#endif

#ifndef MZ_TYPE_LIST_PAGE_SIZE
	#undef MZ_TYPE_LIST_PAGE_SIZE
	#define MZ_TYPE_LIST_PAGE_SIZE 32
#endif
#if MZ_TYPE_LIST_PAGE_SIZE < 8
	#undef MZ_TYPE_LIST_PAGE_SIZE
	#define MZ_TYPE_LIST_PAGE_SIZE 8
#endif
#if MZ_TYPE_LIST_PAGE_SIZE > 64
	#undef MZ_TYPE_LIST_PAGE_SIZE
	#define MZ_TYPE_LIST_PAGE_SIZE 64
#endif
#if !(MZ_TYPE_LIST_PAGE_SIZE == 8 || MZ_TYPE_LIST_PAGE_SIZE == 16 || MZ_TYPE_LIST_PAGE_SIZE == 32                      \
	  || MZ_TYPE_LIST_PAGE_SIZE == 48 || MZ_TYPE_LIST_PAGE_SIZE == 64)
	#error MZ_TYPE_LIST_PAGE_SIZE must be 8, 16, 32, 48 or 64.
#endif

#ifndef MZ_TYPE_LIST_HAS_JUMBO_PAGES
	#define MZ_TYPE_LIST_HAS_JUMBO_PAGES 1
#endif

#if MZ_HAS_BUILTIN(__type_pack_element) || MZ_CLANG >= 6 // older clang implemented __has_builtin poorly
	#define MZ_HAS_TYPE_PACK_ELEMENT 1
#else
	#define MZ_HAS_TYPE_PACK_ELEMENT 0
#endif

#ifndef MZ_HAS_INTEGER_SEQ
	#if MZ_CLANG || MZ_MSVC_LIKE
		#define MZ_HAS_INTEGER_SEQ 1
	#else
		#define MZ_HAS_INTEGER_SEQ 0
	#endif
#endif
#if !MZ_HAS_INTEGER_SEQ
	#include <utility>
#endif

#define MZ_MAKE_INDEXED_TPARAM(N) MZ_COMMA typename MZ_CONCAT(T, N)
#define MZ_MAKE_INDEXED_TARG(N)	  MZ_COMMA MZ_CONCAT(T, N)
#define MZ_0_TO_7				  0, 1, 2, 3, 4, 5, 6, 7
#define MZ_0_TO_15				  MZ_0_TO_7, 8, 9, 10, 11, 12, 13, 14, 15
#define MZ_0_TO_31				  MZ_0_TO_15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31
#define MZ_0_TO_47				  MZ_0_TO_31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47
#define MZ_0_TO_63				  MZ_0_TO_47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63

#include <cstddef>

namespace mz
{
	using std::size_t;

#if 1

	#ifndef MZ_HAS_SNIPPET_META_ALWAYS_FALSE
		#define MZ_HAS_SNIPPET_META_ALWAYS_FALSE

	template <typename... T>
	inline constexpr bool always_false = false;

	#endif // MZ_HAS_SNIPPET_META_ALWAYS_FALSE

	#ifndef MZ_HAS_SNIPPET_META_INDEX_OF_TYPE
		#define MZ_HAS_SNIPPET_META_INDEX_OF_TYPE

	namespace detail
	{
		template <typename T, size_t I, typename... Types>
		struct index_of_type_
		{
			static_assert(always_false<T>, "type not found in list");
		};

		template <typename T, size_t I, typename... Types>
		struct index_of_type_<T, I, T, Types...>
		{
			static constexpr size_t value = I;
		};

		template <typename T, size_t I, typename U, typename... Types>
		struct index_of_type_<T, I, U, Types...> : index_of_type_<T, I + 1, Types...>
		{};
	}
	template <typename T, typename U, typename... V>
	inline constexpr size_t index_of_type = detail::index_of_type_<T, 0, U, V...>::value;

	#endif // MZ_HAS_SNIPPET_META_INDEX_OF_TYPE

#endif

	template <typename... T>
	struct type_list;

#ifndef MZ_HAS_SNIPPET_TYPE_LIST
	#define MZ_HAS_SNIPPET_TYPE_LIST

	namespace detail
	{
		inline constexpr size_t type_list_page_size = MZ_TYPE_LIST_PAGE_SIZE;
	#if MZ_TYPE_LIST_HAS_JUMBO_PAGES
		inline constexpr size_t type_list_jumbo_page_size = 128;
	#else
		inline constexpr size_t type_list_jumbo_page_size = static_cast<size_t>(-1);
	#endif

	#if MZ_HAS_INTEGER_SEQ
		template <typename T, T... Vals>
		struct integer_sequence
		{};
		template <size_t... Vals>
		using index_sequence = integer_sequence<size_t, Vals...>;
		template <size_t Size>
		using make_index_sequence = __make_integer_seq<integer_sequence, size_t, Size>;
	#else
		using std::index_sequence;
		using std::make_index_sequence;
	#endif

		enum class type_list_selector_spec : int
		{
			first,
			skip_pages,
			low_index,
			compiler_builtin
		};

		// clang-format off

		// selector
		template <typename List, size_t N, type_list_selector_spec Specialization = (
			MZ_HAS_TYPE_PACK_ELEMENT      ? type_list_selector_spec::compiler_builtin : (
			N == 0                         ? type_list_selector_spec::first : (
			N >= type_list_jumbo_page_size ? type_list_selector_spec::skip_pages : (
			N >= type_list_page_size       ? type_list_selector_spec::skip_pages : (
			                               type_list_selector_spec::low_index
		)))))>
		struct type_list_selector_;

			// clang-format on

	#if MZ_HAS_TYPE_PACK_ELEMENT

		// selector - selecting elements using a compiler builtin
		template <typename... T, size_t N>
		struct type_list_selector_<type_list<T...>, N, type_list_selector_spec::compiler_builtin>
		{
			using type = __type_pack_element<N, T...>;
		};

	#else

		// selector - first element
		template <typename T0, typename... T, size_t N>
		struct type_list_selector_<type_list<T0, T...>, N, type_list_selector_spec::first>
		{
			using type = T0;
		};

		// selector - skip pages
		template <typename List, size_t N>
		struct type_list_selector_<List, N, type_list_selector_spec::skip_pages>
		{
			// invokes the skip_pages specialization of the slicer
			using type = typename List::template slice<N, 1>::template select<0>;
		};

		// selector - low-index elements
		#define MAKE_SELECTOR_1(N, N0, ...)                                                                            \
			template <typename T##N0 MZ_FOR_EACH(MZ_MAKE_INDEXED_TPARAM, __VA_ARGS__), typename... T>                  \
			struct type_list_selector_<type_list<T##N0 MZ_FOR_EACH(MZ_MAKE_INDEXED_TARG, __VA_ARGS__), T...>,          \
												 N,                                                                    \
												 type_list_selector_spec::low_index>                                   \
			{                                                                                                          \
				using type = T##N;                                                                                     \
			}
		#define MAKE_SELECTOR(...) MZ_FOR_EACH_FORCE_UNROLL(MAKE_SELECTOR_1(__VA_ARGS__))

		template <typename T0, typename T1, typename... T>
		struct type_list_selector_<type_list<T0, T1, T...>, 1, type_list_selector_spec::low_index>
		{
			using type = T1;
		};

		MAKE_SELECTOR(2, 0, 1, 2);
		MAKE_SELECTOR(3, 0, 1, 2, 3);
		MAKE_SELECTOR(4, 0, 1, 2, 3, 4);
		MAKE_SELECTOR(5, 0, 1, 2, 3, 4, 5);
		MAKE_SELECTOR(6, 0, 1, 2, 3, 4, 5, 6);
		MAKE_SELECTOR(7, MZ_0_TO_7);
		#if MZ_TYPE_LIST_PAGE_SIZE >= 16
		MAKE_SELECTOR(8, MZ_0_TO_7, 8);
		MAKE_SELECTOR(9, MZ_0_TO_7, 8, 9);
		MAKE_SELECTOR(10, MZ_0_TO_7, 8, 9, 10);
		MAKE_SELECTOR(11, MZ_0_TO_7, 8, 9, 10, 11);
		MAKE_SELECTOR(12, MZ_0_TO_7, 8, 9, 10, 11, 12);
		MAKE_SELECTOR(13, MZ_0_TO_7, 8, 9, 10, 11, 12, 13);
		MAKE_SELECTOR(14, MZ_0_TO_7, 8, 9, 10, 11, 12, 13, 14);
		MAKE_SELECTOR(15, MZ_0_TO_15);
		#endif
		#if MZ_TYPE_LIST_PAGE_SIZE >= 32
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
		#endif
		#if MZ_TYPE_LIST_PAGE_SIZE >= 48
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
		#endif
		#if MZ_TYPE_LIST_PAGE_SIZE >= 64
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
		#endif

		#undef MAKE_SELECTOR_1
		#undef MAKE_SELECTOR

	#endif // !MZ_HAS_TYPE_PACK_ELEMENT

		enum class type_list_slicer_spec : int
		{
			empty,
			first,
			all,
			skip_first_N,
			skip_jumbo_pages,
			skip_pages,
			prefix,
			single_low_index,
			single_compiler_builtin,
			arbitrary_range
		};

		// clang-format off

		// slicer
		template <typename List, size_t Start, size_t Length, type_list_slicer_spec Specialization = (
			!List::length || !Length || Start >= List::length ? type_list_slicer_spec::empty : (
			Length == 1 && MZ_HAS_TYPE_PACK_ELEMENT          ? type_list_slicer_spec::single_compiler_builtin : (
			Start == 0 && Length == 1                         ? type_list_slicer_spec::first : (
			Start == 0 && List::length == Length              ? type_list_slicer_spec::all : (
			Start >= type_list_jumbo_page_size                ? type_list_slicer_spec::skip_jumbo_pages : (
			MZ_HAS_TYPE_PACK_ELEMENT                         ? type_list_slicer_spec::arbitrary_range : (
			Start >= type_list_page_size                      ? type_list_slicer_spec::skip_pages : (
			Length == 1                                       ? type_list_slicer_spec::single_low_index : (
			Start == 0 && Length <= type_list_page_size       ? type_list_slicer_spec::prefix : (
			Start > 0                                         ? type_list_slicer_spec::skip_first_N : (
			                                                    type_list_slicer_spec::arbitrary_range
		)))))))))))>
		struct type_list_slicer_;

		// clang-format on

		// slicer - empty range
		template <typename List, size_t Start, size_t Length>
		struct type_list_slicer_<List, Start, Length, type_list_slicer_spec::empty>
		{
			using type = type_list<>;
		};

		// slicer - arbitrary ranges
		template <typename, size_t, typename>
		struct type_list_index_sequence_slicer_;
		template <typename List, size_t Start, size_t... Seq>
		struct type_list_index_sequence_slicer_<List, Start, index_sequence<Seq...>>
		{
			using type = type_list<typename List::template select<Start + Seq>...>;
		};
		template <typename List, size_t Start, size_t Length>
		struct MZ_EMPTY_BASES type_list_slicer_<List, Start, Length, type_list_slicer_spec::arbitrary_range>
			: type_list_index_sequence_slicer_<List, Start, make_index_sequence<Length>>
		{};

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

			// slicer - skip jumbo pages (multiples of type_list_jumbo_page_size)
	#if MZ_TYPE_LIST_HAS_JUMBO_PAGES
		// clang-format off
		template <
			typename T0,   typename T1,   typename T2,   typename T3,   typename T4,   typename T5,   typename T6,   typename T7,
			typename T8,   typename T9,   typename T10,  typename T11,  typename T12,  typename T13,  typename T14,  typename T15,
			typename T16,  typename T17,  typename T18,  typename T19,  typename T20,  typename T21,  typename T22,  typename T23,
			typename T24,  typename T25,  typename T26,  typename T27,  typename T28,  typename T29,  typename T30,  typename T31,
			typename T32,  typename T33,  typename T34,  typename T35,  typename T36,  typename T37,  typename T38,  typename T39,
			typename T40,  typename T41,  typename T42,  typename T43,  typename T44,  typename T45,  typename T46,  typename T47,
			typename T48,  typename T49,  typename T50,  typename T51,  typename T52,  typename T53,  typename T54,  typename T55,
			typename T56,  typename T57,  typename T58,  typename T59,  typename T60,  typename T61,  typename T62,  typename T63,
			typename T64,  typename T65,  typename T66,  typename T67,  typename T68,  typename T69,  typename T70,  typename T71,
			typename T72,  typename T73,  typename T74,  typename T75,  typename T76,  typename T77,  typename T78,  typename T79,
			typename T80,  typename T81,  typename T82,  typename T83,  typename T84,  typename T85,  typename T86,  typename T87,
			typename T88,  typename T89,  typename T90,  typename T91,  typename T92,  typename T93,  typename T94,  typename T95,
			typename T96,  typename T97,  typename T98,  typename T99,  typename T100, typename T101, typename T102, typename T103,
			typename T104, typename T105, typename T106, typename T107, typename T108, typename T109, typename T110, typename T111,
			typename T112, typename T113, typename T114, typename T115, typename T116, typename T117, typename T118, typename T119,
			typename T120, typename T121, typename T122, typename T123, typename T124, typename T125, typename T126, typename T127,
			typename... T, size_t Start, size_t Length
		>
		struct type_list_slicer_<
			type_list<
				T0,   T1,   T2,   T3,   T4,   T5,   T6,   T7,
				T8,   T9,   T10,  T11,  T12,  T13,  T14,  T15,
				T16,  T17,  T18,  T19,  T20,  T21,  T22,  T23,
				T24,  T25,  T26,  T27,  T28,  T29,  T30,  T31,
				T32,  T33,  T34,  T35,  T36,  T37,  T38,  T39,
				T40,  T41,  T42,  T43,  T44,  T45,  T46,  T47,
				T48,  T49,  T50,  T51,  T52,  T53,  T54,  T55,
				T56,  T57,  T58,  T59,  T60,  T61,  T62,  T63,
				T64,  T65,  T66,  T67,  T68,  T69,  T70,  T71,
				T72,  T73,  T74,  T75,  T76,  T77,  T78,  T79,
				T80,  T81,  T82,  T83,  T84,  T85,  T86,  T87,
				T88,  T89,  T90,  T91,  T92,  T93,  T94,  T95,
				T96,  T97,  T98,  T99,  T100, T101, T102, T103,
				T104, T105, T106, T107, T108, T109, T110, T111,
				T112, T113, T114, T115, T116, T117, T118, T119,
				T120, T121, T122, T123, T124, T125, T126, T127,
				T...
			>,
			Start, Length, type_list_slicer_spec::skip_jumbo_pages
		>
		{
			using type = typename type_list<T...>::template slice<Start - type_list_jumbo_page_size, Length>;
		};
				// clang-format on
	#endif // MZ_TYPE_LIST_HAS_JUMBO_PAGES

	#if MZ_HAS_TYPE_PACK_ELEMENT

		// slicer - selecting arbitrary single element spans using a compiler builtin
		template <typename... T, size_t Start>
		struct type_list_slicer_<type_list<T...>, Start, 1, type_list_slicer_spec::single_compiler_builtin>
		{
			using type = type_list<__type_pack_element<Start, T...>>;
		};

	#else

		// slicer - skip pages (multiples of type_list_page_size)
		template <typename List, size_t Start, size_t Length>
		struct type_list_slicer_<List, Start, Length, type_list_slicer_spec::skip_pages>
		{
			// repeatedly invokes the skip_first_N specialization until Start is < type_list_page_size
			using type = typename type_list_slicer_<List,
													type_list_page_size,
													List::length - type_list_page_size,
													type_list_slicer_spec::skip_first_N>::type //
				::template slice<Start - type_list_page_size, Length>;
		};

		// slicer - low-index elements
		#define MAKE_SINGLE_ELEMENT_SLICER_1(N, N0, ...)                                                               \
			template <typename T##N0 MZ_FOR_EACH(MZ_MAKE_INDEXED_TPARAM, __VA_ARGS__), typename... T>                  \
			struct type_list_slicer_<type_list<T##N0 MZ_FOR_EACH(MZ_MAKE_INDEXED_TARG, __VA_ARGS__), T...>,            \
											   N,                                                                      \
											   1,                                                                      \
											   type_list_slicer_spec::single_low_index>                                \
			{                                                                                                          \
				using type = type_list<T##N>;                                                                          \
			}
		#define MAKE_SINGLE_ELEMENT_SLICER(...) MZ_FOR_EACH_FORCE_UNROLL(MAKE_SINGLE_ELEMENT_SLICER_1(__VA_ARGS__))

		template <typename T0, typename T1, typename... T>
		struct type_list_slicer_<type_list<T0, T1, T...>, 1, 1, type_list_slicer_spec::single_low_index>
		{
			using type = type_list<T1>;
		};

		MAKE_SINGLE_ELEMENT_SLICER(2, 0, 1, 2);
		MAKE_SINGLE_ELEMENT_SLICER(3, 0, 1, 2, 3);
		MAKE_SINGLE_ELEMENT_SLICER(4, 0, 1, 2, 3, 4);
		MAKE_SINGLE_ELEMENT_SLICER(5, 0, 1, 2, 3, 4, 5);
		MAKE_SINGLE_ELEMENT_SLICER(6, 0, 1, 2, 3, 4, 5, 6);
		MAKE_SINGLE_ELEMENT_SLICER(7, MZ_0_TO_7);
		#if MZ_TYPE_LIST_PAGE_SIZE >= 16
		MAKE_SINGLE_ELEMENT_SLICER(8, MZ_0_TO_7, 8);
		MAKE_SINGLE_ELEMENT_SLICER(9, MZ_0_TO_7, 8, 9);
		MAKE_SINGLE_ELEMENT_SLICER(10, MZ_0_TO_7, 8, 9, 10);
		MAKE_SINGLE_ELEMENT_SLICER(11, MZ_0_TO_7, 8, 9, 10, 11);
		MAKE_SINGLE_ELEMENT_SLICER(12, MZ_0_TO_7, 8, 9, 10, 11, 12);
		MAKE_SINGLE_ELEMENT_SLICER(13, MZ_0_TO_7, 8, 9, 10, 11, 12, 13);
		MAKE_SINGLE_ELEMENT_SLICER(14, MZ_0_TO_7, 8, 9, 10, 11, 12, 13, 14);
		MAKE_SINGLE_ELEMENT_SLICER(15, MZ_0_TO_15);
		#endif
		#if MZ_TYPE_LIST_PAGE_SIZE >= 32
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
		#endif
		#if MZ_TYPE_LIST_PAGE_SIZE >= 48
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
		#endif
		#if MZ_TYPE_LIST_PAGE_SIZE >= 64
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
		#endif

		#undef MAKE_SINGLE_ELEMENT_SLICER_1
		#undef MAKE_SINGLE_ELEMENT_SLICER

		// slicer - prefixes
		#define MAKE_PREFIX_SLICER_1(N0, ...)                                                                          \
			template <typename T##N0 MZ_FOR_EACH(MZ_MAKE_INDEXED_TPARAM, __VA_ARGS__), typename... T>                  \
			struct type_list_slicer_<type_list<T##N0 MZ_FOR_EACH(MZ_MAKE_INDEXED_TARG, __VA_ARGS__), T...>,            \
											   0,                                                                      \
											   MZ_COUNT_VA_ARGS(__VA_ARGS__) + 1,                                      \
											   type_list_slicer_spec::prefix>                                          \
			{                                                                                                          \
				using type = type_list<T0 MZ_FOR_EACH(MZ_MAKE_INDEXED_TARG, __VA_ARGS__)>;                             \
			}
		#define MAKE_PREFIX_SLICER(...) MZ_FOR_EACH_FORCE_UNROLL(MAKE_PREFIX_SLICER_1(__VA_ARGS__))

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
		MAKE_PREFIX_SLICER(MZ_0_TO_7);
		#if MZ_TYPE_LIST_PAGE_SIZE >= 16
		MAKE_PREFIX_SLICER(MZ_0_TO_7, 8);
		MAKE_PREFIX_SLICER(MZ_0_TO_7, 8, 9);
		MAKE_PREFIX_SLICER(MZ_0_TO_7, 8, 9, 10);
		MAKE_PREFIX_SLICER(MZ_0_TO_7, 8, 9, 10, 11);
		MAKE_PREFIX_SLICER(MZ_0_TO_7, 8, 9, 10, 11, 12);
		MAKE_PREFIX_SLICER(MZ_0_TO_7, 8, 9, 10, 11, 12, 13);
		MAKE_PREFIX_SLICER(MZ_0_TO_7, 8, 9, 10, 11, 12, 13, 14);
		MAKE_PREFIX_SLICER(MZ_0_TO_15);
		#endif
		#if MZ_TYPE_LIST_PAGE_SIZE >= 32
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
		#endif
		#if MZ_TYPE_LIST_PAGE_SIZE >= 48
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
		#endif
		#if MZ_TYPE_LIST_PAGE_SIZE >= 64
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
		#endif

		#undef MAKE_PREFIX_SLICER_1
		#undef MAKE_PREFIX_SLICER

		// slicer - skip first N
		#define MAKE_SKIP_N_SLICER_1(N, N0, N1, ...)                                                                   \
			template <                                                                                                 \
				typename T##N0,                                                                                        \
				typename T##N1 MZ_FOR_EACH(MZ_MAKE_INDEXED_TPARAM, __VA_ARGS__), typename... T, size_t Length>         \
				struct type_list_slicer_<type_list<T##N0, T##N1 MZ_FOR_EACH(MZ_MAKE_INDEXED_TARG, __VA_ARGS__), T...>, \
												   N,                                                                  \
												   Length,                                                             \
												   type_list_slicer_spec::skip_first_N>                                \
			{                                                                                                          \
				using type = typename type_list<T##N, T...>::template slice<0, Length>;                                \
			}
		#define MAKE_SKIP_N_SLICER(...) MZ_FOR_EACH_FORCE_UNROLL(MAKE_SKIP_N_SLICER_1(__VA_ARGS__))

		template <typename T0, typename T1, typename... T, size_t Length>
		struct type_list_slicer_<type_list<T0, T1, T...>, 1, Length, type_list_slicer_spec::skip_first_N>
		{
			using type = typename type_list<T1, T...>::template slice<0, Length>;
		};

		template <typename T0, typename T1, typename T2, typename... T, size_t Length>
		struct type_list_slicer_<type_list<T0, T1, T2, T...>, 2, Length, type_list_slicer_spec::skip_first_N>
		{
			using type = typename type_list<T2, T...>::template slice<0, Length>;
		};

		MAKE_SKIP_N_SLICER(3, 0, 1, 2, 3);
		MAKE_SKIP_N_SLICER(4, 0, 1, 2, 3, 4);
		MAKE_SKIP_N_SLICER(5, 0, 1, 2, 3, 4, 5);
		MAKE_SKIP_N_SLICER(6, 0, 1, 2, 3, 4, 5, 6);
		MAKE_SKIP_N_SLICER(7, MZ_0_TO_7);
		MAKE_SKIP_N_SLICER(8, MZ_0_TO_7, 8);
		#if MZ_TYPE_LIST_PAGE_SIZE >= 16
		MAKE_SKIP_N_SLICER(9, MZ_0_TO_7, 8, 9);
		MAKE_SKIP_N_SLICER(10, MZ_0_TO_7, 8, 9, 10);
		MAKE_SKIP_N_SLICER(11, MZ_0_TO_7, 8, 9, 10, 11);
		MAKE_SKIP_N_SLICER(12, MZ_0_TO_7, 8, 9, 10, 11, 12);
		MAKE_SKIP_N_SLICER(13, MZ_0_TO_7, 8, 9, 10, 11, 12, 13);
		MAKE_SKIP_N_SLICER(14, MZ_0_TO_7, 8, 9, 10, 11, 12, 13, 14);
		MAKE_SKIP_N_SLICER(15, MZ_0_TO_15);
		MAKE_SKIP_N_SLICER(16, MZ_0_TO_15, 16);
		#endif
		#if MZ_TYPE_LIST_PAGE_SIZE >= 32
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
		#endif
		#if MZ_TYPE_LIST_PAGE_SIZE >= 48
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
		#endif
		#if MZ_TYPE_LIST_PAGE_SIZE >= 64
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
		#endif

		#undef MAKE_SKIP_N_SLICER_1
		#undef MAKE_SKIP_N_SLICER

	#endif // !MZ_HAS_TYPE_PACK_ELEMENT

		// clang-format on

		// concatenate

		template <typename...>
		struct type_list_concatenate_;

		template <>
		struct type_list_concatenate_<>
		{
			using types = type_list<>;
		};

		template <typename... T>
		struct type_list_concatenate_<type_list<T...>>
		{
			using types = type_list<T...>;
		};

		template <typename... T, typename... U>
		struct type_list_concatenate_<type_list<T...>, type_list<U...>>
		{
			using types = type_list<T..., U...>;
		};

		template <typename... T, typename... U, typename... V>
		struct type_list_concatenate_<type_list<T...>, type_list<U...>, V...>
		{
			using types = typename type_list_concatenate_<type_list<T..., U...>, V...>::types;
		};

		// flatten

		template <typename T>
		struct type_list_flatten_
		{
			using types = type_list<T>;
		};

		template <>
		struct type_list_flatten_<type_list<>>
		{
			using types = type_list<>;
		};

		template <typename... T>
		struct type_list_flatten_<type_list<T...>>
		{
			using types = typename type_list_concatenate_<typename type_list_flatten_<T>::types...>::types;
		};

		template <typename... T>
		using type_list_flatten = typename type_list_concatenate_<typename type_list_flatten_<T>::types...>::types;

		// remove

		template <typename R, typename T>
		struct type_list_remove_
		{
			using types = type_list<T>;
		};

		template <typename R>
		struct type_list_remove_<R, R>
		{
			using types = type_list<>;
		};

		template <typename R, typename... T>
		using type_list_remove = typename type_list_concatenate_<typename type_list_remove_<R, T>::types...>::types;
	} // ::detail

	template <>
	struct type_list<>
	{
		static constexpr size_t length = 0;

		// these are clearly nonsense but needed for templates to not cause substitution failure

		template <size_t Index>
		using select = typename detail::type_list_selector_<type_list<>, Index>::type;

		template <size_t Start, size_t Length = (length - Start)>
		using slice = type_list<>;

		template <typename U>
		static constexpr size_t index_of = static_cast<size_t>(-1);

		using flatten = type_list<>;

		template <typename U>
		using remove = type_list<>;

		template <typename... U>
		using append = type_list<U...>;
	};

	template <typename T>
	struct type_list<T>
	{
		static constexpr size_t length = 1;

		using first = T;
		using type	= first;

	#if MZ_HAS_TYPE_PACK_ELEMENT
		template <size_t Index>
		using select = __type_pack_element<Index, T>;
	#else
		template <size_t Index>
		using select = typename detail::type_list_selector_<type_list<T>, Index>::type;
	#endif

		template <size_t Start, size_t Length = (length - Start)>
		using slice = typename detail::type_list_slicer_<type_list<T>, Start, Length>::type;

		template <typename U>
		static constexpr size_t index_of = index_of_type<U, T>;

		using flatten = detail::type_list_flatten<T>;

		template <typename U>
		using remove = detail::type_list_remove<U, T>;

		template <typename... U>
		using append = type_list<T, U...>;
	};

	template <typename T0, typename... T>
	struct type_list<T0, T...>
	{
		static constexpr size_t length = 1 + sizeof...(T);

		using first = T0;

	#if MZ_HAS_TYPE_PACK_ELEMENT
		template <size_t Index>
		using select = __type_pack_element<Index, T0, T...>;
	#else
		template <size_t Index>
		using select = typename detail::type_list_selector_<type_list<T0, T...>, Index>::type;
	#endif

		template <size_t Start, size_t Length = (length - Start)>
		using slice = typename detail::type_list_slicer_<type_list<T0, T...>, Start, Length>::type;

		template <typename U>
		static constexpr size_t index_of = index_of_type<U, T0, T...>;

		using flatten = detail::type_list_flatten<T0, T...>;

		template <typename U>
		using remove = detail::type_list_remove<U, T0, T...>;

		template <typename... U>
		using append = type_list<T0, T..., U...>;
	};

	template <typename T>
	using type_tag = type_list<T>;

#endif // MZ_HAS_SNIPPET_TYPE_LIST

}

#undef MZ_TYPE_LIST_PAGE_SIZE
#undef MZ_TYPE_LIST_HAS_JUMBO_PAGES
#undef MZ_HAS_TYPE_PACK_ELEMENT
#undef MZ_HAS_INTEGER_SEQ
#undef MZ_MAKE_INDEXED_TPARAM
#undef MZ_MAKE_INDEXED_TARG
#undef MZ_0_TO_7
#undef MZ_0_TO_15
#undef MZ_0_TO_31
#undef MZ_0_TO_47
#undef MZ_0_TO_63

#endif // MZ_TYPE_LIST_HPP
