//
// Created by elena
//
#ifndef LINEAR_CONGRUENTIAL_GENERATOR_GENERATOR_H
#define LINEAR_CONGRUENTIAL_GENERATOR_GENERATOR_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using Id = int;

class LinearCongruentialGenerator final {
private:
    std::vector<Id> randomNumbers;
    std::size_t size;
public:
    explicit LinearCongruentialGenerator(std::size_t number);
    ~LinearCongruentialGenerator();

    [[nodiscard]] std::vector<Id> get_randomNumbers()const;

    void start_generator(const std::string& path)noexcept;

    void print()const noexcept(false);
private:
    static std::vector<Id> try_read_initial_values(const std::string& name)noexcept;
    static std::vector<Id> read_initial_values(const std::string& name)noexcept(false);

    static std::vector<Id> parse_values(const std::string& line)noexcept;

};

#endif
