/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file RandomGenerator.h
 * @brief Header file for the RandomGenerator class.
 */

#ifndef RANDOM_GENERATOR_H
#define RANDOM_GENERATOR_H

#include <random>

/**
 * @class RandomGenerator
 * @brief Random number generator.
 */
class RandomGenerator {
public:
    /**
     * @brief Constructs a RandomGenerator.
     */
    RandomGenerator();

    /**
     * @brief Generates a random integer within the specified range [min, max].
     * @param min Minimum value.
     * @param max Maximum value.
     * @return A random integer between min and max inclusive.
     */
    int generate(int min, int max);

private:
    std::random_device rd;   ///< Random device for seeding.
    std::mt19937 gen;        ///< Mersenne Twister random number generator.
};

#endif // RANDOM_GENERATOR_H

