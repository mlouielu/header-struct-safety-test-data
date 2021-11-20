Header/Struct Safety Test Data
==============================

## How to Use

* Build

```
$ make build
gcc -Wall gen_data.c -o gen_data
```

* Generate Data

```
$ make gen-data
./gen_data
$ ls
... test.bin ...
```

* Python Convert (by `struct`)

```
$ make py-convert
python decode_binary.py test.bin
(10, 20, 30, 0, 0.1, 0.5, 0.7, 143399, 356331540)
(30, 40, 50, 0, 0.1, 0.5, 0.7, 143399, 356335599)
(60, 70, 80, 0, 0.1, 0.5, 0.7, 143399, 356335703)
```

* Clean (remove `.bin` and `gen_data`)

```
$ make clean
rm gen_data test.bin
```
