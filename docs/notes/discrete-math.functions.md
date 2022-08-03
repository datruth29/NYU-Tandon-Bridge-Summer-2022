---
id: kr76phy9fo24pt22mn5cf9j
title: Functions
desc: ''
updated: 1659500358842
created: 1659298625441
---

A function $f$ that maps elements of a set $X$ to elements of a set $Y$, is a subset of $X \times Y$ such that for every $x \isin X$, there is _exactly one_ $y \isin Y$ for which $(x, y) \isin f$.

$f: X \to Y$ is the notation to express the fact that $f$ is a function from $X$ to $Y$. The set $X$ is called the __domain__ of $f$, and the set $Y$ is the __target__ of $f$. An alternate word for target that is sometimes used is __co-domain__. The fact that $f$ maps $x$ to $y$ (or $(x, y) \isin f$) can also be denoted as $f(x)=y$.

If $f$ maps an element of the domain to zero elements or more than one element of the target, then $f$ is not __well-defined__.

Alternatively, a function with a finite domain can be expressed as an __arrow diagram__. An __arrow diagram__ for a function $f$ shows elements of the domain $X$ as listed on the left and the elements of the target $Y$ listed on the right.

For a function $f: X \to Y$, an element $y$ is in the __range__ of $f$ if and only if there is an $x \isin X$ such that $(x, y) \isin f$. This is expressed in the set notation:

$$$
\text{Range of } f = \{y: (x, y) \isin f, \text{ for some } x \isin X \}
$$$

## Strings

The domain and target for functions can also be a set a string.

Suppose there's a function $f: \{0, 1\}^3 \to \{0, 1\}^4$. This function maps an input of a 3-bit string and outputs it as a 4-bit string.

Suppose the definition of $f$ is $x \isin \{0, 1\}^3, f(x) = x0$. Then for any 3-bit string $x$, the output of $f$ on input $x$ is obtained by adding a 0 to the end of $x$. For example, $f(011) = 0110$.

## Function Equality

Two functions, $f$ and $g$, are equal if $f$ and $g$ have the same domain and target, and $f(x) = g(x)$ for every element $x$ in the domain. This is donated with the notation $f = g$.