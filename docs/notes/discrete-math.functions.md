---
id: kr76phy9fo24pt22mn5cf9j
title: Functions
desc: ''
updated: 1660417818921
created: 1659298625441
---

A function $f$ that maps elements of a set $X$ to elements of a set $Y$, is a subset of $X \times Y$ such that for every $x \isin X$, there is _exactly one_ $y \isin Y$ for which $(x, y) \isin f$.

$f: X \to Y$ is the notation to express the fact that $f$ is a function from $X$ to $Y$. The set $X$ is called the __domain__ of $f$, and the set $Y$ is the __target__ of $f$. An alternate word for target that is sometimes used is __co-domain__. The fact that $f$ maps $x$ to $y$ (or $(x, y) \isin f$) can also be denoted as $f(x)=y$.

If $f$ maps an element of the domain to zero elements or more than one element of the target, then $f$ is not __well-defined__.

Alternatively, a function with a finite domain can be expressed as an __arrow diagram__. An __arrow diagram__ for a function $f$ shows elements of the domain $X$ as listed on the left and the elements of the target $Y$ listed on the right.

For a function $f: X \to Y$, an element $y$ is in the __range__ of $f$ if and only if there is an $x \isin X$ such that $(x, y) \isin f$. This is expressed in the set notation:

$$
\text{Range of } f = \{y: (x, y) \isin f, \text{ for some } x \isin X \}
$$

## Strings

The domain and target for functions can also be a set a string.

Suppose there's a function $f: \{0, 1\}^3 \to \{0, 1\}^4$. This function maps an input of a 3-bit string and outputs it as a 4-bit string.

Suppose the definition of $f$ is $x \isin \{0, 1\}^3, f(x) = x0$. Then for any 3-bit string $x$, the output of $f$ on input $x$ is obtained by adding a 0 to the end of $x$. For example, $f(011) = 0110$.

## Function Equality

awo functions, $f$ and $g$, are equal if $f$ and $g$ have the same domain and target, and $f(x) = g(x)$ for every element $x$ in the domain. This is donated with the notation $f = g$.

## Properties of functions

### One to One

A function $f: X \to Y$ is said to be __one-to-one__ or __injective__ when $f(x)$ maps to only one $f(y)$. Stated another way, if $x_1 \neq x_2$ implies that $f(x_1) \neq f(x_2)$. $X$ should always map to a different element of $Y$.

This also implies that is $|X| \leq |Y|$. If $|X| > |Y|$, then there will be an element of $Y$ that has to be mapped to an element of $X$ that's already mapped to an element.

### Onto 

A function $f: X \ to Y$ is said to be __onto__ or __surjective__ when all elements of $Y$ are mapped to at least one element of $X$. That is, for every $y \isin Y$, there is an $x \isin X$ suc that $f(x) = y$.

Opposite of one to one functions, onto functions imply that $|X| \geq |Y|$. This is because if there are more elements in $Y$ then $X$, then there will not be enough elements to map to all elements of $Y$.

### Bijective

A function is said to be __bijective__ (or one-to-one correspondence) when that function is both one-to-one AND onto.

If a function is bijective, then it follows that for $f: X \to Y$, $|X| = |Y|$. If the elements of either set is not equal to each other, then the sets will not be able to meet the condition for either one to one, onto, or neither, thereby making it not bijective.

## Inverse of a Function

If a function is a __bijection__, then an inverse of that function can be obtained by reversing the first and second entries of each pair of the function. The inverse of a function $f$ is denoted by $f^{-1}$, and be written as:

$$
f^{-1} = \{(y, x) : (x, y) \in f\}
$$

## Composition

The process of applying a function to another function is called __composition__.

To denote that $f: X \to Y$ and $g: Y \to Z$, for functions $f$ and $g$ we will use $g \circ f$. This will be the function $(g \circ f): X \to Z$ such that for all $x \in X, (g \circ f)(x) = g(f(x))$

Note that the the domain and target for $g \circ f$ is the target of domain of $f$ and the co-domain of $g$. 

## Identity Function

The __identity function__ always maps a set onto itself and maps every element onto itself.

The identity function of $A$, denoted $I_A: A \to A$, is defined as $I_A(a) = a$, for all $a \in A$.

If a function $f$ from $A \to B$ has an inverse, then $f$ composed with its inverse is the identity function.

$$
\begin{align*}
f(a) &= b \\
f^{-1}(b) &= a \\
(f^{-1} \circ f)(a) &= f^{-1}(f(a)) \\
f^{-1}(f(a)) &= f^{-1}(b) \\
f^{-1}(b) &= a
\end{align*}
$$