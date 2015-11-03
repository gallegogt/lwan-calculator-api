FROM buildpack-deps:jessie

MAINTAINER Yolier Galan Tasse <gallegogt@gmail.com>

LABEL Version="1.0"

RUN apt-get update
RUN apt-get install -y git cmake zlib1g-dev pkg-config libsqlite3-dev
RUN apt-get clean

WORKDIR /srv

RUN git clone https://github.com/lpereira/lwan.git

WORKDIR lwan/
RUN mkdir -p build/
RUN sed -i "s/STATIC/SHARED/g" common/CMakeLists.txt

WORKDIR build/
RUN cmake .. -DCMAKE_BUILD_TYPE=Release && make install && ldconfig

WORKDIR /srv
RUN  git clone https://github.com/gallegogt/lwan-calculator-api.git

WORKDIR lwan-calculator-api/
RUN mkdir -p build/

WORKDIR build/
RUN cmake .. -DCMAKE_BUILD_TYPE=Release && make

CMD ["./bin/calculator-server"]

EXPOSE 8888
