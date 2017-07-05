#ifndef UDKJOINT_H
#define UDKJOINT_H


class udkJoint
{
public:
    udkJoint();
    Vector3 _position;///<このジョイントの位置
    Vector3 _rotate_in_euler;///<オイラー角でのこのジョイントの回転角
};

#endif // UDKJOINT_H
