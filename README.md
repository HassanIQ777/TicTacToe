# TicTacToe

> *"One of my oldest projects"*

A terminal Tic Tac Toe game written in C++ on December 19, 2024. You are `X`. The computer is `O`. The computer's strategy is to pick a random empty cell and hope for the best.

```
----1---2---3---
1 |   |   |   |
2 |   |   |   |
3 |   |   |   |
----------------
```

---

## Gameplay

You and the computer take turns on a 3×3 grid. You go first every time — the computer doesn't ask. First to get three in a row (horizontally, vertically, or diagonally) wins. Fill the board with no winner and it's a draw.

The terminal clears between turns. Either it's immersive, or it makes scrolling back to look at the board impossible.

---

## Controls

Input is a column-then-row pair (space-separated), matching the board's labeled axes:

```
Select cell: 2 1     ← column 2, row 1
```

```
----1---2---3---
1 |   | X |   |
2 |   |   |   |
3 |   |   |   |
----------------
```

Out-of-bounds input (`< 1` or `> 3`) is silently ignored and the turn is skipped. Entering an already-occupied cell overwrites... nothing, the check is there, it just quietly moves on. The computer then gets a free move. Choose wisely.

---

## The AI

The computer (`O`) picks its move by generating a random `(col, row)` pair and checking if the cell is empty. If it's taken, it tries again. It will attempt this up to **1000 times** before giving up. On a non-full board, statistically it finds a cell within a handful of tries. On a nearly-full board it gets a little sweaty.

This means the computer:
- Cannot block you
- Cannot set up a win
- Cannot do anything intentional at all
- Will still occasionally beat you because that's how `rand()` works sometimes

---

## Building

No dependencies beyond `g++` with C++20 support and `make`.

```bash
git clone https://github.com/HassanIQ777/TicTacToe
cd TicTacToe
make
```

```bash
# Release build (default) — -O2 -march=native -flto
make

# Debug build — ASan + UBSan, -Og, -DDEBUG
make debug

# Build and run immediately
make run

# Clean build artifacts ("Nothing but echoes remain...")
make clean
```

The binary lands at `./tictactoe`.

---

## Running

```bash
./tictactoe
```

Works anywhere with a terminal and a C++ compiler. No SDL2, no ncurses, no nothing. `printf` and `system("clear")` are the entire rendering stack.

---

## Project Structure

```
TicTacToe/
├── main.cpp     # 110 lines — board, win check, draw check, game loop, AI
├── Makefile     # 83 lines
├── .gitignore
└── LICENSE      # MIT
```

---

## License

MIT — play freely.

---

*Made by [HassanIQ777](https://github.com/HassanIQ777) — Dec 19, 2024*