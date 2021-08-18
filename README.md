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