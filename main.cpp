#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

int main() {
    const size_t N = 10'000'000; // 10 million values
    std::vector<int> data;
    data.reserve(N);

    // Generate random values
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, 1'000'000);

    for (size_t i = 0; i < N; ++i) {
        data.push_back(dist(rng));
    }

    std::cout << "Sorting started..." << std::endl;

    auto start = std::chrono::high_resolution_clock::now();

    // Sort in descending order
    std::sort(data.begin(), data.end(), std::greater<int>());

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Sorting completed in " << elapsed.count() << " seconds\n";

    // Print first 10 results
    for (int i = 0; i < 10; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
