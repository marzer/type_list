
compiler = meson.get_compiler('cpp')
is_clang = compiler.get_id() == 'clang'

example_args = []
if is_clang
	clang_major = '@0@'.format(compiler.version()).split('.')[0].strip().to_int()
	if clang_major >= 9
		example_args += [ '-ftime-trace' ]
	endif
endif

example_overrides = [ 'warning_level=0' ]
compiler_supports_cpp20 = compiler.links(
	'''
	#include <version>
	#include <bit>

	int main()
	{
		return 0;
	}
	''',
	name : 'supports c++20',
	args : [ '-std=c++20' ],
	no_builtin_args : true
)
# if compiler_supports_cpp20
# 	example_overrides += 'cpp_std=none'
# 	example_args += '-std=c++20'
# endif

name = 'comparsion_type_list'
if get_option('use_tuple')
	name = 'comparsion_tuple'
	example_args += [ '-DUSE_STD_TUPLE=1' ]
endif

executable(
	name,
	[ 'comparison_main.cpp' ],
	include_directories : inc,
	cpp_args : example_args,
	override_options: example_overrides
)
