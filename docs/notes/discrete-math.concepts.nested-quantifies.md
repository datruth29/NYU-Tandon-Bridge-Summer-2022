---
id: 431y712m9bvrt4x66hjfk7b
title: Nested Quantifies
desc: ''
updated: 1657634170813
created: 1657629259889
---

A logical expression with more than one quantifier that bind different variables is said to have __Nested Quantifiers__.

Below is an example

$$
\forall x \exists y P(x, y) \rightarrow \text{x and y are both bound}\\
\forall x P(x, y) \rightarrow \text{x is bound and y is free}\\
\exists y \exists z T(x, y, z) \rightarrow \text{y and z are bound. x is free}
$$

For __alternating nested quantifies__, the order of the quantifier matters. For instance:

$$
\forall x \exists y (x + y = 0)
$$

For the above, since the existential quantifier goes second, it can respond to the universal quantifier. Thus, it can give a value of $-x$ making the statement true. Now lets switch the order of the quantifiers:

$$
\exists y \forall x (x + y = 0)
$$

Since the existential quantifier is now going first, it must select a value without the knowledge of what the universal quantifier will pick. This means it can no longer respond with a $-x$. Since the universal can always pick a value that will make the statement false, the statement will always be false.

## De Morgan's Law 
![[discrete-math.concepts.de-morgans-law#nested-quantifiers]]
