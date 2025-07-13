#ifndef HEADER_H
#define HEADER_H

#include <string>
#include <vector>

struct LZ77Tuple {
    int offset;
    int length;
    char next_char;
};

std::vector<LZ77Tuple> compressLZ77(const std::string& input, int window_size = 20);

void printCompressed(const std::vector<LZ77Tuple>& compressed);

std::string decompressLZ77(const std::vector<LZ77Tuple>& compressed);

#endif