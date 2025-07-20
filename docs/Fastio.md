---
title: fastio
documentation_of: //cpstl/other/Fastio.hpp
---

## fastio
高速入出力．`pair` や `tuple`, `vector` も直接入出力が可能 (出力は空白区切りとなる)．また，128bit 整数の入出力にも対応．
`cpstd::print` での出力では改行が入るが，`cpstd::_print` を使えば一応改行なしで出力できる．ただし，`cpstd::print` と違い可変長引数に対応していないため注意．
