#ifndef UDKMESH_H
#define UDKMESH_H

struct Vertex
{
    Vector3 _pos;
    Vector2 _uv;
    int _tex;
    float _w;
};

class udkMesh
{
public:
    udkMesh();
private:
    std::vector<Vertex> _vertex;
};

#endif // UDKMESH_H
