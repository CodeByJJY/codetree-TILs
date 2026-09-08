#include <iostream>
#include <vector>

using namespace std;

const int MAX_POS = 200005;
const int OFFSET = 100000;

// 0: 회색(기본), 1: 흰색, 2: 검은색
int tiles[MAX_POS];

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
            // 현재 위치 포함 왼쪽으로 x칸 흰색(1)으로 뒤집기
            for (int k = 0; k < x; k++) {
                tiles[curr - k] = 1;
            }
            curr = curr - x + 1; // 마지막 위치로 이동
        } else if (dir == 'R') {
            // 현재 위치 포함 오른쪽으로 x칸 검은색(2)으로 뒤집기
            for (int k = 0; k < x; k++) {
                tiles[curr + k] = 2;
            }
            curr = curr + x - 1; // 마지막 위치로 이동
        }
    }

    // 결과 집계
    int white_ans = 0, black_ans = 0;
    for (int i = 0; i < MAX_POS; i++) {
        if (tiles[i] == 1) white_ans++;
        else if (tiles[i] == 2) black_ans++;
    }

    cout << white_ans << " " << black_ans << "\n";

    return 0;
}