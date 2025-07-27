---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: cpstl/ds/segtree.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include <bits/stdc++.h>\n#include \"cpstl/other/fastio.hpp\"\n#include \"cpstl/ds/segtree.hpp\"\
    \n\nlong long op(long long a, long long b) { return a + b; }\nlong long e() {\
    \ return 0; }\n\nint main() {\n\tint N, Q;\n\tcpstd::input(N, Q);\n\tstd::vector<long\
    \ long> A(N);\n\tcpstd::input(A);\n\tcpstd::segtree<long long, op, e> sg(A);\n\
    \tint t;\n\twhile (Q--) {\n\t\tcpstd::input(t);\n\t\tif (t == 0) {\n\t\t\tint\
    \ p;\n\t\t\tlong long x;\n\t\t\tcpstd::input(p, x);\n\t\t\tsg.add(p, x);\n\t\t\
    }\n\t\telse {\n\t\t\tint l, r;\n\t\t\tcpstd::input(l, r);\n\t\t\tcpstd::print(sg.fold(l,\
    \ r));\n\t\t}\n\t}\n\treturn 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: verify/ds/lc-Point-Add-Range-Sum-segtree.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/ds/lc-Point-Add-Range-Sum-segtree.test.cpp
layout: document
redirect_from:
- /verify/verify/ds/lc-Point-Add-Range-Sum-segtree.test.cpp
- /verify/verify/ds/lc-Point-Add-Range-Sum-segtree.test.cpp.html
title: verify/ds/lc-Point-Add-Range-Sum-segtree.test.cpp
---
