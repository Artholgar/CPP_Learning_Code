#pragma once
#include <iostream>
#include <utility>
#include <vector>

using Vertex = std::pair<int, int>;

class Polygon
{
    friend std::ostream& operator<<(std::ostream& stream, const Polygon& polygon);

public:
    const Vertex& get_vertex(int index) const;

    void add_vertex(int x, int y);

private:
    std::vector<Vertex> _vertices;
};