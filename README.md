#LZ77 Compression & Decompression in C++
This project implements the LZ77 compression algorithm in C++. It provides functionality to compress strings by replacing repeated sequences of characters with references, and to decompress such compressed data back to the original string.

About LZ77
LZ77 is a lossless data compression algorithm that replaces repeated sequences with pointers (offset and length) to previous occurrences within a sliding window. It is widely used in compression formats like ZIP and PNG.

Features
Compress strings using a sliding window with configurable size.

Decompress compressed data back to the original string.

Command-line interface to choose between compression and decompression.

Outputs compressed data as tuples (offset, length, next_char).

Usage
Compile the project using your preferred C++ compiler.

Run the executable.

Choose mode:

c to compress a string.

d to decompress compressed data.

For compression, specify the window size (e.g., 20).

Enter the string or compressed data as prompted.

Example
Compression
Choose mode: (c)ompress or (d)ecompress? c
Enter window size (e.g., 20): 10
Enter text to compress: abcabcabc

Compressed output (offset, length, next_char):
(0, 0, a)
(0, 0, b)
(0, 0, c)
(3, 3, c)
(3, 3, )

Decompression
Choose mode: (c)ompress or (d)ecompress? d
Enter compressed data (format: (offset,length,next_char) ...):
(0,0,a) (0,0,b) (0,0,c) (3,3,c) (3,3, )

Decompressed string:
abcabcabc
