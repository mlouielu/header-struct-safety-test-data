Header/Struct Safety Test Data
==============================

## Example Struct Layout

```
struct velocity {
  double x;
  double y;
  double z;
};

struct foobar {
  int32_t posx;
  int32_t posy;
  int32_t posz;

  struct velocity vel;

  struct timespec curr_time;
};
```

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

* pahole

```
$ make pahole
pahole -E -M -C foobar gen_data
struct foobar {
	/* typedef int32_t -> __int32_t */ int                        posx;              /*     0     4 */
	/* typedef int32_t -> __int32_t */ int                        posy;              /*     4     4 */
	/* typedef int32_t -> __int32_t */ int                        posz;              /*     8     4 */

	/* XXX 4 bytes hole, try to pack */

	struct velocity {
		double             x;                                                    /*    16     8 */
		double             y;                                                    /*    24     8 */
		double             z;                                                    /*    32     8 */
	} vel; /*    16    24 */
	struct timespec {
		/* typedef __time_t */ long int           tv_sec;                        /*    40     8 */
		/* typedef __syscall_slong_t */ long int           tv_nsec;              /*    48     8 */
	} curr_time; /*    40    16 */

	/* size: 56, cachelines: 1, members: 5 */
	/* sum members: 52, holes: 1, sum holes: 4 */
	/* last cacheline: 56 bytes */
};
```

* Clean (remove `.bin` and `gen_data`)

```
$ make clean
rm gen_data test.bin
```
