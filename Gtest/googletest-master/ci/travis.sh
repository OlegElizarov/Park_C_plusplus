#!/usr/bin/env sh
set -evx

. Gtest/googletest-master/ci/get-nprocessors.sh

# if possible, ask for the precise number of processors,
# otherwise take 2 processors as reasonable default; see
# https://docs.travis-ci.com/user/speeding-up-the-build/#Makefile-optimization
if [ -x /usr/bin/getconf ]; then
    NPROCESSORS=$(/usr/bin/getconf _NPROCESSORS_ONLN)
else
    NPROCESSORS=2
fi
# as of 2017-09-04 Travis CI reports 32 processors, but GCC build
# crashes if parallelized too much (maybe memory consumption problem),
# so limit to 4 processors for the time being.
if [ $NPROCESSORS -gt 4 ] ; then
	echo "$0:Note: Limiting processors to use by make from $NPROCESSORS to 4."
	NPROCESSORS=4
fi
# Tell make to use the processors. No preceding '-' required.
MAKEFLAGS="j${NPROCESSORS}"
export MAKEFLAGS

env | sort

# Set default values to OFF for these variables if not specified.
: "${NO_EXCEPTION:=OFF}"
: "${NO_RTTI:=OFF}"
: "${COMPILER_IS_GNUCXX:=OFF}"

mkdir build || true
cd build
cmake -Dgtest_build_samples=ON \
      -Dgtest_build_tests=ON \
      -Dgmock_build_tests=ON \
      -Dcxx_no_exception=$NO_EXCEPTION \
      -Dcxx_no_rtti=$NO_RTTI \
      -DCMAKE_COMPILER_IS_GNUCXX=$COMPILER_IS_GNUCXX \
      -DCMAKE_CXX_FLAGS=$CXX_FLAGS \
      -DCMAKE_BUILD_TYPE=$BUILD_TYPE \
      ..
#cp Gtest/googletest-master/googletest/include/gtest/gtest.h .
#cp Gtest/googletest-master/googletest/include/gtest/gtest.h ./Gtest

make
cd /home/travis/build/OlegElizarov/Park_C_plusplus/
cppcheck --enable=all --check-config --std=c99 --suppress=missingIncludeSystem IZN1.c
cd /home/travis/build/OlegElizarov/Park_C_plusplus/build
sudo make Gtest_run
sudo make Gtest_runn
valgrind --leak-check=full -q ./Gtest_run
