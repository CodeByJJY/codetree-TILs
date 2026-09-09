#include <iostream>
#include <algorithm>

using namespace std;

struct Rect {
    int x1, y1, x2, y2;

    // 사각형 단독 넓이
    int area() const {
        return (x2 - x1) * (y2 - y1);
    }
};

// 두 사각형 r1과 r2의 겹치는 넓이를 구하는 함수
int get_overlap_area(const Rect& r1, const Rect& r2) {
    int overlap_x = max(0, min(r1.x2, r2.x2) - max(r1.x1, r2.x1));
    int overlap_y = max(0, min(r1.y2, r2.y2) - max(r1.y1, r2.y1));
    return overlap_x * overlap_y;
}

int main() {
    // 빠른 입출력 설정
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Rect A, B, M;
    if (!(cin >> A.x1 >> A.y1 >> A.x2 >> A.y2)) return 0;
    cin >> B.x1 >> B.y1 >> B.x2 >> B.y2;
    cin >> M.x1 >> M.y1 >> M.x2 >> M.y2;

    // A와 B가 M과 겹치고 남아있는 넓이 계산
    int rem_A = A.area() - get_overlap_area(A, M);
    int rem_B = B.area() - get_overlap_area(B, M);

    cout << rem_A + rem_B << "\n";

    return 0;
}