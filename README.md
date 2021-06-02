# `mz::type_list`
A variadic type list 'tag' type optimized to be more compiler-friendly than `std::tuple`.

See [Compilation speed humps: std::tuple](https://marzer.github.io/md_blog_2021_05_31_compilation_speed_humps_std_tuple.html) for a write-up on the sorts of optimizations applied herein.

Requires C++11.

<br>

## Synopsis

```cpp
namespace mz
{
	template <typename... T>
	struct type_list
	{
		static constexpr size_t length = sizeof...(T);

		using first = /* the first type in the list */;

		template <size_t Index>
		using select = /* the type at the selected index */;

		template <size_t SliceStart, size_t SliceLength = (length - SliceStart)>
		using slice = type_list</* the types in the selected slice */>;
	};
}
```

<br>

## Benchmarks
Single-threaded compilation of the example application on my Ryzen 3950X:

|                | Clang 12   | GCC 10     | MSVC 19.29 |
|--------------- |------------|------------|------------|
| std::tuple     | 6.448s       | 3.185s      |  7.965s    |
| mz::type_list  | 0.303s       | 0.407s      |  0.830s    |
| speedup factor | 21.2x faster | 7.8x faster | 9.6x faster |

<br>

## Installation

It's a single header. Drop it in your project.

<br>

## License
MIT. See [LICENSE](LICENSE).
