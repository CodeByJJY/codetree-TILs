#include <iostream>
#include <algorithm>

using namespace std;

const int OFFSET = 1000;
int grid[2005][2005];

int main() {
    // 빠른 입출력 설정
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x11, y11, x12, y12;
    int x21, y21, x22, y22;

    if (!(cin >> x11 >> y11 >> x12 >> y12)) return 0;
    cin >> x21 >> y21 >> x22 >> y22;

    // 1. 첫 번째 직사각형 칠하기 (1로 표시)
    for (int x = x11; x < x12; x++) {
        for (int y = y11; y < y12; y++) {
            grid[x + OFFSET][y + OFFSET] = 1;
        }
    }

    // 2. 두 번째 직사각형으로 덮인 부분 지우기 (0으로 변경)
    for (int x = x21; x < x22; x++) {
        for (int y = y21; y < y22; y++) {
            grid[x + OFFSET][y + OFFSET] = 0;
        }
    }

    // 3. 남아있는 잔해의 최소/최대 좌표 찾기
    int min_x = 2005, max_x = -1;
    int min_y = 2005, max_y = -1;
    bool has_debris = false;

    for (int x = 0; x < 2005; x++) {
        for (int y = 0; y < 2005; y++) {
            if (grid[x][y] == 1) {
                has_debris = true;
                min_x = min(min_x, x);
                max_x = max(max_x, x);
                min_y = min(min_y, y);
                max_y = max(max_y, y);
            }
        }
    }

    // 4. 결과 계산 및 출력
    if (!has_debris) {
        cout << 0 << "\n";
    } else {
        int width = max_x - min_x + 1;
        int height = max_y - min_y + 1;
        cout << width * height << "\n";
    }

    return 0;
}