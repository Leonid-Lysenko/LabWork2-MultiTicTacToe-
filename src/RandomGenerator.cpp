/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file RandomGenerator.cpp
 * @brief Implementation of the RandomGenerator class for generating random integers.
 */

#include "RandomGenerator.h"

/**
 * @brief Constructs a RandomGenerator and initializes the random number engine.
 */
RandomGenerator::RandomGenerator() : gen(rd()) {}

/**
 * @brief Generates a random integer within the inclusive range [min, max].
 * 
 * @param min The minimum value (inclusive).
 * @param max The maximum value (inclusive).
 * @return A randomly generated integer between min and max.
 */
int RandomGenerator::generate(int min, int max) {
    std::uniform_int_distribution<> distrib(min, max);
    return distrib(gen);
}

