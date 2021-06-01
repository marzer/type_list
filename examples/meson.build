
compiler = meson.get_compiler('cpp')
is_clang = compiler.get_id() == 'clang'

example_args = []
if is_clang
	clang_major = '@0@'.format(compiler.version()).split('.')[0].strip().to_int()
	if clang_major >= 9
		example_args += [ '-ftime-trace' ]
	endif
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
