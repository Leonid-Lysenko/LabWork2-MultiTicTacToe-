# Test Plan for Multi Tic-Tac-Toe

This test plan corresponds to the updated integration tests with controlled AI behavior, ensuring deterministic AI moves and detailed scenario coverage.

---

## 1. Functional Test Cases

### 1.1 Classic Mode Tests

- **ClassicHumanVsHuman_XWinsHorizontal**
  Verify that a human player (X) can win by completing a horizontal line on the 2D board.

- **ClassicHumanVsHuman_DrawGame**
  Verify that the game correctly detects a draw when the board is full with no winner.

- **ClassicHumanVsHuman_InvalidMoveHandling**
  Verify that invalid moves (out-of-bounds or occupied cells) are rejected and the player is prompted again.

- **GameTest_GameInitialization**
  Check that the game initializes properly with human and AI players, and the initial game state is ongoing.

- **GameTest_GameStartsCorrectly**
  Verify that the game starts in the ongoing state with correct player setup.

### 1.2 3D Mode Tests

- **ThreeDHumanVsHuman_SpaceDiagonalWin**
  Verify that a player can win by completing a diagonal line across levels in 3D mode.

- **ThreeDHumanVsHuman_VerticalLineWin**
  Verify that a player can win by completing a vertical line in 3D mode.

- **ThreeDHumanVsHuman_ExitDuringGame**
  Verify that the game correctly handles a player exit request during gameplay.

- **ThreeDGameTest_SpaceDiagonalWin**
  Similar to above, tests winning condition on 3D diagonal.

- **ThreeDGameTest_EarlyExit**
  Tests early exit functionality in 3D mode.

### 1.3 AI Behavior Tests

- **AITest_EasyAIMakesValidMove**
  Verify that Easy AI selects a valid and empty cell on the board.

- **AITest_MediumAIBlocksWin**
  Verify that Medium AI blocks opponent’s immediate winning move.

- **AITest_HardAIPrefersWinning**
  Verify that Hard AI chooses a winning move when available.

### 1.4 Board Class Tests

- **BoardTest_Initialization**
  Verify that a new board is empty and not full.

- **BoardTest_SetAndGetCell**
  Verify that cells can be set and retrieved correctly.

- **BoardTest_MoveValidation**
  Verify that valid and invalid moves are correctly identified.

### 1.5 Game Rules Tests

- **GameRulesTest_CheckWin**
  Verify detection of winning conditions in rows, columns, and diagonals.

- **GameRulesTest_CheckDraw**
  Verify detection of draw when board is full without a winner.

### 1.6 Validator Tests

- **ValidatorTest_ValidInput**
  Verify that valid input strings are correctly parsed into positions.

- **ValidatorTest_InvalidInputFormat**
  Verify that malformed inputs throw exceptions.

- **ValidatorTest_InvalidInputRange**
  Verify that out-of-range inputs throw exceptions.

### 1.7 Integration Tests with Controlled AI (Updated)

- **IntegrationTest_AITakesFirstAvailableCell**
  Verify that the controlled AI picks the first available empty cell on the board deterministically.

- **IntegrationTest_AIRespondsToCornerMove**
  Verify AI’s response to a human move in the corner by selecting the next available cell.

- **IntegrationTest_AIBlocksWin**
  Verify that AI blocks the human player’s immediate winning move.

- **IntegrationTest_HumanWinsVertically**
  Verify that the human player can win vertically and the board state reflects this.

- **IntegrationTest_FullGameWithEasyAI**
  Simulate a full game between a human and Easy AI, verifying that the game ends with a valid final state (win/draw).

---

## 2. Test Environment

- **Framework:** Google Test (gtest)
- **Language:** C++17
- **Input Handling:** Mock input handlers simulate user and AI inputs for deterministic testing.
- **Output Handling:** Custom output capturing board state for verification.

---

## 3. Test Execution Procedure

1. Build the project with tests enabled.
2. Run all tests using the test runner (e.g., `ctest` or directly executing the test binary).
3. Confirm all tests pass without failures or errors.
4. For failing tests, analyze logs and debug accordingly.

---

## 4. Coverage Summary

- Core game logic and state transitions
- Player move input and validation (human and AI)
- Board state management and win/draw detection
- AI decision making at different difficulty levels, now with deterministic controlled AI for integration tests
- Handling of special cases like invalid input and early exit

---

## 5. Conclusion

The updated test plan ensures Multi Tic-Tac-Toe behaves correctly with deterministic AI moves, improving test reliability and coverage of AI response scenarios. It maintains comprehensive coverage of classic and 3D modes, input validation, and game flow.

