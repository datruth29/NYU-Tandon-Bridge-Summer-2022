---
id: ep5i5hlw6ecf0iq8i8tsu99
title: '115328'
desc: ''
updated: 1658719440811
created: 1658678009512
---
# Sets

A __set__ is a collection of __objects__. Objects can be represented as various types, fromm letters, to numbers, to book titles, etc. The objects in a set are called __elements__.

A set is defined by the elements in it. One way we can show a set with elements is using __roster notation__. An example of roster notation looks like this:

$A = \{1, 2, 3, 4\}$

Where the set $A$ contains the following 4 elements: 1, 2, 3, 4. It should also be notated that repeating the element does not change the set.

An __empty set__ (aka a __null set__) is a set which contains no elements and is denoted by the symbol $\emptyset$.

A __finite set__ is a set that is either empty or whose elements can be nummbered 1 through $n$ for some positive integer $n$. an __infinite set__ is a set that is not finite.

The __cardinality__ of a finite set is the number of distinct elements in a set. For instance, the following set would have a cardinality of 4.

$A = \{1, 2, 3, 4\}$

A __universal set__ is denoted by the symbol $\mathbb{U}$. A universal set would include all elements of a particular context. For example, if the context of videogame length, the universal set would be all videogames that contain a length.

Cardinality can be denoted as follows: $\vert A \vert=4$

If there are too many elements in a set, you can donate a large number elements (or an infinite amount of elements) with $...$. This should only be done the numbers in the set can show a distinct pattern. For example:

$B=\{2, 4, 6, ..., 100\}$

Would show a set of integers that are multiple of 2 up to 100.

Two sets are considered equal when they have exactly the same elements.

Common mathematical sets can have their own symbols. Here are somme common examples:


Set | Symbol | Examples
---------|----------|---------
 $\mathbb{N}$ is a set of __natural numbers__ which includes >= 0 | $\mathbb{N}$ | $0, 1, 2, 3, ...$
 $\mathbb{Z}$ is a set of all integers| \mathbb{Z}$ | $..., -2, -1, 0, 1, 2, ...$
 $\mathbb{Q}$ is a set of __rational numbers__ which includes all real numbers such that $a/b$ and a and b != 0| $\mathbb{Q}$ | $0, 1/2, 5.23, -5.1$
 $\mathbb{R}$ is the set of real numbers.| $\mathbb{R}$ | 0, 1/2, -5.3, $\pi$, $\sqrt{2}$

Superscripts are used to denote whether the set contains all positive or negative values. For instance: $\mathbb{Z}^+$ would be all set of positive integers. Conversely, $\mathbb{Z}^-$ would be all set of negative integers.

Set operations such as [[discrete-math.sets.operators.union]] and [[discrete-math.sets.operators.intersection]] can be used together to define sets. For instance, the set $A \cup ( B \cap C)$ is the union of set $A$ and the set $B \cap C$. Parenthesis are important in this case since the set $(A \cup B) \cap C$ is different forom the initial set.

Example:

$$
A = \{1, 2, 3, 4\} \\
B = \{3, 4, 5, 6\} \\
C = \{2, 3, 5, 7\} \\
B \cup C = \{2, 3, 4, 5, 6, 7\} \\
A \cap (B \cup C) = \{2, 3, 4\} \\
$$

For a long sequence of elements, special notation can be used. $i=1$ is placed below the operation and $n$ is placed above and is to be taken as the operation will be applied to all sets with integer indices i ranging from 1 through n.

$$
    \bigcup_{i=1}^{n}A_i = A_1 \cup A_2 \cup ... \cup A_n = \{x: x \isin A_i \text{ for all i such that } 1 \leq i <= n\}
$$

## Set Builder Notation

A __set builder notation__ is a set that is defined by specifying that set includes all elements in a larger set that also meets certain conditions. It looks like this

$C=\{x \isin \mathbb{Z}: 0 < x < 100 \text{ and x is prime}\}$

Which would be all prime integers between 0 and 100.

## Sets of Subsets

A set is considered a __subset__ of a set, when all elements of that set are contained in a set. The symbol for subset is $\subseteq$

If $A \subseteq B$, and there is an of B that is not an element of A such that $A \neq B$, then we would say that $A$ is a __proper subset__ of $B$. The symbol for proper subset is $\subset$.

## Set of sets

Elements of a set can be sets themselves.

Example: $A=\{{1, 2\}, \emptyset, \{1, 2, 3\}, \{1\}}$

This set has 4 elements: $\{2\}$, $\emptyset$, $\{1, 2, 3\}$, and $\{1\}$. Things to consider for this set:

- $\{1, 2\}$ is an element of the set.
- $1$ is not an element of this set. But $\{1\}$ is.

The __power set__ of a set $A$ is denoted $P(A)$, and is the set of all subsets $A$. For example, if $A=\{1, 2\}$, then

$$
P(A) = \{\emptyset, \{1\}, \{2\}, \{1, 2\}\}
$$

The __cardinality__ of a power set of n would be $2^n$. In the case of the previous set used, the cardinality would be $2^2 = 4$

## Intersections

The __intersection__ of sets $A$ and $B$, denoted by the denoted by the symbol $\cap$ and is read as _"$A$ intersect $B$"_, is the set of all elements that are elements of both $A$ and $B$.

The intersection operation can also apply to infinite sets:

$$
A = \{x \isin \mathbb{Z}: \text{ x is an integer multiple of 2}\} \\
B = \{x \isin \mathbb{Z}: \text{ x is an integer multiple of 3}\} \\
A \cap B = \{x \isin \mathbb{Z}: \text{ x is an integer multiple of 6}\} \\
$$

In a way, you can consider __interaction__ to be similar to an [[discrete-math.logic.operators.and]] operation in that the element must be in set $A$ __and__ set $B$ in order to be part of it's intersection.

## Union

The __union__ of two sets $A$ and $B$, denoted $A \cup B$ and read as "_$A$ union $B$_" is the set of all elements that are elements of A or B. 

The definition for union is similar to the inclusive or, in that an element must be either in set $A$ __or__ set $B$ to be an element in $A \cup B$.

An example of this is the following:

$$
A = \{1, 2, 3\} \\
B = \{2, 5, 8\} \\
A \cup B = \{1, 2, 3, 5, 8\} \\
$$

## Difference

The __difference__ between two sets $A$ and $B$, denoted $A - B$, is the set of elements that are in $A$ but not in $B$.

Example:

$$
A = \{a, b, c, e, f\}
B = \{d, e, f, g\}
A = \{a, b, c\}
$$

### Symmetric Difference

The difference operations is not communtative, hence it is not always the case that $A-B = B-A$. In contrast, the __symmetric difference between two sets A and B, denoted $A \oplus B$, is the set of elements that are a member of exactly one of $A$, and $B$, but not both.

Alternative definition for symmetric difference is:

$$
A \oplus B = (A - B) \cup (B - A)
$$

Example:

$$
A = \{a, b, c, e, f\}
B = \{d, e, f, g\}
A = \{a, b, c, d, g\}
$$

## Complement

The __complement__ of a set $A$, denoted $\overline{A}$, is the set of all elements in $\mathbb{U}$ that are not elements of $A$. An alternative defintion of $\overline{A}$ is $\mathbb{U} - A$.

For example, let $\mathbb{U} = \mathbb{Z}$.

$$
A = \{x \isin \mathbb{Z}: x is odd\}
$$

The complement of this set would be the set of all even integers.

## Cartesian Product

For two sets $A$ and $B$, the __Cartesian product__ of $A$ and $B$, denoted $A \times B$, is the set of all ordered pairs in which the first entry is in $A$ and the second entry is in $B$. That is:

$$
A \times B = \{(a, b): a \in A and b \in B\}
$$

An __ordered pair__ of items, written as $(x, y)$. The first entry of the ordered pair $(x, y)$ is $x$ and the second entry is $y$. The order of an ordered pair are important, unlike a set. This is denoted by the parenthesis $()$. For example, $(x, y) \neq (y, x)$, whereas $\{x, y\} = \{y, x\}$.

An ordered list of three items is called an __ordered triple__ and is denoted $(x, y, z)$. For $n \geq 4$, an ordered listt of n items is called an __ordered n-tuple__ (or just __n-tuple__ for short).

The Cartesian Product for $n$ sets contains n-tuples. For example:

$$
A_1 \times A_2 \times A_3 \times ... \times A_n = \{(a_1, a_2, ..., a_n): a_i \in A_i \text{ for all i such that } 1 \leq i \leq n\}
$$

The Cartesian Product of a set A with itself can be denoted as $A \times A$ or $A^2$. More generally:

$$
A^k = \underbrace{A \times A \times .... \times A}_{\text{k times}}
$$

### Strings

If sequence of characters is called a __string__. The set of characters used in a set of strings is called the __alphabet__ for the set of strings. The __length__ of a string is the number of characters in the string.

A __binary string__ is a string whose alphabet is $\{0, 1\}$. A __bit__ is a character in a binary string. A string of length $n$ is also called an __n-bit string__.

The __empty string__ is the unique string whose length is 0 and is usually denoted by the symbol $\lambda$.

If $s$ and $t$ are two strings, then the __concatenation__ of $s$ and $t$ (denoted $st$) is the string obtained by putting $s$ and $t$ together.