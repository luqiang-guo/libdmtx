g++ test.cpp -o test    \
-I../                   \
-L../.libs              \
-ldmtx                  \
-Wl,-rpath=../.libs