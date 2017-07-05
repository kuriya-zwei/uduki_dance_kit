#ifndef UDKBONE_H
#define UDKBONE_H


class udkJoint;

/***
 * @brief 骨を表すクラス　ジョイントを二つ指定することで表現
 */
class udkBone
{
public:
    udkBone();

    udkJoint* _from;
    udkJoint* _to;
};

#endif // UDKBONE_H
