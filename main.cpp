/*Made by @HassanIQ777 on 2024 Dec 19*/

#include <iostream>
#include <string>

using namespace std;

void printBoard(string BOARD[3][3]) {
  printf("----1---2---3---\n");
  printf("1 | %s | %s | %s |\n", BOARD[0][0].c_str(), BOARD[0][1].c_str(),
         BOARD[0][2].c_str());
  printf("2 | %s | %s | %s |\n", BOARD[1][0].c_str(), BOARD[1][1].c_str(),
         BOARD[1][2].c_str());
  printf("3 | %s | %s | %s |\n", BOARD[2][0].c_str(), BOARD[2][1].c_str(),
         BOARD[2][2].c_str());
  printf("----------------\n");
}

void clear_terminal() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

bool checkWin(string BOARD[3][3], string player) {
  // rows
  for (int i = 0; i < 3; ++i) {
    if (BOARD[i][0] == player && BOARD[i][1] == player &&
        BOARD[i][2] == player) {
      return true;
    }
  }

  // columns
  for (int i = 0; i < 3; ++i) {
    if (BOARD[0][i] == player && BOARD[1][i] == player &&
        BOARD[2][i] == player) {
      return true;
    }
  }

  // diagonals
  if (BOARD[0][0] == player && BOARD[1][1] == player && BOARD[2][2] == player) {
    return true;
  }
  if (BOARD[0][2] == player && BOARD[1][1] == player && BOARD[2][0] == player) {
    return true;
  }

  return false;
}
bool checkDraw(string BOARD[3][3]) {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (BOARD[i][j] == " ") {
        return false;
      }
    }
  }
  return true; // no empty cells = draw
}

int main() {
  srand(static_cast<unsigned int>(time(0)));
  string player = "X";
  string computer = "O";

  string BOARD[3][3] = {{" ", " ", " "}, {" ", " ", " "}, {" ", " ", " "}};

  bool running = true;
  while (running) {
    clear_terminal();
    printBoard(BOARD);

    if (checkWin(BOARD, player)) {
      cout << "Player wins!\n";
      break;
    } else if (checkWin(BOARD, computer)) {
      cout << "Computer wins!\n";
      break;
    } else if (checkDraw(BOARD)) {
      cout << "It's a draw!\n";
      break;
    }

    cout << "\nSelect cell: ";
    int col = 0, row = 0;
    cin >> col >> row;
    row--;
    col--;
    if (row < 0 || row >= 3 || col < 0 || col >= 3)
      continue;
    if (BOARD[col][row] == " ")
      BOARD[col][row] = player;

    int ccol = 0, crow = 0;
    bool computerMoved = false;

    for (int attempts = 0; attempts < 1000 && !computerMoved; ++attempts) {
      ccol = rand() % 3;
      crow = rand() % 3;
      if (BOARD[crow][ccol] == " ") {
        BOARD[crow][ccol] = computer;
        computerMoved = true;
      }
    }
  }
}