CFuncEntry.so: testlib.cpp
	g++ -o CFuncEntry.so testlib.cpp -g -shared -fpic -DEBUG -lpython2.7_d -DPy_DEBUG
clean:
	rm -fr ./CFuncEntry.so ./build
py:
	python setup.py build ; cp -f ./build/**/*.so ./
