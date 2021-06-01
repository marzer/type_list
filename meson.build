project(
	'type_list',
	'cpp',
	version : '0.1.0',
	meson_version : '>=0.53.0',
	license : 'MIT',
	default_options : [ # https://mesonbuild.com/Builtin-options.html
		# core options
		'buildtype=release',
		'warning_level=3',
		'werror=true',
		'layout=flat',

		# base options
		'b_lto=false',
		'b_ndebug=if-release',

		# compiler options
		'cpp_std=c++17'
	]
)

subdir('include')
subdir('examples')
