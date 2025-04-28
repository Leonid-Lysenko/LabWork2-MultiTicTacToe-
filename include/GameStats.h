/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file GameStats.h
 * @brief Header file for the GameStats class.
 */

#ifndef GAME_STATS_H
#define GAME_STATS_H

#include <string>

/**
 * @class GameStats
 * @brief Tracks game statistics.
 */
class GameStats {
public:
    /**
     * @brief Constructs a new GameStats instance.
     */
    GameStats();

    /**
     * @brief Records a win for player X.
     */
    void addXWin();

    /**
     * @brief Records a win for player O.
     */
    void addOWin();

    /**
     * @brief Records a draw.
     */
    void addDraw();

    /**
     * @brief Retrieves the current statistics as a formatted string.
     * @return A string containing the statistics.
     */
    std::string getStats() const;

private:
    int xWins;  ///< Number of wins by player X.
    int oWins;  ///< Number of wins by player O.
    int draws;  ///< Number of draws.
};

#endif // GAME_STATS_H

