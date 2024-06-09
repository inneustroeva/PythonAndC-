#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

struct Vector3D {
    double x, y, z;
};

double length(const Vector3D& v) {
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

double dotProduct(const Vector3D& v1, const Vector3D& v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

Vector3D crossProduct(const Vector3D& v1, const Vector3D& v2) {
    return {
        v1.y * v2.z - v1.z * v2.y,
        v1.z * v2.x - v1.x * v2.z,
        v1.x * v2.y - v1.y * v2.x
    };
}

double angleBetween(const Vector3D& v1, const Vector3D& v2) {
    double dot = dotProduct(v1, v2);
    double len1 = length(v1);
    double len2 = length(v2);
    return acos(dot / (len1 * len2)) * 180.0 / M_PI;
}

Vector3D add(const Vector3D& v1, const Vector3D& v2) {
    return {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
}

Vector3D subtract(const Vector3D& v1, const Vector3D& v2) {
    return {v1.x - v2.x, v1.y - v2.y, v1.z - v2.z};
}

bool areParallel(const Vector3D& v1, const Vector3D& v2) {
    Vector3D cross = crossProduct(v1, v2);
    return (cross.x == 0 && cross.y == 0 && cross.z == 0);
}

double mixedProduct(const Vector3D& v1, const Vector3D& v2, const Vector3D& v3) {
    Vector3D cross = crossProduct(v2, v3);
    return dotProduct(v1, cross);
}

int main() {
    srand(time(0));

    Vector3D v1 = {rand() % 100, rand() % 100, rand() % 100};
    Vector3D v2 = {rand() % 100, rand() % 100, rand() % 100};
    Vector3D v3 = {rand() % 100, rand() % 100, rand() % 100};

    std::cout << "Vector 1: (" << v1.x << ", " << v1.y << ", " << v1.z << ")\n";
    std::cout << "Vector 2: (" << v2.x << ", " << v2.y << ", " << v2.z << ")\n";
    std::cout << "Vector 3: (" << v3.x << ", " << v3.y << ", " << v3.z << ")\n";

    std::cout << "Length of v1: " << length(v1) << "\n";
    std::cout << "Length of v2: " << length(v2) << "\n";
    std::cout << "Length of v3: " << length(v3) << "\n";

    std::cout << "Angle between v1 and v2: " << angleBetween(v1, v2) << " degrees\n";
    std::cout << "Angle between v1 and v3: " << angleBetween(v1, v3) << " degrees\n";
    std::cout << "Angle between v2 and v3: " << angleBetween(v2, v3) << " degrees\n";

    Vector3D sum12 = add(v1, v2);
    Vector3D sum13 = add(v1, v3);
    Vector3D sum23 = add(v2, v3);

    std::cout << "Sum of v1 and v2: (" << sum12.x << ", " << sum12.y << ", " << sum12.z << ")\n";
    std::cout << "Sum of v1 and v3: (" << sum13.x << ", " << sum13.y << ", " << sum13.z << ")\n";
    std::cout << "Sum of v2 and v3: (" << sum23.x << ", " << sum23.y << ", " << sum23.z << ")\n";

    Vector3D diff12 = subtract(v1, v2);
    Vector3D diff13 = subtract(v1, v3);
    Vector3D diff23 = subtract(v2, v3);

    std::cout << "Difference of v1 and v2: (" << diff12.x << ", " << diff12.y << ", " << diff12.z << ")\n";
    std::cout << "Difference of v1 and v3: (" << diff13.x << ", " << diff13.y << ", " << diff13.z << ")\n";
    std::cout << "Difference of v2 and v3: (" << diff23.x << ", " << diff23.y << ", " << diff23.z << ")\n";

    if (areParallel(v1, v2)) std::cout << "v1 and v2 are parallel\n";
    if (areParallel(v1, v3)) std::cout << "v1 and v3 are parallel\n";
    if (areParallel(v2, v3)) std::cout << "v2 and v3 are parallel\n";

    double mixed = mixedProduct(v1, v2, v3);
    std::cout << "Mixed product of v1, v2 and v3: " << mixed << "\n";
    if (mixed != 0) {
        std::cout << "Vectors do not lie in the same plane\n";
    } else {
        std::cout << "Vectors lie in the same plane\n";
    }

    return 0;
}
