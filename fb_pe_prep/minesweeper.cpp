#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib>
//Create random board with mines in random places
//
//Create the board which is visible by user
//
//Play!!!
//

//Data structures:
//realBoard
//userBoard
//
//Step
//at each step check what is the content in real board.
//if it is mine, Game lost
//if it has adjacent mines then reveal the element
//if it has no adjacent mines then do DFS till element with adjacent mines found
//a

using namespace std;
#define BOARD_HEIGHT 9
#define BOARD_WIDTH 9

class Minesweeper {
private:
	vector<vector<int>> real_board;
	vector<vector<int>> user_board;
	pair<int, int> first_move;
public:
	void create_real_board() {
		real_board = vector<vector<int>>(BOARD_HEIGHT,
							vector<int>(BOARD_WIDTH, 0));
		srand(time(NULL));
		for (int i = 0; i < BOARD_HEIGHT; i++) {
			for (int j = 0; j < BOARD_WIDTH; j++) {
				if ((rand() % 5) == 4)
					real_board[i][j] = -1;
			}
		}

		if (real_board[first_move.first][first_move.second] == -1 ) {
			real_board[first_move.first][first_move.second] = 0;
		}
		//calculate adjacent mines

		for (int i = 0; i < BOARD_HEIGHT; i++) {
			for (int j = 0; j < BOARD_WIDTH; j++) {
				//index offsets
				if (real_board[i][j] == -1)
					continue;
				vector<vector<int>> idx_ofs = {{1, 1}, {1, 0}, {1, -1},
												{0, 1}, {0, -1},
												{-1, 1}, {-1, 0}, {-1, -1}};
				for (auto idx_of: idx_ofs) {
					int x = i + idx_of[0];
					int y = j + idx_of[1];
					if (x >= 0 && x < BOARD_HEIGHT && y >= 0 && y < BOARD_WIDTH) {
						if (real_board[x][y] == -1)
							real_board[i][j]++;
					}
				}
			}
		}
		//display board
		for (int i = 0; i < BOARD_HEIGHT; i++) {
			for (int j = 0; j < BOARD_WIDTH; j++) {
				cout<<real_board[i][j]<<endl;
			}
		}
	}

	void init_user_board () {
		
		user_board = vector<vector<int>>(BOARD_HEIGHT,
							vector<int>(BOARD_WIDTH, -2));
	}

	//take input position as input
	void play(pair<int, int> input) {
		//check if already visible
		int x = input.first;
		int y = input.second;
		if (user_board[x][y] == -2) {
			if (real_board[x][y] == -1) {

			}
		}
	}
};



int main () {
	Minesweeper m;
	m.first_move = make_pair(3, 4);
	m.create_real_board();
	
}
