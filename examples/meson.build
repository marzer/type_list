
is_clang = meson.get_compiler('cpp').get_id() == 'clang'

example_args = []
if is_clang
	example_args += [ '-ftime-trace' ]
endif

executable(
	'using_type_list',
	[ 'comparison_with_std_tuple.cpp' ],
	include_directories : inc,
	cpp_args : example_args
)

example_args += [ '-DUSE_STD_TUPLE=1' ]

executable(
	'using_std_tuple',
	[ 'comparison_with_std_tuple.cpp' ],
	include_directories : inc,
	cpp_args : example_args
)
