HOME=/Users/malt
GTEST_DIR=${HOME}/usr/src/gtest-1.7.0

test:tests.cpp ../pqs
	g++ tests.cpp -o tests -I${GTEST_DIR}/include -L${GTEST_DIR}/build -lgtest ${GTEST_DIR}/build/libgtest_main.a

clean:
	rm ./tests