# System Requirements

## Functional Requirements

### 1. Game Core
* The system shall provide a terminal-based turn-based strategy game: Multi Tic-Tac-Toe, supporting both classic (2D) and 3D game modes.
* The system shall support matches between two human players, one human and one AI, or two AI players.
* The system shall allow the user to select the game mode (classic or 3D) before starting a match.
* The system shall manage the game state, including alternating turns, checking for win/draw conditions, and restarting or exiting the game.

### 2. Players
* The system shall support human players, who interact via console input.
* The system shall support AI players with three difficulty levels: Easy, Medium, and Hard.
* The system shall allow the user to select the type (human/AI) and marker (X or O) for each player.
* The system shall ensure that each player is assigned a unique marker.

### 3. Boards
* The system shall provide a standard 3x3 grid for classic mode.
* The system shall provide a 3D board consisting of multiple 3x3 grids (levels) for 3D mode.
* The system shall manage board state, validate moves, and detect winning combinations (rows, columns, diagonals for 2D; across levels for 3D).

### 4. Moves and Validation
* The system shall prompt the current player to enter a move (row/column for 2D; level/row/column for 3D).
* The system shall validate input for correctness (within bounds, cell unoccupied).
* The system shall reject invalid moves and prompt the player to try again.

### 5. Artificial Intelligence (AI)
* The system shall provide AI opponents with three difficulty levels:
  * **Easy:** selects moves randomly from available cells.
  * **Medium:** blocks immediate opponent wins and seeks immediate wins.
  * **Hard:** uses advanced strategies (e.g., minimax or similar) to maximize chances of winning.
* The AI shall function in both classic and 3D modes.

### 6. Input and Output
* The system shall use a console-based interface for all user interaction.
* The system shall display the current board state, player turns, and results of each move.
* The system shall provide clear error messages for invalid input and notify users of game outcomes (win, draw, exit).

### 7. Game Flow
* The system shall alternate turns between the two players until a win or draw is detected.
* The system shall allow restarting or exiting the game after a match concludes.

### 8. Utility Components
* The system shall include modules for input validation and random number generation for AI.
* The system shall ensure robustness and prevent crashes due to invalid input.

## Non-Functional Requirements

### 1. Performance
* The system shall respond to user input and AI calculations within 1 second on modern hardware.
* The system shall efficiently handle both 2D and 3D board logic without noticeable delays.

### 2. Usability
* The system shall provide intuitive and clear prompts for all user actions.
* The system shall display the board and game status in an easily readable format.

### 3. Maintainability
* The system shall be implemented in C++ using modular, object-oriented design.
* The code shall include Doxygen comments for all classes and methods.
* The system shall be structured to allow easy addition of new features (e.g., new AI levels, board sizes).

## Constraints

* The system shall operate exclusively in a terminal environment using standard C++ libraries.
* The game board size for classic mode is fixed at 3x3; for 3D mode, the number of levels is fixed (e.g., 3).
* The system shall not support networked or graphical play in the current version.

# Use Case Scenarios

1. **Launching the Game:**
    * The user launches the Multi Tic-Tac-Toe executable.
    * The system displays a main menu with options to start a new game, view rules, or exit.

2. **Starting a New Game:**
    * The user selects "Start Game" from the menu.
    * The system prompts the user to choose the game mode (classic or 3D).
    * The system prompts the user to select player types (human/AI) and AI difficulty if applicable.
    * The system assigns markers (X or O) to each player.
    * The system displays the initial empty board.

3. **Making a Move:**
    * The system prompts the current player to enter their move (row and column for 2D; level, row, and column for 3D).
    * The system validates the move for correctness and cell availability.
    * If the move is invalid, the system displays an error and prompts again.
    * If valid, the system updates the board and displays the new state.

4. **AI Turn:**
    * If the current player is AI, the system calculates the move according to the selected difficulty.
    * The system displays the AI's move and updates the board.

5. **Winning the Game:**
    * After each move, the system checks for a win or draw condition.
    * If a player wins, the system displays a congratulatory message and the final board state.
    * If the board is full with no winner, the system declares a draw.

6. **Restarting or Exiting:**
    * After a game concludes, the system prompts the user to restart or exit.
    * If restart is chosen, the system returns to the main menu.
    * If exit is chosen, the program terminates.

7. **Exiting at Any Time:**
    * At any main menu or prompt, the user can choose to exit, and the system will terminate gracefully.

## Notes

* These requirements and scenarios reflect the current capabilities of Multi Tic-Tac-Toe. Future versions may include graphical UI, online multiplayer, or custom board sizes.

