#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

struct Vector2D {
    double x, y;
};

double length(const Vector2D& v) {
    return sqrt(v.x * v.x + v.y * v.y);
}

double dotProduct(const Vector2D& v1, const Vector2D& v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

double angleBetween(const Vector2D& v1, const Vector2D& v2) {
    double dot = dotProduct(v1, v2);
    double len1 = length(v1);
    double len2 = length(v2);
    return acos(dot / (len1 * len2)) * 180.0 / M_PI;
}

Vector2D add(const Vector2D& v1, const Vector2D& v2) {
    return {v1.x + v2.x, v1.y + v2.y};
}

Vector2D subtract(const Vector2D& v1, const Vector2D& v2) {
    return {v1.x - v2.x, v1.y - v2.y};
}

bool areParallel(const Vector2D& v1, const Vector2D& v2) {
    return (v1.x * v2.y - v1.y * v2.x) == 0;
}

int main() {
    srand(time(0));

    Vector2D v1 = {rand() % 100, rand() % 100};
    Vector2D v2 = {rand() % 100, rand() % 100};
    Vector2D v3 = {rand() % 100, rand() % 100};

    std::cout << "Vector 1: (" << v1.x << ", " << v1.y << ")\n";
    std::cout << "Vector 2: (" << v2.x << ", " << v2.y << ")\n";
    std::cout << "Vector 3: (" << v3.x << ", " << v3.y << ")\n";

    std::cout << "Length of v1: " << length(v1) << "\n";
    std::cout << "Length of v2: " << length(v2) << "\n";
    std::cout << "Length of v3: " << length(v3) << "\n";

    std::cout << "Angle between v1 and v2: " << angleBetween(v1, v2) << " degrees\n";
    std::cout << "Angle between v1 and v3: " << angleBetween(v1, v3) << " degrees\n";
    std::cout << "Angle between v2 and v3: " << angleBetween(v2, v3) << " degrees\n";

    Vector2D sum12 = add(v1, v2);
    Vector2D sum13 = add(v1, v3);
    Vector2D sum23 = add(v2, v3);

    std::cout << "Sum of v1 and v2: (" << sum12.x << ", " << sum12.y << ")\n";
    std::cout << "Sum of v1 and v3: (" << sum13.x << ", " << sum13.y << ")\n";
    std::cout << "Sum of v2 and v3: (" << sum23.x << ", " << sum23.y << ")\n";

    Vector2D diff12 = subtract(v1, v2);
    Vector2D diff13 = subtract(v1, v3);
    Vector2D diff23 = subtract(v2, v3);

    std::cout << "Difference of v1 and v2: (" << diff12.x << ", " << diff12.y << ")\n";
    std::cout << "Difference of v1 and v3: (" << diff13.x << ", " << diff13.y << ")\n";
    std::cout << "Difference of v2 and v3: (" << diff23.x << ", " << diff23.y << ")\n";

    if (areParallel(v1, v2)) std::cout << "v1 and v2 are parallel\n";
    if (areParallel(v1, v3)) std::cout << "v1 and v3 are parallel\n";
    if (areParallel(v2, v3)) std::cout << "v2 and v3 are parallel\n";

    return 0;
}
