---
id: whwnja0n9sybez8hlzjqpg8
title: De Morgans Law
desc: ''
updated: 1657634195891
created: 1657504253424
---

## Nested Quantifiers

De Morgan's Law can be applied to logical statements with [[discrete-math.concepts.nested-quantifies]]. Each time the negation sign moves past a quantifier, the quantifier changes type from universal to existential or from existential to universal.

### Table for De Morgan's Law for nested quantified statements

$$
\begin{array}{|c|}
\hline
\neg \forall x \forall y P(x, y) \equiv \exists x \exists y \neg P(x, y)\\ \hline
\neg \forall x \exists y P(x, y) \equiv \exists x \forall y \neg P(x, y)\\
\hline
\neg \exists x \forall y P(x, y) \equiv \forall x \exists y \neg P(x, y)\\
\hline
\neg \exists x \exists y P(x, y) \equiv \forall x \forall y \neg P(x, y)\\
\hline
\end{array}
$$