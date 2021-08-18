# fan-speed

build it:

```bash
$ mkdir build && cd build
$ cmake ..
$ make
```

run tests:

```
$ cd build
$ cmake -DFAN_SPEED_BUILD_TEST=on ..
$ make
$ make test
```

you must install cctest before running tests.

```bash
$ git clone https://github.com/ccup/cctest.git
$ cd cctest
$ mkdir build && cd build
$ make 
$ sudo make install
```
