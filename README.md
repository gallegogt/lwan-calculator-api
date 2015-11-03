# lwan-calculator-api C/C++
lwan-calculator-api

## Dependencies
1- [lwan Web Server](https://github.com/lpereira/lwan.git)


### Build dependencies

1. Lwan
```bash
~$ git clone https://github.com/lpereira/lwan.git
~$ cd lwan
~/lwan$ mkdir build
~/lwan$ cd build
~/lwan/build$ cmake .. -DCMAKE_BUILD_TYPE=Release
~/lwan/build$ sudo make install
```

2.- Include in source json.h from lwan/techempower source and (utf8)[http://ufpr.dl.sourceforge.net/project/utfcpp/utf8cpp_2x/Release%202.3.4/utf8_v2_3_4.zip]

## You will need:
    cmake >= 2.8.0
    gcc >= 4.7


## Build
```bash
~$ git clone https://github.com/gallegogt/lwan-calculator-api.git
~$ cd lwan-calculator-api
~/lwan-calculator-api$ mkdir build
~/lwan-calculator-api/$ cd build
~/lwan-calculator-api/build$ cmake .. -DCMAKE_BUILD_TYPE=Release
~/lwan-calculator-api/build$ make
```

## Usage

### Server
```bash
~$ cd lwan-calculator-api/build/bin
~lwan-calculator-api/build/bin$ ./calculator-server
```

### Client
```bash
$ curl --data-urlencode "query={\"op\": \"*\", \"ops\": [3, 1,5,6,7,8,9]}" http://localhost:8888
```

