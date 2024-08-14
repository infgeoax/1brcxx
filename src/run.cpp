#include <fstream>
#include <iostream>

#include "time_me.h"

struct Stat {
    double min_value;
    double max_value;
    double sum;
    int count;
};

int main(int argc, char *argv[]) {
    long long lines = 0;
    TimeMe _([&lines](auto dur) {
        std::cout << "processed " << lines << " in " << dur.count() << " seconds.\n";
    });

    std::string filename = "measurements.txt";
    if (argc > 1) {
        filename = argv[1];
    }

    std::string rdbuf(1<<24, '\0');
    std::ifstream input;
    input.rdbuf()->pubsetbuf(rdbuf.data(), rdbuf.size());
    input.open(filename, std::ios_base::in | std::ios_base::binary);

    std::string buffer(4096, '\0');
    while (input) {
        input.read(buffer.data(), buffer.size());
        int count = input.gcount();
        lines += count;
    }
}