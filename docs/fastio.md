---
title: Fast I/O
documentation_of: //cpstl/other/fastio.hpp
---

## 概要
高速入出力．`pair` や `tuple`, `vector` も直接入出力が可能 (出力は空白区切りとなる)．また，128bit 整数の入出力にも対応．
`cpstd::print` での出力では改行が入るが，`cpstd::fastio::_print` を使えば一応改行なしで出力できる．ただし，`cpstd::print` と違い可変長引数に対応していないため注意．

## 使い方
- `template<typename H, typename... T> void input(H &desth, T &... destt)`: 各引数に入力．
- `template<typename H, typename... T> void print(H &&tgh, T &&... tgt)`: 各引数を空白区切りで出力し改行．
- `void flush()`: 標準出力を flush する．interactive 問題などで使用する．
