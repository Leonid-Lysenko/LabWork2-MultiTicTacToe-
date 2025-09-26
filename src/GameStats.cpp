/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file GameStats.cpp
 * @brief Implementation of the GameStats class for tracking game outcomes.
 */

#include "GameStats.h"
#include <sstream>

/**
 * @brief Constructs a GameStats object with zeroed counters.
 */
GameStats::GameStats() : xWins(0), oWins(0), draws(0) {}

/**
 * @brief Increments the count of X player wins.
 */
void GameStats::addXWin() { 
    xWins++; 
}

/**
 * @brief Increments the count of O player wins.
 */
void GameStats::addOWin() { 
    oWins++; 
}

/**
 * @brief Increments the count of draw games.
 */
void GameStats::addDraw() { 
    draws++; 
}

/**
 * @brief Returns a formatted string with the current game statistics.
 * 
 * Includes number of X wins, O wins, and draws.
 * 
 * @return A string representing the statistics summary.
 */
std::string GameStats::getStats() const {
    std::ostringstream oss;
    oss << "Statistics:\n";
    oss << "X wins: " << xWins << "\n";
    oss << "O wins: " << oWins << "\n";
    oss << "Draws: " << draws << "\n";
    return oss.str();
}

