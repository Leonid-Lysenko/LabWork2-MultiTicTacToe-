/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file test_3d_game.cpp
 * @brief Unit tests for 3D Tic-Tac-Toe game mode including win scenarios and early exit handling.
 */

#include <gtest/gtest.h>
#include "Game.h"
#include "HumanPlayer.h"
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include <sstream>

/**
 * @class Mock3DInput
 * @brief Mock input handler for simulating 3D game inputs in tests.
 *
 * Provides a sequence of predefined inputs for 3D positions and supports simulating an exit request.
 */
class Mock3DInput : public InputHandler {
public:
    /**
     * @brief Sets the sequence of input strings to simulate player moves.
     * @param inputs Vector of strings representing moves or commands (e.g. "exit").
     */
    void setInputSequence(const std::vector<std::string>& inputs) {
        this->inputs = inputs;
        current = 0;
        exitRequested = false;
    }

    /**
     * @brief Disabled for 3D mode; throws if called.
     * @throws std::runtime_error Always throws because 2D input is unsupported in 3D mode.
     */
    Position getInput() override {
        throw std::runtime_error("2D input not supported in 3D mode");
    }

    /**
     * @brief Returns the next 3D position input from the sequence.
     * @return Position3D Parsed 3D position from input string.
     * @throws std::runtime_error If exit was requested or no more inputs are available.
     * @throws std::invalid_argument If input format is invalid.
     */
    Position3D get3DInput() override {
        if (exitRequested) {
            throw std::runtime_error("Exit was requested");
        }
        
        if (current >= inputs.size()) {
            throw std::runtime_error("No more test inputs");
        }
        
        std::string input = inputs[current++];
        if (input == "exit") {
            exitRequested = true;
            throw std::runtime_error("Exit requested by player");
        }
        
        std::istringstream iss(input);
        int level, row, col;
        if (!(iss >> level >> row >> col)) {
            throw std::invalid_argument("Invalid 3D input format");
        }
        return Position3D(level-1, Position(row-1, col-1));
    }

    /**
     * @brief Indicates whether the player has requested to exit the game.
     * @return true if exit was requested, false otherwise.
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
 * @brief Test case for winning the 3D game by completing a space diagonal.
 *
 * Simulates a sequence of moves leading player X to win by forming a diagonal across levels.
 */
TEST(ThreeDGameTest, SpaceDiagonalWin) {
    auto input = std::make_shared<Mock3DInput>();
    auto output = std::make_shared<ConsoleOutput>();
    
    input->setInputSequence({
        "1 1 1", // X
        "1 2 2", // O
        "2 2 2", // X
        "2 1 1", // O
        "3 3 3"  // X wins
    });

    auto player1 = std::make_unique<HumanPlayer>(Cell::X, input);
    auto player2 = std::make_unique<HumanPlayer>(Cell::O, input);
    
    Game game(std::move(player1), std::move(player2), output, Game::Mode::THREE_D);
    game.start();
    
    EXPECT_EQ(game.getState(), GameState::X_WON);
}

/**
 * @brief Test case for early exit from the 3D game.
 *
 * Simulates a player requesting to exit after the first move.
 */
TEST(ThreeDGameTest, EarlyExit) {
    auto input = std::make_shared<Mock3DInput>();
    auto output = std::make_shared<ConsoleOutput>();
    
    input->setInputSequence({
        "1 1 1", // X
        "exit"   // Exit
    });

    auto player1 = std::make_unique<HumanPlayer>(Cell::X, input);
    auto player2 = std::make_unique<HumanPlayer>(Cell::O, input);
    
    Game game(std::move(player1), std::move(player2), output, Game::Mode::THREE_D);
    game.start();
    
    EXPECT_EQ(game.getState(), GameState::EXITED);
}

