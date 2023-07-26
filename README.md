tf::string
===

A header-only set of C++11 helper functions for `std::string`, aiming for readability more than performance.


### Why?

`std::string` doesn't easily provide basic stuff such as `.split(c)`, `.startswith(s)` and others. Some useful functions
are available on `std::string_view`, but if your project doesn't use C++20 then it's not usable. Also, there are not many
extra functions there.

The Boost library has many algorithms implemented, but then you either need to depend on Boost (which is a big
dependency) or use their BCP libray (https://www.boost.org/doc/libs/1_82_0/tools/bcp/doc/html/index.html), which is
yet another dependency to add. If you just want to use some string functions that can be a lot.

The Qt library has `QString`, which has many good methods, but Qt is also a huge dependency.


### Examples

```c++
std::cout << " - ";
for (auto&& substr : tf::string{"a,b,c,d"}.split(',')) {
    std::cout << substr << " - ";
}
// - a - b - c - d - 

tf::string{"hello my friends"}.startswith("hello"); // true
tf::string{"hello my friends"}.startswith("my"); // false

std::cout << tf::string{"hello my friends"}.endswith("friends"); // true
std::cout << tf::string{"hello my friends"}.endswith("ends"); // true
std::cout << tf::string{"hello my friends"}.endswith(""); // false
std::cout << tf::string{"hello my friends"}.endswith("my"); // false

tf::string{"hi"}.contains("h"); // true
tf::string{"hi"}.contains("b"); // false
```