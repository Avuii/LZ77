#include "header.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    char mode;
    cout << "Choose mode: (c) compress or (d) decompress?"<<endl;
    cin >> mode;
    cin.ignore();

    if (mode == 'c'&& mode=='C')
        {
        int window_size;
        cout << "Enter window size (e.g., 20): ";
        cin >> window_size;
        cin.ignore();

        string input;
        cout << "Enter text to compress: ";
        getline(cin, input);

        auto compressed = compressLZ77(input, window_size);
        cout << "\nCompressed output (offset, length, next_char):\n";
        printCompressed(compressed);
    }
    else if (mode == 'd'&& mode=='D') {
        string line;
        cout << "Enter compressed data as (offset,length,char), separated by spaces:\n";
        getline(cin, line);

        vector<LZ77Tuple> compressed;
        stringstream ss(line);
        string token;

        while (getline(ss, token, ' ')) {
            if (token.empty()) continue;
            int o, l;
            char c;

            if (sscanf(token.c_str(), "(%d,%d,%c)", &o, &l, &c) == 3) {
                compressed.push_back({o, l, c});
            } else {
                cout << "Invalid format: " << token << endl;
            }
        }

        string result = decompressLZ77(compressed);
        cout << "\nDecompressed text:\n" << result << endl;
    }
    else {
        cout << "Invalid mode. Use 'c' for compression or 'd' for decompression.\n";
    }

    return 0;
}
