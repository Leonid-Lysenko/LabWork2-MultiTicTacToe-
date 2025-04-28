/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file test_classic_human_vs_human.cpp
 * @brief Unit tests for classic 2D Tic-Tac-Toe mode with two human players.
 */

#include <gtest/gtest.h>
#include "Game.h"
#include "HumanPlayer.h"
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include <sstream>

/**
 * @class MockInput
 * @brief Mock input handler to simulate 2D game inputs for human players.
 *
 * Provides a predefined sequence of 2D moves for testing purposes.
 */
class MockInput : public InputHandler {
public:
    /**
     * @brief Sets the sequence of input strings representing moves.
     * @param inputs Vector of strings in the format "row col".
     */
    void setInputSequence(const std::vector<std::string>& inputs) {
        this->inputs = inputs;
        current = 0;
    }

    /**
     * @brief Returns the next 2D position input from the sequence.
     * @return Position Parsed 2D position from input string.
     * @throws std::runtime_error If no more inputs are available.
     */
    Position getInput() override {
        if (current >= inputs.size()) {
            throw std::runtime_error("No more test inputs");
        }
        std::string input = inputs[current++];
        std::istringstream iss(input);
        int row, col;
        iss >> row >> col;
        return Position(row-1, col-1);
    }

    /**
     * @brief Disabled for classic mode; throws if called.
     * @throws std::runtime_error Always throws because 3D input is unsupported in classic mode.
     */
    Position3D get3DInput() override {
        throw std::runtime_error("3D input not supported");
    }

    /**
     * @brief Indicates whether the player has requested to exit the game.
     * @return false Always returns false as exit is not simulated here.
     */
    bool shouldExit() const override {
        return false;
    }

private:
    std::vector<std::string> inputs; ///< Sequence of input commands or moves.
    size_t current = 0;              ///< Current input index.
};

/**
 * @brief Test case where player X wins by forming a horizontal line in classic 2D mode.
 */
TEST(ClassicHumanVsHuman, XWinsHorizontal) {
    auto input = std::make_shared<MockInput>();
    auto output = std::make_shared<ConsoleOutput>();
    
    input->setInputSequence({
        "1 1", // X
        "2 1", // O 
        "1 2", // X
        "2 2", // O
        "1 3"  // X wins
    });

    auto player1 = std::make_unique<HumanPlayer>(Cell::X, input);
    auto player2 = std::make_unique<HumanPlayer>(Cell::O, input);
    
    Game game(std::move(player1), std::move(player2), output, Game::Mode::CLASSIC);
    game.start();
    
    EXPECT_EQ(game.getState(), GameState::X_WON);
}

/**
 * @brief Test case for a draw game in classic 2D mode.
 */
TEST(ClassicHumanVsHuman, DrawGame) {
    auto input = std::make_shared<MockInput>();
    auto output = std::make_shared<ConsoleOutput>();
    
    input->setInputSequence({
        "1 1", "1 2", "1 3",
        "2 2", "2 1", "2 3",
        "3 3", "3 1", "3 2"
    });

    auto player1 = std::make_unique<HumanPlayer>(Cell::X, input);
    auto player2 = std::make_unique<HumanPlayer>(Cell::O, input);
    
    Game game(std::move(player1), std::move(player2), output, Game::Mode::CLASSIC);
    game.start();
    
    EXPECT_EQ(game.getState(), GameState::DRAW);
}

/**
 * @brief Test case for handling invalid moves in classic 2D mode.
 *
 * Verifies that invalid moves are rejected and the player is prompted again.
 */
TEST(ClassicHumanVsHuman, InvalidMoveHandling) {
    auto input = std::make_shared<MockInput>();
    auto output = std::make_shared<ConsoleOutput>();
    
    input->setInputSequence({
        "1 1", "4 2", "1 2", // O attempts invalid move "4 2"
        "2 1", "2 2",
        "3 1"  // X wins
    });

    auto player1 = std::make_unique<HumanPlayer>(Cell::X, input);
    auto player2 = std::make_unique<HumanPlayer>(Cell::O, input);
    
    Game game(std::move(player1), std::move(player2), output, Game::Mode::CLASSIC);
    game.start();
    
    EXPECT_EQ(game.getState(), GameState::X_WON);
}

