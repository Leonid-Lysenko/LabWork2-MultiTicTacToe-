/* Leonid Lysenko st128618@student.spbu.ru
   Lab2
*/

/**
 * @file Game.cpp
 * @brief Implementation of the Game class managing the game flow.
 */

#include "Game.h"
#include <stdexcept>

/**
 * @brief Constructs a Game instance.
 * 
 * Initializes players, output handler, game mode, and initial game state.
 * 
 * @param player1 Unique pointer to the first player.
 * @param player2 Unique pointer to the second player.
 * @param output Shared pointer to the output handler.
 * @param mode Game mode (classic 2D or 3D).
 */
Game::Game(std::unique_ptr<Player> player1, 
           std::unique_ptr<Player> player2,
           std::shared_ptr<OutputHandler> output,
           Mode mode)
    : output(output),
      state(GameState::ONGOING),
      player1(std::move(player1)),
      player2(std::move(player2)),
      mode(mode) {}

/**
 * @brief Starts the game loop.
 * 
 * Depending on the mode, runs the game loop for classic or 3D tic-tac-toe.
 * Handles player turns until the game ends or exit is requested.
 * Displays the final game state.
 * 
 * @throws std::exception Propagates exceptions not related to player exit.
 */
void Game::start() {
    output->displayMessage("Game started! (Type 'exit' to quit at any time)");
    
    try {
        if (mode == Mode::CLASSIC) {
            output->displayBoard(board);
            
            while (state == GameState::ONGOING) {
                processPlayerTurn(*player1);
                if (state != GameState::ONGOING) break;
                
                processPlayerTurn(*player2);
            }
        } else {
            board3D.display(output);
            
            while (state == GameState::ONGOING) {
                process3DPlayerTurn(*player1);
                if (state != GameState::ONGOING) break;
                
                process3DPlayerTurn(*player2);
            }
        }
    } catch (const std::exception& e) {
        // If exit requested by any player, set state accordingly
        if (player1->shouldExit() || player2->shouldExit()) {
            state = GameState::EXITED;
        } else {
            throw; // Re-throw unexpected exceptions
        }
    }
    
    output->displayGameState(state);
}

/**
 * @brief Processes a single turn for a player in classic 2D mode.
 * 
 * Checks for exit request, prompts the player for a move, updates the board,
 * displays the board, and checks the game state.
 * 
 * @param player Reference to the player whose turn it is.
 */
void Game::processPlayerTurn(Player& player) {
    if (player.shouldExit()) {
        state = GameState::EXITED;
        return;
    }
    
    output->displayMessage(player.getMarker() == Cell::X ? "X's turn:" : "O's turn:");
    
    Move move = player.getMove(board);
    board.setCell(move.position.row, move.position.col, move.player);
    output->displayBoard(board);
    checkGameState();
}

/**
 * @brief Processes a single turn for a player in 3D mode.
 * 
 * Checks for exit request, prompts the player for a 3D move, updates the 3D board,
 * displays the current board state, and checks the 3D game state.
 * 
 * @param player Reference to the player whose turn it is.
 */
void Game::process3DPlayerTurn(Player& player) {
    try {
        if (player.shouldExit()) {
            state = GameState::EXITED;
            return;
        }
        
        output->displayMessage(player.getMarker() == Cell::X ? 
            "X's turn:" : "O's turn:");
        
        Position3D pos = player.get3DMove(board3D);
        Move move(pos.position, player.getMarker());
        board3D.makeMove(pos.level, move);
        
        output->displayMessage("Current board state:");
        board3D.display(output);
        
        check3DGameState();
    } catch (const std::exception& e) {
        if (player.shouldExit()) {
            state = GameState::EXITED;
        } else {
            throw;
        }
    }
}

/**
 * @brief Checks the current game state for classic 2D mode.
 * 
 * Updates the game state to reflect a win, draw, or ongoing game.
 */
void Game::checkGameState() {
    if (rules.checkWin(board, Cell::X)) {
        state = GameState::X_WON;
    } else if (rules.checkWin(board, Cell::O)) {
        state = GameState::O_WON;
    } else if (board.isFull()) {
        state = GameState::DRAW;
    }
}

/**
 * @brief Checks the current game state for 3D mode.
 * 
 * Updates the game state to reflect a win, draw, or ongoing game.
 */
void Game::check3DGameState() {
    if (board3D.checkWin(Cell::X)) {
        state = GameState::X_WON;
    } else if (board3D.checkWin(Cell::O)) {
        state = GameState::O_WON;
    } else if (board3D.isFull()) {
        state = GameState::DRAW;
    }
}

/**
 * @brief Returns the current game state.
 * 
 * @return The current GameState enum value.
 */
GameState Game::getState() const {
    return state;
}

