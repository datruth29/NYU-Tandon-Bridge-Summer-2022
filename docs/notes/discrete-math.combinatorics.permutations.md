---
id: t6qo8cy3fboqw50349725kq
title: Permutations
desc: ''
updated: 1662919848581
created: 1662911552780
---

__Permutations__ are all possible ways a group of elements can be selected, while taking into account the order in which they are selected. This is in contrast to [[discrete-math.combinatorics.combinations]], which doesn't care about the order in which the elements are selected.:w

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

## Details

Notice in the example above that the number of choices to select goes down with each selection for an element. For instance, on our first select we have 3 choices that can be made between __A, B, and C__.

Upon selecting an element (for instance, __A__) we now have to select from the 2 remaining elements, __B and C__. We do this until we have only 1 selection to make.

We can then see that to get all permutations of the letters __A, B, and C__, we have to take the total number of letters (we will call this _n_) and multiply that by _n-1_. From this we can see that we can get the total number of permutations by finding the factorial of _n_, _n!_.

## Permutations of Subsets

Suppose we have a list of __8 olympic participants__ and we have medals for the 1st, 2nd, and 3rd place finishers. If we tried to calculate this using _n!_, we would be over counting since we only count 3 of the selections.

We only want to calculate 8 * 7 * 6. We can generalize with _n!_ by factoring out the parts we don't need to calculate. Since we are only selecting 3, we can get the amount fo selections that we aren't counting by subtracting _n_ by the total number of selections.

If selections is denoted as _s_ and number of elements as _n_, the number of elements that are not being counted are _n_ - _s_. Therefore, the total number of elements we __DON'T__ want to count is _n_ - _s_. We will denote this as _r_.

Now let us solve. Since there are 8 elements and we are only selecting 3, we can say _n=8_. To factor our the elements we don't want to count, we will have to divide _8_ by _8_ - _3_. We then get the factorial for each and solve.

$$
\frac{8!}{8!-3!} = \frac{8!}{5!} = 8 * 7 * 6
$$

## Formula for Permutations

$$
\begin{equation}
P(n, r) = \frac{n!}{(n-r)!}
\end{equation}
