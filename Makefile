build:
	gcc -g -Wall gen_data.c -o gen_data

gen-data:
	./gen_data

py-convert:
	python decode_binary.py test.bin

pahole:
	pahole -E -M -C foobar gen_data

clean:
	rm -f gen_data test.bin
