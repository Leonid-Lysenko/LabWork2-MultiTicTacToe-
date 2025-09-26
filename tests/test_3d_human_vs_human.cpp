/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file test_3d_human_vs_human.cpp
 * @brief Unit tests for 3D Tic-Tac-Toe mode with two human players.
 */

#include <gtest/gtest.h>
#include "Game.h"
#include "HumanPlayer.h"
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include <sstream>

/**
 * @class Mock3DInput
 * @brief Mock input handler to simulate 3D game inputs for human players.
 *
 * Provides a predefined sequence of 3D moves for testing purposes.
 */
class Mock3DInput : public InputHandler {
public:
    /**
     * @brief Sets the sequence of input strings representing moves.
     * @param inputs Vector of strings in the format "level row col".
     */
    void setInputSequence(const std::vector<std::string>& inputs) {
        this->inputs = inputs;
        current = 0;
    }

    /**
     * @brief Disabled for 3D mode; throws if called.
     * @throws std::runtime_error Always throws because 2D input is unsupported in 3D mode.
     */
    Position getInput() override {
        throw std::runtime_error("2D input not supported");
    }

    /**
     * @brief Returns the next 3D position input from the sequence.
     * @return Position3D Parsed 3D position from input string.
     * @throws std::runtime_error If no more inputs are available.
     */
    Position3D get3DInput() override {
        if (current >= inputs.size()) {
            throw std::runtime_error("No more test inputs");
        }
        std::string input = inputs[current++];
        std::istringstream iss(input);
        int level, row, col;
        iss >> level >> row >> col;
        return Position3D(level-1, Position(row-1, col-1));
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
 * @brief Test case where player X wins by forming a diagonal across levels in 3D.
 */
TEST(ThreeDHumanVsHuman, SpaceDiagonalWin) {
    auto input = std::make_shared<Mock3DInput>();
    auto output = std::make_shared<ConsoleOutput>();
    
    // X forms a diagonal through levels
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
 * @brief Test case where player O wins by forming a vertical line in 3D.
 */
TEST(ThreeDHumanVsHuman, VerticalLineWin) {
    auto input = std::make_shared<Mock3DInput>();
    auto output = std::make_shared<ConsoleOutput>();
    
    // O forms a vertical line
    input->setInputSequence({
        "1 2 2", // X
        "1 1 1", // O
        "2 3 3", // X 
        "2 1 1", // O
        "3 1 3", // X
        "3 1 1"  // O wins
    });

    auto player1 = std::make_unique<HumanPlayer>(Cell::X, input);
    auto player2 = std::make_unique<HumanPlayer>(Cell::O, input);
    
    Game game(std::move(player1), std::move(player2), output, Game::Mode::THREE_D);
    game.start();
    
    EXPECT_EQ(game.getState(), GameState::O_WON);
}

/**
 * @brief Test case for player exit during a 3D game.
 */
TEST(ThreeDHumanVsHuman, ExitDuringGame) {
    auto input = std::make_shared<Mock3DInput>();
    auto output = std::make_shared<ConsoleOutput>();
    
    // Test exit from game
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

