#ifndef UDKGLOBALDATA_H
#define UDKGLOBALDATA_H
#include <QImage>
#include <vector>
#include "udkTimeLine.h"

std::vector<udkParts> g_parts_vec;
std::vector<udkBone> g_bone_vec;
std::vector<QImage> g_image_vec;
std::vector<cv::Mat> g_image_vec;
udkTimeLine g_time_line;

#endif // UDKGLOBALDATA_H
