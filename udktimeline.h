#ifndef UDKTIMELINE_H
#define UDKTIMELINE_H
#include "udkslerpcontainer.h"
#include "udkJoint.h"

struct udkTimeLineItem
{
    bool _visibility;

    int _start_frame;
    int _frame_length;

    udkTimeLineItem();
};

struct udkTimeLineItemJoint:public udkTimeLineItem, public udkSlerpContainer<udkJoint>
{

};

class udkTimeLinelayer
{
public:
    udkTimeLinelayer();
    std::vector<sp<udkTimeLineItem>> _layer;

};


class udkTimeLine
{
public:
    udkTimeLine();
    std::vector<sp<udkTimeLinelayer>> _layer;

};

#endif // UDKTIMELINE_H
