#include <iostream>
#include <cmath>

using namespace std;

void drawCircle(int radius) {
    for (int y = -radius; y <= radius; ++y) {
        for (int x = -radius; x <= radius; ++x) {
            double distance = sqrt(x * x + y * y);
            if (abs(distance - radius) < 0.5) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int radius;

    cout << "Enter the radius of the circle: ";
    cin >> radius;

    drawCircle(radius);

    return 0;
}
