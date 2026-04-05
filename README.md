# Tic-Tac-Toe in C

A two-player, terminal-based Tic-Tac-Toe game written in C for Windows. Players take turns entering numbered positions to place their marks on a 3×3 grid until one player wins or the game ends in a draw.

---

## Table of Contents

- [Features](#features)
- [Requirements](#requirements)
- [Building](#building)
- [Running the Game](#running-the-game)
- [How to Play](#how-to-play)
- [Board Layout](#board-layout)
- [Project Structure](#project-structure)
- [Code Overview](#code-overview)
- [Known Limitations](#known-limitations)
- [Possible Improvements](#possible-improvements)
- [License](#license)

---

## Features

- Two-player local multiplayer (Player 1 = `X`, Player 2 = `O`)
- Color-coded terminal output (green text on black background)
- Input validation with retry on invalid moves
- Win detection across all rows, columns, and diagonals
- Draw detection when all squares are filled with no winner
- Board redraws cleanly after every move

---

## Requirements

| Requirement | Details |
|---|---|
| OS | Windows (uses `windows.h` and `conio.h`) |
| Compiler | GCC (MinGW/MSYS2) or MSVC |
| C Standard | C89 or later |

> **Note:** This program uses Windows-specific headers (`windows.h`, `conio.h`) and the `system("cls")` / `system("color")` calls. It will **not** compile or run directly on Linux or macOS without modification.

---

## Building

### Using GCC (MinGW)

```bash
gcc cTicTacToe.c -o tictactoe.exe
```

### Using MSVC (Developer Command Prompt)

```bash
cl cTicTacToe.c /Fe:tictactoe.exe
```

---

## Running the Game

```bash
tictactoe.exe
```

The console will switch to a green-on-black color scheme and display the initial board. No command-line arguments are required.

---

## How to Play

1. The game opens with an empty board showing positions numbered **1–9**.
2. **Player 1 (X)** is prompted first.
3. Enter the number of the square you want to claim and press **Enter**.
4. If the square is already taken or the input is out of range, you will be prompted to try again.
5. Players alternate turns until:
   - One player gets three marks in a row (horizontally, vertically, or diagonally) → that player **wins**.
   - All nine squares are filled with no winner → the game ends in a **draw**.
6. After the game ends, press any key to exit.

---

## Board Layout

Squares are numbered as shown below. Enter the corresponding number on your turn.

```
     |     |
  1  |  2  |  3
_____|_____|_____
     |     |
  4  |  5  |  6
_____|_____|_____
     |     |
  7  |  8  |  9
     |     |
```

Once a player claims a square, its number is replaced with `X` or `O`.

---

## Project Structure

```
.
└── cTicTacToe.c   # Single-file source — all game logic lives here
```

| Symbol | Type | Purpose |
|---|---|---|
| `square[10]` | `char` array | Stores the state of each board position (indices 1–9) |
| `main()` | function | Game loop — handles turns, input, and end conditions |
| `checkwin()` | function | Returns `1` (win), `0` (draw), or `-1` (game continues) |
| `drawBoard()` | function | Clears the screen and redraws the current board state |

---

## Code Overview

### `main()`

Runs the core game loop using a `do...while` construct. On each iteration it:

1. Draws the board.
2. Determines whose turn it is (odd iterations → Player 1, even → Player 2).
3. Reads the player's chosen square via `scanf`.
4. Validates the choice — the square must be in range and not already taken.
5. Places the mark and calls `checkwin()`.
6. Increments the player counter to alternate turns.

The loop exits when `checkwin()` returns anything other than `-1`.

### `checkwin()`

Checks all eight winning lines (three rows, three columns, two diagonals) by comparing the character values stored in `square[]`. Returns:

- `1` — a winning line was found.
- `0` — all squares are filled and no winner exists (draw).
- `-1` — the game should continue.

### `drawBoard()`

Calls `system("cls")` to clear the console, then prints the 3×3 grid using the current contents of `square[]`.

---

## Known Limitations

- **Windows only.** `conio.h`, `windows.h`, `system("cls")`, and `system("color 0A")` are not portable to POSIX systems.
- **No AI opponent.** The game is strictly two-player; there is no computer player.
- **No input sanitisation beyond range.** Non-numeric input to `scanf("%d", &choice)` can cause undefined behaviour or an infinite loop.
- **`Sleep` is imported but unused.** `windows.h` is included solely for the `Sleep` function, which is never called in the current code.
- **`square[0]` is wasted.** The array is sized 10 so positions map naturally to indices 1–9, leaving index 0 unused.

---

## Possible Improvements

- Replace `system("cls")` and `system("color")` with ANSI escape codes for cross-platform support.
- Add input validation to handle non-integer input gracefully (e.g., flush `stdin` on bad reads).
- Implement a single-player mode with a minimax AI opponent.
- Add a play-again prompt instead of exiting immediately after a game.
- Remove the unused `Sleep` import and `#include <windows.h>` if the colour feature is dropped.
- Replace the global `square[]` array with function parameters to improve encapsulation.

---

## License

This project is provided as-is for educational purposes. No license is currently specified — add one (e.g., MIT) if you intend to distribute the code.
