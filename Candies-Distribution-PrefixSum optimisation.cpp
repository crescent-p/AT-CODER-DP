{\rtf1\ansi\deff0\nouicompat{\fonttbl{\f0\fnil Cascadia Mono;}{\f1\fnil\fcharset0 Calibri;}}
{\colortbl ;\red128\green128\blue128;\red0\green0\blue0;\red163\green21\blue21;\red0\green0\blue255;\red111\green0\blue138;\red0\green128\blue128;\red43\green145\blue175;\red0\green128\blue0;}
{\*\generator Riched20 10.0.22621}\viewkind4\uc1 
\pard\sa200\sl276\slmult1\cf1\f0\fs19\lang9 #include\cf2  \cf3 <iostream>\cf2\par
\cf1 #include\cf2  \cf3 <vector>\cf2\par
\cf1 #include\cf2  \cf3 <algorithm>\cf2\par
\par
\cf4 using\cf2  \cf4 namespace\cf2  std;\par
\par
\cf1 #define\cf2  \cf5 getunique\cf2 (v) \cf4 do\cf2  \{ sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end()); \} \cf4 while\cf2 (0)\par
\par
\cf1 #define\cf2  \cf5 rep\cf2 (i, a, n) \cf4 for\cf2  (\cf4 int\cf2  i = a; i < n; i++)\par
\cf1 #define\cf2  \cf5 per\cf2 (i, a, n) \cf4 for\cf2  (\cf4 int\cf2  i = n - 1; i >= a; i--)\par
\cf1 #define\cf2  \cf5 pyes\cf2   cout \cf6 <<\cf2  \cf3 "YES"\cf2  \cf6 <<\cf2  endl;\par
\cf1 #define\cf2  \cf5 pno\cf2   cout \cf6 <<\cf2  \cf3 "NO"\cf2  \cf6 <<\cf2  endl;\par
\par
\cf1 #define\cf2  \cf5 input\cf2 (k, arr) \cf7 ll\cf2  k;cin>>k;\cf7 vector\cf2 <\cf7 ll\cf2 > arr(k);\cf5 rep\cf2 (i, 0, k) cin>>arr[i];\par
\cf1 #define\cf2  \cf5 output\cf2 (arr, k) \cf5 rep\cf2 (i, 0, k) cout<<arr[i]<<\cf3 " "\cf2 ;cout\cf6 <<\cf2 endl;\par
\cf1 #define\cf2  \cf5 endl\cf2  \cf3 '\\n'\cf2\par
\cf1 #define\cf2  \cf5 sumall\cf2 (arr, k) \cf7 ll\cf2  sum = 0; \cf5 rep\cf2 (i, 0, k) sum+=arr[i];\par
\cf1 #define\cf2  \cf5 fast\cf2   \cf7 ios_base\cf2 ::sync_with_stdio(0);cin.tie(0);cout.tie(0);\par
\par
\cf1 #define\cf2  \cf5 s\cf2  second\par
\cf1 #define\cf2  \cf5 f\cf2  first\par
\par
\cf1 #define\cf2  \cf5 MOD\cf2  (1000000000 + 7)\par
\par
\cf4 using\cf2  \cf7 ll\cf2  = \cf4 long\cf2  \cf4 long\cf2 ;\par
\par
\par
\cf4 void\cf2  solve() \{\par
    \cf7 ll\cf2  k, n;\par
    cin \cf6 >>\cf2  n; cin \cf6 >>\cf2  k;\par
    \cf7 vector\cf2 <\cf7 ll\cf2 > arr(n + 1);\par
    \cf5 rep\cf2 (i, 0, n) cin \cf6 >>\cf2  arr\cf6 [\cf2 i\cf6 ]\cf2 ;\par
    \cf7 vector\cf2 <\cf7 ll\cf2 > dp(k + 1);\par
\par
    \cf7 vector\cf2 <\cf7 ll\cf2 > prefixsum(k + 1);\par
\par
    \cf8 //dp[i] = no of ways to reach i in n steps.\cf2\par
    \cf8 // This is a space optimised dp\cf2\par
    \cf8 // so instead of keeping dp[n][i] we only keep dp[curr][i] and dp[prev][i]\cf2\par
    \cf8 // since answer depends on prev state only\cf2\par
    \cf8 // For initialization we can keep first a-i-th places 1. since there is exactly one way \cf2\par
    \cf8 // to do this. (Having a single 0 or a single 1 or a single 2......upto a-i-th value)\cf2\par
    \cf8 //if we have 3 in first slot then dp[0] = 1 dp[1] = 1... dp[3] = 1\cf2\par
    \cf8 //\cf2\par
    \cf8 //Idea here -> fill ndp(nextdp) with values from dp(curr dp).\cf2\par
    \cf8 //nth ndp[0....k] = ndp[0....k] + dp[0....k - 0.....a-i-th value].\cf2\par
    \cf8 //\cf2\par
    \cf4 for\cf2  (\cf4 int\cf2  i = 0; i <= arr\cf6 [\cf2 0\cf6 ]\cf2 ; i++) dp\cf6 [\cf2 i\cf6 ]\cf2  = 1;\par
    \cf4 for\cf2  (\cf4 int\cf2  i = 1; i < n; i++) \{\par
        \cf7 vector\cf2 <\cf7 ll\cf2 > ndp(k + 1, 0);\par
        prefixsum\cf6 [\cf2 0\cf6 ]\cf2  = dp\cf6 [\cf2 0\cf6 ]\cf2 ;\par
        \cf4 for\cf2  (\cf4 int\cf2  i = 1; i <= k; i++) \{\par
            prefixsum\cf6 [\cf2 i\cf6 ]\cf2  = prefixsum\cf6 [\cf2 i - 1\cf6 ]\cf2  + dp\cf6 [\cf2 i\cf6 ]\cf2 ;\par
        \}\par
        \cf4 for\cf2  (\cf4 int\cf2  tot = 0; tot <= k; tot++) \{    \par
            \par
            \par
            \cf4 if\cf2  (max(0LL, tot - arr\cf6 [\cf2 i\cf6 ]\cf2 ) == 0) \{\par
                ndp\cf6 [\cf2 tot\cf6 ]\cf2  += prefixsum\cf6 [\cf2 tot\cf6 ]\cf2 ;\par
                ndp\cf6 [\cf2 tot\cf6 ]\cf2  %= \cf5 MOD\cf2 ;\par
            \}\par
            \cf4 else\cf2  \{\par
                ndp\cf6 [\cf2 tot\cf6 ]\cf2  += prefixsum\cf6 [\cf2 tot\cf6 ]\cf2  - prefixsum\cf6 [\cf2 tot - arr\cf6 [\cf2 i\cf6 ]\cf2  - 1\cf6 ]\cf2 ;\par
                ndp\cf6 [\cf2 tot\cf6 ]\cf2  %= \cf5 MOD\cf2 ;\par
            \}\par
            \cf8 //replace with prefix sum.\cf2\par
            \cf8 /*for (int j = 0; j <= arr[i]; j++) \{\cf2\par
\cf8                 if (tot >= j) \{\cf2\par
\cf8                     ndp[tot] += dp[tot - j];\cf2\par
\cf8                 \}\cf2\par
\cf8             \}*/\cf2\par
        \}\par
        dp \cf6 =\cf2  ndp;\par
    \}\par
    cout \cf6 <<\cf2  dp\cf6 [\cf2 k\cf6 ]\cf2  \cf6 <<\cf2  \cf5 endl\cf2 ;\par
\}\par
\par
\cf4 int\cf2  main() \{\par
    \cf5 fast\cf2 ;\par
    \cf7 ll\cf2  t;\par
    \cf8 //cin >> t;\cf2\par
    t = 1;\par
    \cf4 while\cf2  (t--) \{\par
        solve();\par
    \}\par
\par
    \cf4 return\cf2  0;\par
\}\par
\cf0\f1\fs22\par
}
 