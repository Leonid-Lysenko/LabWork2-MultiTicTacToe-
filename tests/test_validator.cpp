/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file test_validator.cpp
 * @brief Unit tests for the Validator class.
 */

#include <gtest/gtest.h>
#include "Validator.h"

/**
 * @brief Test that valid input strings are correctly parsed into Position objects.
 */
TEST(ValidatorTest, ValidInput) {
    Validator validator;
    Position pos = validator.validateInput("1 2");
    EXPECT_EQ(pos.row, 0);
    EXPECT_EQ(pos.col, 1);
}

/**
 * @brief Test that invalid input formats throw std::invalid_argument exceptions.
 */
TEST(ValidatorTest, InvalidInputFormat) {
    Validator validator;
    EXPECT_THROW(validator.validateInput("abc"), std::invalid_argument);
    EXPECT_THROW(validator.validateInput("1"), std::invalid_argument);
}

/**
 * @brief Test that input values outside the valid range throw std::invalid_argument exceptions.
 */
TEST(ValidatorTest, InvalidInputRange) {
    Validator validator;
    EXPECT_THROW(validator.validateInput("0 1"), std::invalid_argument);
    EXPECT_THROW(validator.validateInput("4 2"), std::invalid_argument);
}

