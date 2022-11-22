# This file is a part of marzer/type_list and is subject to the the terms of the MIT license.
# Copyright (c) Mark Gillard <mark.gillard@outlook.com.au>
# See https://github.com/marzer/type_list/blob/master/LICENSE for the full license text.
# SPDX-License-Identifier: MIT

cpp = meson.get_compiler('cpp')

example_args = []
example_args += cpp.first_supported_argument('-ftime-trace')

example_overrides = []
example_overrides = [ 'warning_level=0' ]

executable(
	'comparsion_type_list',
	[ 'comparison_main.cpp' ],
	cpp_args : example_args + [ '-DUSE_STD_TUPLE=0' ],
	override_options: example_overrides,
	dependencies: [ type_list_dep ],
	install: false
)

executable(
	'comparsion_tuple',
	[ 'comparison_main.cpp' ],
	cpp_args : example_args + [ '-DUSE_STD_TUPLE=1' ],
	override_options: example_overrides,
	dependencies: [ type_list_dep ],
	install: false
)
