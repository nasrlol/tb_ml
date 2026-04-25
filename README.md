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

Inserted 1 keys, root=0xffff51c278af, root->key_count=0
Inserted 2 keys, root=0xffff51c278af, root->key_count=0
Inserted 3 keys, root=0xffff51c278af, root->key_count=0
Inserted 4 keys, root=0xffff51c278af, root->key_count=0
...
Inserted 432278 keys, root=0xffff51c278af, root->key_count=0
Inserted 432279 keys, root=0xffff51c278af, root->key_count=0
Inserted 432280 keys, root=0xffff51c278af, root->key_count=0
=== BTREE DEBUG ===
Root @ 0xffff51c278af
key_count: 0
is_leaf: 1
Keys:
trained value :: 3.718282

========
[1927] header_index=7, row_index=99, payload=0xffff5ce3dca7
[1928] header_index=8, row_index=98, payload=0xffff5ce3da27
[1929] header_index=9, row_index=97, payload=0xffff5ce3d7a7
[1930] header_index=10, row_index=96, payload=0xffff5ce3d527
[1931] header_index=11, row_index=95, payload=0xffff5ce3d2a7
[1932] header_index=12, row_index=94, payload=0xffff5ce3d027
[1933] header_index=13, row_index=93, payload=0xffff5ce3cda7
[1934] header_index=14, row_index=92, payload=0xffff5ce3cb27
[1935] header_index=15, row_index=91, payload=0xffff5ce3c8a7
[1936] header_index=16, row_index=90, payload=0xffff5ce3c627
[1937] header_index=17, row_index=89, payload=0xffff5ce3c3a7
[1938] header_index=18, row_index=88, payload=0xffff5ce3c127
[1939] header_index=19, row_index=87, payload=0xffff5ce3bea7
[1940] header_index=5, row_index=102, payload=0xffff5ce3e447
[1941] header_index=6, row_index=101, payload=0xffff5ce3e1c7
[1942] header_index=7, row_index=100, payload=0xffff5ce3df47
[1943] header_index=8, row_index=99, payload=0xffff5ce3dcc7
[1944] header_index=9, row_index=98, payload=0xffff5ce3da47
[1945] header_index=10, row_index=97, payload=0xffff5ce3d7c7
[1946] header_index=11, row_index=96, payload=0xffff5ce3d547
[1947] header_index=12, row_index=95, payload=0xffff5ce3d2c7
[1948] header_index=13, row_index=94, payload=0xffff5ce3d047
[1949] header_index=14, row_index=93, payload=0xffff5ce3cdc7
[1950] header_index=15, row_index=92, payload=0xffff5ce3cb47
[1951] header_index=16, row_index=91, payload=0xffff5ce3c8c7
make: *** [Makefile:20: run] Segmentation fault (core dumped)

```


## ISSUES

children null.
rows are wrong.

