#include <iostream>
#include <cmath>
using namespace std;


struct Point {
    double x;
    double y;
};

void Banner() {
    cout << "Welcome to the Cartesian coordinate Area of Triangle Program" << endl;
    cout << "Enter the two points p1(x1, y1) and p2(x2, y2)" << endl << endl;
}

void InputPoints(Point& p1, Point& p2) {
    cout << "Enter x1 and y1: ";
    cin >> p1.x >> p1.y;

    cout << "Enter x2 and y2: ";
    cin >> p2.x >> p2.y;
}

double Distance(const Point& p1, const Point& p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

double SemiPerimeter(double a, double b, double c) {
    return (a + b + c) / 2.0;
}

double AreaOfTriangle(const Point& p1, const Point& p2, double c) {
    double a = fabs(p2.x - p1.x);  // side parallel to y-axis
    double b = fabs(p2.y - p1.y);  // side parallel to x-axis
    double s = SemiPerimeter(a, b, c);
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

void PrintResult(double a, double b, double c, double area) {
    cout << "\nResults:\n";
    cout << "Side a (parallel to y-axis): " << a << endl;
    cout << "Side b (parallel to x-axis): " << b << endl;
    cout << "Side c (distance between points): " << c << endl;
    cout << "Area of Triangle: " << area << endl;
}

int main() {
    Point p1 = {0, 0}, p2 = {0, 0};
    double distance, area;
    char choice;

    do {
        Banner();
        InputPoints(p1, p2);

        distance = Distance(p1, p2);
        area = AreaOfTriangle(p1, p2, distance);

        double a = fabs(p2.x - p1.x);
        double b = fabs(p2.y - p1.y);

        PrintResult(a, b, distance, area);

        cout << "\nDo you want to calculate another triangle? (y/n): ";
        cin >> choice;
        cout << endl;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
