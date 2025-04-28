# Component Diagram

This component diagram illustrates the high-level structure and interactions of the main subsystems in the Tic-Tac-Toe project:

## Components

- **GameCore**
  Manages core game logic, including game state, player management, game mode selection (classic/3D), and turn handling. Coordinates with BoardSystem, AISystem, and UserInterface for gameplay, move processing, and output.

- **BoardSystem**
  Handles board representation and logic for both 2D and 3D Tic-Tac-Toe. Provides methods for move validation, win checking, and board state management.

- **AISystem**
  Implements AI logic for computer players, including move calculation and difficulty strategies. Interacts with BoardSystem to analyze the board and select optimal moves.

- **UserInterface**
  Provides terminal-based user interaction, including input prompts, move validation, and display of game status and results.

## Interactions

- **GameCore** uses **BoardSystem** to manage the board and validate moves.

- **GameCore** uses **AISystem** to generate AI moves.

- **GameCore** uses **UserInterface** for all user input and output.

- **AISystem** uses **BoardSystem** to analyze the board.

- **UserInterface** uses **BoardSystem** to display the board and validate user moves.

