#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
vector<string> picture;
bool visited[100][100];

void dfs(int x, int y, char color, bool isColorWeakness) {
    if (x < 0 || x >= N || y < 0 || y >= N || visited[x][y]) {
        return;
    }

    if (isColorWeakness) {
        if (color == 'R' || color == 'G') {
            if (picture[x][y] == 'B') {
                return;
            }
        }
    }

    visited[x][y] = true;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny] && picture[nx][ny] == color) {
            dfs(nx, ny, color, isColorWeakness);
        }
    }
}

pair<int, int> countAreas(bool isColorWeakness) {
    memset(visited, false, sizeof(visited));
    int count = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                dfs(i, j, picture[i][j], isColorWeakness);
                count++;
            }
        }
    }

    return {count, 0};
}

int main() {
    cin >> N;

    picture.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> picture[i];
    }

    pair<int, int> normalCount = countAreas(false);
    pair<int, int> colorWeaknessCount = countAreas(true);

    cout << normalCount.first << " " << colorWeaknessCount.first << endl;

    return 0;
}
