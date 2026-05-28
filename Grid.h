#pragma once
#include <vector>

class Grid {
public:
    std::vector<float> vertices;
    std::vector<int> indices;

    float xmin, xmax, ymin, ymax, step;

    Grid(float xmin, float xmax, float ymin, float ymax, float step);
    void generate();
};
