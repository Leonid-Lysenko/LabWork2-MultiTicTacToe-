# Detailed Description of the Class Diagram

This class diagram represents the architecture of an advanced Tic-Tac-Toe game supporting both classic and 3D gameplay, human and AI players, and multiple AI difficulty levels. The design is modular, extensible, and follows object-oriented principles.

## Enumerations

- **Cell**
  Represents the possible states of a cell on the board: empty, X, or O.
  This enum is used throughout the game logic to identify the state of each position.

- **Mode**
  Defines the game mode: classic (2D) or three-dimensional (3D).
  This allows the game logic to adapt to different board types and rules.

## Core Value Objects

- **Position**
  Encapsulates a two-dimensional coordinate (`row`, `col`) on the board.
  Provides constructors and equality comparison for convenient use in board logic.

- **Position3D**
  Extends `Position` by adding a level (z-coordinate), representing a cell in a 3D board.
  Useful for 3D Tic-Tac-Toe, allowing moves to be specified in three dimensions.

- **Move**
  Represents a move in the game, combining a `Position` and the `Cell` (player) making the move.
  This abstraction allows for easy passing and validation of moves.

## Board Representation

- **Board**
  Models a standard 2D Tic-Tac-Toe board using a 2D array of `Cell` values.
  Provides methods to get and set cell values and to check for a win condition.

- **Board3D**
  Represents a 3D Tic-Tac-Toe board as an array of `Board` objects, one per level.
  It provides methods to access individual levels, make moves, and check for a win in 3D space.

## Input and Output Abstractions

- **ConsoleInput**
  Handles user input from the console, providing a method to retrieve input as a string.

- **ConsoleOutput**
  Responsible for displaying messages to the user via the console.

- **InputHandler**
  Abstracts input handling, providing a method to determine if the player wants to exit the game.
  This allows for flexible input sources and exit conditions.

## Player Hierarchy

- **Player (Abstract)**
  The base class for all players (human or AI).
  Stores the player’s marker (`Cell`) and an input handler.
  Declares virtual methods for making moves in both 2D and 3D games, and for querying the player’s marker or exit status.

- **HumanPlayer**
  Inherits from `Player`.
  Implements move methods by interacting with the user via input handlers.

- **AIPlayer**
  Inherits from `Player`.
  Contains a unique pointer to an `AIDifficulty` strategy, which determines the AI’s behavior.
  Implements move methods by delegating to the difficulty strategy and includes logic for finding winning moves in 3D.

## AI Difficulty Strategy Hierarchy

- **AIDifficulty (Abstract)**
  Defines the interface for AI move calculation strategies.
  Allows for different AI behaviors to be plugged into the `AIPlayer`.

- **EasyAIDifficulty**
  Implements a basic AI strategy (e.g., random or first-available move).

- **MediumAIDifficulty**
  Implements a more advanced strategy, possibly including logic to find immediate winning moves.

- **HardAIDifficulty**
  Implements the most advanced AI strategy, potentially using minimax or similar algorithms.

## Utility Classes

- **Validator**
  Provides methods to validate user input and convert it into `Position` or `Position3D` objects.
  Ensures that moves entered by the user are legal and correctly formatted.

- **RandomGenerator**
  Encapsulates random number generation, using standard C++ random facilities.
  Used by AI strategies to select moves randomly when appropriate.

## Game Orchestration

- **Game**
  The central class that manages the game loop, players, board, and output.
  Holds unique pointers to two players and a shared pointer to the output handler.
  The `start()` method runs the main game logic, alternating turns, checking for win conditions, and handling user interaction.

## Relationships and Interactions

- **Inheritance:**
  - `HumanPlayer` and `AIPlayer` both inherit from `Player`, enabling polymorphic handling of players.
  - `EasyAIDifficulty`, `MediumAIDifficulty`, and `HardAIDifficulty` inherit from `AIDifficulty`, allowing different AI behaviors.

- **Composition and Aggregation:**
  - `Game` owns two `Player` objects and an output handler.
  - `AIPlayer` owns an `AIDifficulty` strategy.
  - `Board3D` is composed of multiple `Board` objects (one per level).
  - `Player` references an `InputHandler` for user input or exit detection.

- **Usage:**
  - `Validator` and `RandomGenerator` are utility classes used throughout the game logic and AI.

## Summary

This class structure enables:

- Flexible switching between human and AI players.
- Easy addition of new AI difficulty levels.
- Support for both classic and 3D Tic-Tac-Toe modes.
- Clean separation of concerns between game logic, input/output, player behavior, and utility functions.

