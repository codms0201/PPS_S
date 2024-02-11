#include <iostream>
#include <unordered_set>

using namespace std;

int board[5][5];
unordered_set<int> uniqueNumbers;

void dfs(int x, int y, int depth, int currentNumber) {
    if (depth == 6) {
        uniqueNumbers.insert(currentNumber);
        return;
    }

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {
            dfs(nx, ny, depth + 1, currentNumber * 10 + board[nx][ny]);
        }
    }
}

int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            dfs(i, j, 1, board[i][j]);
        }
    }

    cout << uniqueNumbers.size() << endl;

    return 0;
}
