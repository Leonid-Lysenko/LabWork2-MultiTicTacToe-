# General System Description: Multi Tic-Tac-Toe

**Genre:** Turn-based strategy, classic and 3D Tic-Tac-Toe game with AI opponents

**Concept:**
Multi Tic-Tac-Toe is an advanced turn-based game that extends the classic Tic-Tac-Toe concept into both traditional 2D and innovative 3D gameplay modes. The game supports human players competing against each other or against AI-controlled opponents with multiple difficulty levels. The focus is on strategic placement of markers on the board to achieve winning combinations, with additional complexity introduced by the 3D mode and AI strategies.

## Main System Elements:

1. **Players:**
    * Can be human or AI-controlled.
    * Each player uses a marker (`X` or `O`) to make moves on the board.
    * Human players interact via console input, while AI players use different difficulty strategies to calculate optimal moves.

2. **Boards:**
    * **Classic 2D Board:** A standard 3x3 grid representing the traditional Tic-Tac-Toe board.
    * **3D Board:** Consists of multiple stacked 2D boards (levels), allowing moves in three dimensions and adding strategic depth.
    * Boards manage the state of each cell and provide methods to check for winning conditions.

3. **Moves and Positions:**
    * Moves are represented by positions on the board (`row`, `col` for 2D; `level`, `row`, `col` for 3D) along with the player’s marker.
    * The system validates moves to ensure legality and updates the board state accordingly.

4. **Artificial Intelligence (AI):**
    * AI players use different difficulty strategies (`Easy`, `Medium`, `Hard`) to determine their moves.
    * Strategies range from random move selection to advanced algorithms that analyze the board to find winning or blocking moves.
    * AI supports both 2D and 3D modes, adapting its logic accordingly.

5. **Input and Output:**
    * The game uses console-based input and output for interaction.
    * Input handlers manage user commands and exit requests.
    * Output handlers display the board state, moves, and game status messages.

6. **Game Flow:**
    * The game alternates turns between two players until a win or draw condition is met.
    * In 3D mode, the complexity of winning combinations increases, requiring more strategic thinking.
    * The system manages turn order, move validation, win checking, and game termination.

7. **Utility Components:**
    * Includes modules for validating user input and generating random numbers used by AI.
    * Ensures robustness and fairness in gameplay.

## Game Goal:  
To be the first player to align their markers in a winning combination on the board-either in a row, column, diagonal (2D), or across levels (3D)-or to force a draw if no winning moves remain.

