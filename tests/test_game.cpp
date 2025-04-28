/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file test_game.cpp
 * @brief Unit tests for the Game class in classic mode.
 */

#include <gtest/gtest.h>
#include "Game.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"
#include "EasyAIDifficulty.h"
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include <sstream>

/**
 * @class MockInput
 * @brief Mock input handler simulating user inputs and exit requests for classic mode tests.
 */
class MockInput : public InputHandler {
public:
    /**
     * @brief Sets the sequence of input strings representing moves or commands.
     * @param inputs Vector of input strings.
     */
    void setInputSequence(const std::vector<std::string>& inputs) {
        this->inputs = inputs;
        current = 0;
        exitRequested = false;
    }

    /**
     * @brief Returns the next 2D position input from the sequence.
     * @return Position Parsed 2D position from input string.
     * @throws std::runtime_error If exit is requested or no more inputs are available.
     * @throws std::invalid_argument If input format is invalid.
     */
    Position getInput() override {
        if (exitRequested) {
            throw std::runtime_error("Exit requested");
        }
        
        if (current >= inputs.size()) {
            exitRequested = true;
            throw std::runtime_error("No more test inputs");
        }
        
        std::string input = inputs[current++];
        if (input == "exit") {
            exitRequested = true;
            throw std::runtime_error("Exit requested");
        }
        
        std::istringstream iss(input);
        int row, col;
        if (!(iss >> row >> col)) {
            throw std::invalid_argument("Invalid input format");
        }
        return Position(row - 1, col - 1);
    }

    /**
     * @brief Disabled for classic mode; throws if called.
     * @throws std::runtime_error Always throws because 3D input is unsupported in classic mode.
     */
    Position3D get3DInput() override {
        throw std::runtime_error("3D input not supported in classic mode");
    }

    /**
     * @brief Indicates whether the player has requested to exit the game.
     * @return true if exit requested, false otherwise.
     */
    bool shouldExit() const override {
        return exitRequested;
    }

private:
    std::vector<std::string> inputs; ///< Sequence of input commands or moves.
    size_t current = 0;              ///< Current input index.
    bool exitRequested = false;      ///< Exit request flag.
};

/**
 * @brief Test that the game initializes correctly with human and AI players.
 */
TEST(GameTest, GameInitialization) {
    auto input = std::make_shared<MockInput>();
    auto output = std::make_shared<ConsoleOutput>();
    auto human = std::make_unique<HumanPlayer>(Cell::X, input);
    auto ai = std::make_unique<AIPlayer>(Cell::O, std::make_unique<EasyAIDifficulty>());
    
    Game game(std::move(human), std::move(ai), output);
    EXPECT_EQ(game.getState(), GameState::ONGOING);
}

/**
 * @brief Test that the game starts correctly and is in ongoing state.
 */
TEST(GameTest, GameStartsCorrectly) {
    auto input = std::make_shared<MockInput>();
    auto output = std::make_shared<ConsoleOutput>();
    
    auto human = std::make_unique<HumanPlayer>(Cell::X, input);
    auto ai = std::make_unique<AIPlayer>(Cell::O, std::make_unique<EasyAIDifficulty>());
    
    Game game(std::move(human), std::move(ai), output);
    
    EXPECT_EQ(game.getState(), GameState::ONGOING);
}

