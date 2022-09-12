---
id: 5y5b1712b5pukq0z8xgxlug
title: Combinations
desc: ''
updated: 1662922263753
created: 1662911592739
---

__Combinations__ are all possible ways a group of elements can be selected, without regard for the order they are chosen in. This is in contrast to [[discrete-math.combinatorics.permutations]], which does take into account the order elements are selected.

## Example

Suppose you have a set of letters {A, B, C}. How many ways are there to combine those letters to make a word (please note that by word, we are just talking about a sequence of characters)?

- A
    - AB
        - ABC (1)
    - AC
        - ACB (2)
- B
    - BC
        - BCA (3)
    - BA
        - BAC (4)
-C
    - CA
        - CAB (5)
    - CB
        - CBA (6)
    
We can see that there are 6 different ways that a word can be constructed.
