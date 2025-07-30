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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: cpstl/math/StaticModint.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_point_get\"\
    \n\n#include <bits/stdc++.h>\n#include \"cpstl/math/StaticModint.hpp\"\n#include\
    \ \"cpstl/other/Fastio.hpp\"\n#include \"cpstl/ds/DualSegtree.hpp\"\n\nusing mint\
    \ = cpstd::Modint998244353;\nusing F = std::pair<mint, mint>;\nF composition(F\
    \ g, F f) { return {f.first * g.first, f.second * g.first + g.second}; }\nF id()\
    \ { return {1, 0}; }\n\nint main() {\n\tint N, Q;\n\tcpstd::input(N, Q);\n\tstd::vector<mint>\
    \ A(N);\n\tcpstd::input(A);\n\tcpstd::DualSegtree<F, composition, id> sg(N);\n\
    \tint t, l, r, p;\n\tmint b, c;\n\twhile (Q--) {\n\t\tcpstd::input(t);\n\t\tif\
    \ (t == 0) {\n\t\t\tcpstd::input(l, r, b, c);\n\t\t\tsg.apply(l, r, {b, c});\n\
    \t\t}\n\t\telse {\n\t\t\tcpstd::input(p);\n\t\t\tF act = sg[p];\n\t\t\tcpstd::print(act.first\
    \ * A[p] + act.second);\n\t\t}\n\t}\n\treturn 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: verify/ds/lc-Range-Affine-Point-Get-DualSegtree.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/ds/lc-Range-Affine-Point-Get-DualSegtree.test.cpp
layout: document
redirect_from:
- /verify/verify/ds/lc-Range-Affine-Point-Get-DualSegtree.test.cpp
- /verify/verify/ds/lc-Range-Affine-Point-Get-DualSegtree.test.cpp.html
title: verify/ds/lc-Range-Affine-Point-Get-DualSegtree.test.cpp
---
