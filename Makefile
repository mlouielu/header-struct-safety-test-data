build:
	gcc -Wall gen_data.c -o gen_data

gen-data:
	./gen_data

py-convert:
	python decode_binary.py test.bin

clean:
	rm gen_data test.bin
