#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <vector>

const double MIN_TEMPERATURE = -99;
const double MAX_TEMPERATURE = 99;
const int MAX_STATIONS = 10000;
const int MAX_STATION_NAME_LEN = 100;

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<> temperature_dist(MIN_TEMPERATURE, MAX_TEMPERATURE);
std::uniform_int_distribution<> station_count_dist(1, MAX_STATIONS);
std::uniform_int_distribution<> station_name_len_dist(1, MAX_STATION_NAME_LEN);

const std::string ALPHABET = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz !@#$%^&*(){}|\\`~'\"";
std::uniform_int_distribution<> alphabet_idx_dist(0, ALPHABET.size() - 1);

std::string random_string(int len) {
    std::string s(len, 0);
    for (int i = 0; i < len; ++i) {
        s[i] = ALPHABET[alphabet_idx_dist(gen)];
    }
    return s;
}

double random_temperature() {
    return temperature_dist(gen);
}

int main(int argc, char *argv[]) {
    int n_stations = station_count_dist(gen);
    std::vector<std::string> stations;
    stations.reserve(n_stations);
    for (int i = 0; i < n_stations; ++i) {
        stations.emplace_back(random_string(station_name_len_dist(gen)));
    }
    std::uniform_int_distribution<> station_idx_dist(0, n_stations - 1);

    int n = 1000000000;
    if (argc > 1) {
        n = std::stoi(argv[1]);
    }
    std::ofstream out("measurements.txt");

    for (int i = 0; i < n; ++i) {
        out << stations[station_idx_dist(gen)] << ";" << random_temperature() << "\n";
    }
}