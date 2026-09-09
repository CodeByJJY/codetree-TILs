#include <iostream>

using namespace std;

const int OFFSET = 100;
int grid[205][205];

int main() {
    // 빠른 입출력 설정
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    for (int k = 0; k < N; k++) {
        int x, y;
        cin >> x >> y;

        // (x, y)를 좌측 하단으로 하는 8x8 크기의 색종이 칠하기
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                grid[x + i + OFFSET][y + j + OFFSET] = 1;
            }
        }
    }

    // 칠해진 영역(넓이) 집계
    int total_area = 0;
    for (int i = 0; i < 205; i++) {
        for (int j = 0; j < 205; j++) {
            if (grid[i][j] == 1) {
                total_area++;
            }
        }
    }

    cout << total_area << "\n";

    return 0;
}