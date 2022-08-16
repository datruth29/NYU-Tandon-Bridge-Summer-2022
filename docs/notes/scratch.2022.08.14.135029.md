---
id: fb2n27led2mgfejqnxy8f3x
title: '135029'
desc: ''
updated: 1660507160408
created: 1660499430871
---

## Summary of Notes for Week 7

## Chapter 4

### 4.1 Top-Down Design

- Discussion about how programs are thought of as subpart, specifically into functions. The first point is on __fundamental design principals__.

- First discussion is on __top-down design__ or whats commonly known as __procedural programming__. This is where programs are designed in a linear matter from top to bottom, and is broken up with subparts. These subparts can be referedd to as __procedures__ or __functions__. Please note that words such as procedures and functions largely mean the same thing. In cases where they are different, it's usually in the context of the a specific programming language or paradigm, but for the most part just treat them to be the same.

- Using functions lets you divide a program into smaller parts, which has the advantage of being easier to test functions and allowing multiple people to work on separate parts of a function to make constructing programs in teams faster.

### 4.2 Predefined Functions

#### Using functions

- Predefined functions are functions that have already been created within a C++ library.

Examples of a predefined function are:

```cpp
sqrt();
to_string();
pow();
```

- Expressions which use functions such as sqrt(9.0) are called __function calls__. The value placed inside the functions are called __arguments__ or __parameters__. Functions can have more than one argument that can be placed in it.

- Please note that like the words procedures and functions, arguments and parameters generally mean the same thing. You might find them to have slightly different meanings in your programming travels, but for the most part they refer to the same thing; the values that are placed in a function.

- Arguments in a function can be constants (9.0, 'a', 1, etc), variables, or expressions.

Examples of uses like below:

```cpp
int main()
{
    int a = 1;
    int b = 2;

    sqrt(9.0) \\ Call using constant
    sqrt(a) \\ Call using variable
    sqrt(a + 9.0) \\ Call using an expression
    pow(a, b) \\ Call using more than one argument
}
```

- Functions can return values. For example, `sqrt(9)` will return the value 3.0.  Because of this, functions can be used as part of expressions such as below

- Note that c++ an only return one value in a function. However we will find ways around this limitation later one when going over concepts like __structs__ and __classess__.

```cpp
sales = 9.0;
bonus = sqrt(sales) / 10;
```

- Function calls can also be used in cout like `cout << pow(1, 2) << endl;`

#### Directives and Headers

```cpp
#include <iostream>
#include <cmath>
```

- Lines such as `#include` are called __directives__ in c++.
- The name inside of the arrow markers (<`iostream`>) is actually the name of a file. These files are called __header files__.
- The `#include` directive is tells the __preprocessor__ to include the contents of the specified file at the point where the directive is called.
- Header files contains information such as declarations of functions, variables, classes, etc, that you wish to include in your program.
- For instance, `iostream` and `cmath` are header files that we've been using to make use of functions such as `cout` and `pow()`.
- Declarations that are made in for standard library headers (like `iostream`, `cmath`, etc) usually are part of the `std` namespaces.
- We can make use of those declarations after we call their respective headers with the `using` directive.

 __Authors Note:__ The book is wrong with regards to stating that `using namespace std;` being mandatory to use declarations. For instance:

```cpp
#include <iostream>

int main()
{
    std::cout << "Hello World!" << std:endl;
    return 0;
}
```

The above works by placing the namespace `std` before using the function from the standard library with the prefix `std::`.

The reason why you may want to make your calls this way is to avoid name classes with functions from the standard library, such as if you want to make your own `pow` or `sqrt` function.

You can learn a bit more about this and the practices of `using namespace std` via this [youtube video from Coding Beauty](https://www.youtube.com/watch?v=etQX4Mme2f4).

#### Type Casting

- In C++, we can change the data type of variable and values from their original declaration. When we do this, it is called __Type Casting__.

Lets consider the example code below:

```cpp
int total_work_hours = 63, number_of_workers = 6;
double average_weekly_hours;

average_weekly_hours = total_work_hours / number_of_workers;
```

The above program is calculating the average number of hours that is worked about workers for a week. However, if we try to calculate this, we will only get a whole number response because the division is being down on two ints. We don't want to change the data type on those variables because ints are the best way to represent them except in this case. This is a perfect example of when we would want to use __type casting__

- In C++, we can use type casting with the following function call `static_cast<type>(value)`.
- For example, if we want to change the integer value 9 to the double, we would use `static_cast<double>(9)`. The 9 will then become 9.0

Let us change our program above to include this.

```cpp
int total_work_hours = 63, number_of_workers = 6;
double average_weekly_hours;

average_weekly_hours = static_cast<double>(total_work_hours) / number_of_workers;
```

_Note:_ Remember that when performing calculations, we just need to have one value in the expression be a double to get back a double calculation, so in our case we just need to type cast one of either __total_work_hours__ or __number_of_works__.

- There's another way to type cast in C++ using the type as a function call. For instance `double(total_work_hours)` would also work as a type cast. This way of casting is called __C Style Casting_ as it was the prominent way to cast types in the C language.

- Generally, you should prefer using `static_cast` for type casting in modern C++. If you want to see some discussion on this, check out [this github discussion](https://stackoverflow.com/questions/1609163/what-is-the-difference-between-static-cast-and-c-style-casting), as well as [this discussion that has more specific](https://stackoverflow.com/questions/103512/why-use-static-castintx-instead-of-intx).

### 4.3 Programmer-Defined Functions

#### Function Definitions

