# `mz::type_list` [![MIT license](docs/images/badge-license-MIT.svg)](./LICENSE) [![C++17](docs/images/badge-c++17.svg)][cpp_compilers] [![Sponsor](docs/images/badge-sponsor.svg)][sponsor] [![Gitter](docs/images/badge-gitter.svg)][gitter]

A variadic 'type list' for performing operations on lists of types in metaprogramming contexts. Optimized to be much more compiler-friendly than `std::tuple`.

See [Compilation speed humps: std::tuple](https://marzer.github.io/md_blog_2021_05_31_compilation_speed_humps_std_tuple.html) for a write-up on the sorts of optimizations applied herein.

Requires C++17.

<br>

## Synopsis

```cpp
namespace mz
{
	template <typename... T>
	struct type_list
	{
		// get the number of types in the list:
		static constexpr size_t length = sizeof...(T);

		// index of the first appearance of the specified type:
		template <typename U>
		static constexpr size_t index_of = /* ... */;

		// get a specific type:
		template <size_t Index>
		using select = /* T...[Index] */;

		// convenience alias for select<0>:
		using first = select<0>;

		// convenience alias for select<0> when length == 1:
		using type = select<0>;

		// get a 'slice' (sublist):
		template <size_t Start, size_t Length = (length - Start)>
		using slice = type_list</* ... */>;

		// adding on to the beginning of the list:
		template <typename... U>
		using prepend = type_list<U..., T...>;

		// adding on to the end of the list:
		template <typename... U>
		using append = type_list<T..., U...>;

		// recursively flatten child sublists:
		using flatten = type_list</* ... */>;

		// remove all occurrences of the specified type:
		template <typename U>
		using remove = type_list</* ... */>;
	};

	// alias for a single-element list:
	template <typename T>
	using type_tag = type_list<T>;
}
```

<br>

## Usage

The library is a single header so the easiest way to use it is to drop [type_list.hpp] somewhere in your project.

Alternatively you can add `include` to your include paths then `#include <mz/type_list.hpp>`

There is also support for use as a `meson.build` subproject.

<br>

## Benchmarks

Single-threaded compilation of the example application on my Ryzen 3950X:

|                | Clang 12     | GCC 10      | MSVC 19.29  |
| -------------- | ------------ | ----------- | ----------- |
| std::tuple     | 6.448s       | 3.185s      | 7.965s      |
| mz::type_list  | 0.303s       | 0.407s      | 0.830s      |
| speedup factor | 21.2x faster | 7.8x faster | 9.6x faster |

<br>

## License

MIT. See [LICENSE](LICENSE).

<br>

## Contributing

There are three ways you can contribute:

1. Reporting bug or making feature requests [here](https://github.com/marzer/type_list/issues/new)
2. Opening a pull request (⚠&#xFE0F; _caveat - see below_)
3. Becoming a [sponsor] ❤&#xFE0F;

### Pull requests

`type_list.hpp` is programmatically extracted from a much larger project so I won't accept pull requests made for this repository directly; if you wish to contribute a bugfix or a feature, please find the type_list implementation [in this project](https://github.com/marzer/muu) and propose your changes there instead. I will then propagate them to this satellite library when they are merged.

[type_list.hpp]: include/mz/type_list.hpp
[license]: ./LICENSE
[cpp_compilers]: https://en.cppreference.com/w/cpp/compiler_support
[gitter]: https://gitter.im/marzer/community
[sponsor]: https://github.com/sponsors/marzer
