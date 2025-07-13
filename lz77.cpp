#include "header.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 using namespace std;

std::vector<LZ77Tuple> compressLZ77(const std::string& input, int window_size) {
    std::vector<LZ77Tuple> compressed;
    int i = 0;

    while (i < input.size()) {
        int match_length = 0;
        int match_offset = 0;

        int start = std::max(0, i - window_size);
        std::string window = input.substr(start, i - start);

        for (int len = 1; len <= input.size() - i; ++len) {
            std::string substring = input.substr(i, len);
            size_t pos = window.find(substring);

            if (pos != std::string::npos) {
                match_offset = i - (start + pos);
                match_length = len;
            } else {
                break;
            }
        }

        char next_char = (i + match_length < input.size()) ? input[i + match_length] : '\0';

        if (match_length > 0) {
            compressed.push_back({match_offset, match_length, next_char});
            i += match_length + 1;
        } else {
            compressed.push_back({0, 0, input[i]});
            i += 1;
        }
    }

    return compressed;
}

void printCompressed(const std::vector<LZ77Tuple>& compressed) {
    for (const auto& t : compressed) {
        std::cout << "(" << t.offset << ", " << t.length << ", " << t.next_char << ")\n";
    }
}

std::string decompressLZ77(const std::vector<LZ77Tuple>& compressed) {
    std::string output;

    for (const auto& t : compressed) {
        if (t.offset == 0 && t.length == 0) {
            output += t.next_char;
        } else {
            int start = output.size() - t.offset;
            for (int i = 0; i < t.length; ++i) {
                output += output[start + i];
            }
            if (t.next_char != '\0') {
                output += t.next_char;
            }
        }
    }

    return output;
}

