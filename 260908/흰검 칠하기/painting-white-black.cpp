#include <iostream>
#include <vector>

using namespace std;

const int MAX_POS = 200005;
const int OFFSET = 100000;

struct Tile {
    int white_cnt = 0;
    int black_cnt = 0;
    int color = 0; // 0: None, 1: White, 2: Black, 3: Gray
};

Tile tiles[MAX_POS];

int main() {
    // 빠른 입출력 설정
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    int curr = OFFSET; // 시작 위치

    for (int i = 0; i < N; i++) {
        int x;
        char dir;
        cin >> x >> dir;

        if (dir == 'L') {
            // 왼쪽으로 x칸 (현재 위치 포함)
            for (int k = 0; k < x; k++) {
                int pos = curr - k;
                tiles[pos].white_cnt++;
                
                // 회색 조건 체크 (흰색 >= 2 && 검은색 >= 2)
                if (tiles[pos].white_cnt >= 2 && tiles[pos].black_cnt >= 2) {
                    tiles[pos].color = 3;
                } else if (tiles[pos].color != 3) {
                    tiles[pos].color = 1; // 흰색
                }
            }
            curr = curr - x + 1; // 마지막으로 칠한 위치로 이동
        } else if (dir == 'R') {
            // 오른쪽으로 x칸 (현재 위치 포함)
            for (int k = 0; k < x; k++) {
                int pos = curr + k;
                tiles[pos].black_cnt++;
                
                // 회색 조건 체크
                if (tiles[pos].white_cnt >= 2 && tiles[pos].black_cnt >= 2) {
                    tiles[pos].color = 3;
                } else if (tiles[pos].color != 3) {
                    tiles[pos].color = 2; // 검은색
                }
            }
            curr = curr + x - 1; // 마지막으로 칠한 위치로 이동
        }
    }

    // 결과 집계
    int white_ans = 0, black_ans = 0, gray_ans = 0;
    for (int i = 0; i < MAX_POS; i++) {
        if (tiles[i].color == 1) white_ans++;
        else if (tiles[i].color == 2) black_ans++;
        else if (tiles[i].color == 3) gray_ans++;
    }

    cout << white_ans << " " << black_ans << " " << gray_ans << "\n";

    return 0;
}