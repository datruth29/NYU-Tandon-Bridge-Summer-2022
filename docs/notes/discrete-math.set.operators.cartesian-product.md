---
id: o3npv25kpasr4u2k21jro19
title: Cartesian Product
desc: ''
updated: 1658760040227
created: 1658760036628
---

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