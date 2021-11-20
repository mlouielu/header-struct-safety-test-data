import sys
import struct


def main(filename):
    with open(filename, "rb") as f:
        while True:
            b = f.read(56)
            if not b:
                break
            print(struct.unpack("iiiidddqq", b))


if __name__ == "__main__":
    main(sys.argv[1])
