# lwan-calculator-api C/C++
lwan-calculator-api 

## Dependencies
1- [lwan Web Server](https://github.com/lpereira/lwan.git)

2- [JsonPack](https://github.com/ymglez/jsonpack.git)

### Build dependencies

1. JsonPack
```bash
~$ git clone https://github.com/ymglez/jsonpack.git
~$ cd jsonpack
~/jsonpack$ mkdir build
~jsonpack$ cd build
~jsonpack/build$ cmake .. -DCMAKE_BUILD_TYPE=Release
~jsonpack/build$ make
~jsonpack/build$ sudo make install
```

2. Lwan
```bash
~$ git clone https://github.com/lpereira/lwan.git
~$ cd lwan
~/lwan$ mkdir build
~/lwan$ cd build
~/lwan/build$ cmake .. -DCMAKE_BUILD_TYPE=Release
~/lwan/build$ sudo make install 
```

## You will need:
    cmake >= 2.8.0
    gcc >= 4.7
    
## Build
```bash
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

