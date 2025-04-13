FROM ubuntu:22.04

RUN apt-get update && \
    apt-get install -y g++ && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY src/radix_sort.cpp .
COPY src/vhod.txt .

RUN g++ radix_sort.cpp -o radix_sort -std=c++11

ENTRYPOINT ["./radix_sort", "0", "vhod.txt"]
