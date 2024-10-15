#include <iostream>
#include <vector>
#include <chrono>

struct PointAoS {
    float x, y, z;
};

struct PointSoA {
    std::vector<float> x;
    std::vector<float> y;
    std::vector<float> z;
};

void processAoS(const std::vector<PointAoS>& points) {
    for (const auto& p : points) {
        float sum = p.x + p.y + p.z;
    }
}

void processSoA(const PointSoA& points) {
    for (size_t i = 0; i < points.x.size(); ++i) {
        float sum = points.x[i] + points.y[i] + points.z[i];
    }
}

int main() {
    const size_t numPoints = 1000000;

    // Create AoS
    std::vector<PointAoS> pointsAoS(numPoints);
    for (size_t i = 0; i < numPoints; ++i) {
        pointsAoS[i] = {static_cast<float>(i), static_cast<float>(i), static_cast<float>(i)};
    }

    // Benchmark AoS
    auto start = std::chrono::high_resolution_clock::now();
    processAoS(pointsAoS);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationAoS = end - start;
    std::cout << "AoS processing time: " << durationAoS.count() << " seconds" << std::endl;

    // Create SoA
    PointSoA pointsSoA;
    pointsSoA.x.resize(numPoints);
    pointsSoA.y.resize(numPoints);
    pointsSoA.z.resize(numPoints);
    for (size_t i = 0; i < numPoints; ++i) {
        pointsSoA.x[i] = static_cast<float>(i);
        pointsSoA.y[i] = static_cast<float>(i);
        pointsSoA.z[i] = static_cast<float>(i);
    }

    // Benchmark SoA
    start = std::chrono::high_resolution_clock::now();
    processSoA(pointsSoA);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationSoA = end - start;
    std::cout << "SoA processing time: " << durationSoA.count() << " seconds" << std::endl;

    return 0;
}
