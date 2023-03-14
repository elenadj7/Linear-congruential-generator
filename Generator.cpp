//
// Created by elena
//
#include "Generator.h"
#include <algorithm>

LinearCongruentialGenerator::LinearCongruentialGenerator(std::size_t number) : size(number + 1) { randomNumbers.reserve(number + 1); }

LinearCongruentialGenerator::~LinearCongruentialGenerator() { randomNumbers.erase(randomNumbers.begin(), randomNumbers.end()); size = 0; }


std::vector<Id> LinearCongruentialGenerator::read_initial_values(const std::string& name)noexcept(false) {
    if (auto file = std::ifstream(name)) {
        std::string temp_line;
        std::getline(file, temp_line);
        std::vector<Id> initial_values = parse_values(temp_line);
        file.close();
        return initial_values;
    }
    else throw std::exception(); //File couldn't be opened
}

std::vector<Id> LinearCongruentialGenerator::parse_values(const std::string& line)noexcept {
    std::vector<Id> ret;
    auto divider = line.find(',');
    ret.push_back(std::stoi(line.substr(0, divider)));
    std::string line2 = line.substr(divider + 1);
    divider = line2.find(',');
    ret.push_back(std::stoi(line2.substr(0, divider)));
    std::string line3 = line2.substr(divider + 1);
    divider = line3.find(',');
    ret.push_back(std::stoi(line3.substr(0, divider)));
    ret.push_back(std::stoi(line3.substr(divider + 1)));
    return ret;
}

std::vector<Id> LinearCongruentialGenerator::try_read_initial_values(const std::string& name)noexcept {
    try {
        std::vector<Id> ret = read_initial_values(name);
        return ret;
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void LinearCongruentialGenerator::start_generator(const std::string& path)noexcept {
    std::vector<Id> initial_values = try_read_initial_values(path);
    randomNumbers.push_back(initial_values[0]);
    for (std::size_t i = 1; i < size; ++i) {
        Id number = (initial_values[1] * randomNumbers[i - 1] + initial_values[2]) % initial_values[3];
        randomNumbers.push_back(number);
    }
    randomNumbers.erase(std::remove(randomNumbers.begin(), randomNumbers.end(), initial_values[0]), randomNumbers.end());
}

void LinearCongruentialGenerator::print()const noexcept(false) {
    for (std::size_t i = 0; i < randomNumbers.size(); ++i)
        std::cout << randomNumbers[i] << " ";
    std::cout << std::endl;
}

std::vector<Id> LinearCongruentialGenerator::get_randomNumbers()const { return randomNumbers; }
