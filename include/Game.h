/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file Game.h
 * @brief Header file for the Game class.
 */

#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "GameState.h"
#include "GameRules.h"
#include "OutputHandler.h"
#include "Board.h"
#include "Board3D.h"
#include <memory>

/**
 * @class Game
 * @brief The main game class managing the game flow.
 */
class Game {
public:
    friend class TestGame; // Даем доступ тестовому классу
    /**
     * @enum Mode
     * @brief Game modes supported.
     */
    enum class Mode { CLASSIC, THREE_D };
    
    /**
     * @brief Constructs a new Game instance.
     * @param player1 The first player.
     * @param player2 The second player.
     * @param output Output handler for displaying game info.
     * @param mode Game mode, either CLASSIC or THREE_D (default CLASSIC).
     */
    Game(std::unique_ptr<Player> player1, 
         std::unique_ptr<Player> player2,
         std::shared_ptr<OutputHandler> output,
         Mode mode = Mode::CLASSIC);

    /**
     * @brief Starts the game loop.
     */
    void start();

    /**
     * @brief Returns the current game state.
     * @return The current GameState.
     */
    GameState getState() const;

private:
    /**
     * @brief Processes a single turn for a player in classic mode.
     * @param player The player making the move.
     */
    void processPlayerTurn(Player& player);

    /**
     * @brief Processes a single turn for a player in 3D mode.
     * @param player The player making the move.
     */
    void process3DPlayerTurn(Player& player);

    /**
     * @brief Checks and updates the game state in classic mode.
     */
    void checkGameState();

    /**
     * @brief Checks and updates the game state in 3D mode.
     */
    void check3DGameState();

    std::shared_ptr<OutputHandler> output; ///< Output handler.
    GameState state; ///< Current game state.
    std::unique_ptr<Player> player1; ///< First player.
    std::unique_ptr<Player> player2; ///< Second player.
    Board board; ///< Classic 2D game board.
    Board3D board3D; ///< 3D game board.
    GameRules rules; ///< Game rules checker.
    Mode mode; ///< Current game mode.
};

#endif // GAME_H

