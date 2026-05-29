#include "Grid.h"
#include <cmath>

Grid::Grid(float xmin, float xmax, float ymin, float ymax, float step)
    : xmin(xmin), xmax(xmax), ymin(ymin), ymax(ymax), step(step)
{
    generate();
}

void Grid::generate()
{
    vertices.clear();
    indices.clear();

    int xSize = (xmax - xmin) / step + 1;
    int ySize = (ymax - ymin) / step + 1;


    // vertices
    for (float y = ymin; y <= ymax; y += step) {
        for (float x = xmin; x <= xmax; x += step) {
            vertices.push_back(x);
            vertices.push_back(y);
            //  vertices.push_back(0.0f);
            vertices.push_back( std::abs( x * x + y ) );
        }
    }

    // indices
    for (int y = 0; y < ySize - 1; y++) {
        for (int x = 0; x < xSize - 1; x++) {
            int i = y * xSize + x;
            indices.push_back(i);
            indices.push_back(i + 1);
            indices.push_back(i);
            indices.push_back(i + xSize);
        }
    }
    for (int i = 0; i < ySize - 1; i++) {
        int a = (i + 1) * xSize - 1;
        indices.push_back(a);
        indices.push_back(a + xSize);
    }
    for (int i = 0; i < xSize - 1; i++) {
        int a = (ySize - 1) * xSize;
        indices.push_back(a + i);
        indices.push_back(a + i + 1);
    }
}
