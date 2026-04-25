# TB_ML

An attempt at writing a machine learning library in C, using `tb_db` as the data input layer.
[tb_db](https://git.nsrddyn.com/tb_db.git/)

---

## References

- [Computerphile – Random Numbers (YouTube)](https://www.youtube.com/watch?v=OlSYfj8VZi0)
- [PCG Random – O'Neill (pcg-random.org)](https://www.pcg-random.org/)
- [Pattern Recognition and Machine Learning – Bishop (PDF)](https://www.cs.uoi.gr/~arly/courses/ml/tmp/Bishop_book.pdf)
- [Mean Squared Error – Wikipedia](https://en.wikipedia.org/wiki/Mean_squared_error)
- [Lineaire Benadering – Wikipedia (NL)](https://nl.wikipedia.org/wiki/Lineaire_benadering)
- [Partial Differential Equations – Wikipedia](https://en.wikipedia.org/wiki/Partial_differential_equation)
- [Lineair Regression](https://www.geeksforgeeks.org/machine-learning/ml-linear-regression/)


> - [ChatGPT]  used for navigating unfamiliar topics and finding relevant material
> - [Claude]  used for mathematical implementations because I suck
---

## Dependencies

- [`tb_db`](https://git.nsrddyn.com/tb_db) — custom CSV query engine / database layer

---

## Status

Work in progress.


## OUTPUT

```bash
[2038] header_index=17, row_index=100, payload=0xfffe9924e087
[2039] header_index=18, row_index=99, payload=0xfffe9924de07
[2040] header_index=19, row_index=98, payload=0xfffe9924db87
[2041] header_index=17, row_index=101, payload=0xfffe9924e327
[2042] header_index=18, row_index=100, payload=0xfffe9924e0a7
[2043] header_index=19, row_index=99, payload=0xfffe9924de27
[2044] header_index=18, row_index=101, payload=0xfffe9924e347
[2045] header_index=19, row_index=100, payload=0xfffe9924e0c7
[2046] header_index=19, row_index=101, payload=0xfffe9924e367
trained value :: 1.062144
Prediction for new house: 2202.942871
```


## ISSUES

children null.
rows are wrong.
prediction isnt taking enough parameters
