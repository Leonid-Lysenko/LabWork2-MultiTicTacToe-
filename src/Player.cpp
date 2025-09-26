/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file Player.cpp
 * @brief Implementation of the Player base class.
 */

#include "Player.h"

/**
 * @brief Constructs a Player with the specified marker and optional input handler.
 * 
 * @param marker The player's marker (Cell::X or Cell::O).
 * @param inputHandler Shared pointer to an InputHandler (optional).
 */
Player::Player(Cell marker, std::shared_ptr<InputHandler> inputHandler) 
    : marker(marker), inputHandler(inputHandler) {}

/**
 * @brief Returns the player's marker.
 * 
 * @return The Cell marker representing the player.
 */
Cell Player::getMarker() const {
    return marker;
}

/**
 * @brief Checks if the player has requested to exit the game.
 * 
 * Delegates the check to the input handler if available.
 * 
 * @return true if exit was requested, false otherwise.
 */
bool Player::shouldExit() const {
    return inputHandler ? inputHandler->shouldExit() : false;
}

/**
 * @brief Virtual destructor for the Player base class.
 */
Player::~Player() = default;

