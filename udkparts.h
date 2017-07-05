#ifndef UDKPARTS_H
#define UDKPARTS_H
#include "udkslerpcontainer.h"

class udkParts
{
public:
    udkParts();
    udkPartsPattern _pattern;
    udkSlerpContainer<int,Vector3> _position;
    udkSlerpContainer<int,Vector3> _center_pos;
    udkSlerpContainer<int,Vector3> _rotate_in_euler;
    udkSlerpContainer<int,Vector3> _scale;
    Vector3 _parts_div_num;///<パーツ画像のXYZのそれぞれのパターン数　Zは使わない
    udkMesh _mesh;
};

#endif // UDKPARTS_H
