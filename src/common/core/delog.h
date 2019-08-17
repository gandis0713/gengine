#ifndef DELOG_H
#define DELOG_H

#include <QDebug>

#define LineSep \
    << "\n" \

#define CText(text) \
    << "[" << #text << "]" \

#define Value(value) \
    << value

#define LogBase \
    qDebug() << __FUNCTION__ \

#define TextLog(text) \
    LogBase CText(text)

#define ValueLog(value) \
    TextLog(value) Value(value)

#define ValueTextLog(text, value) \
    TextLog(text) Value(value)

#define Vec2(vec) \
    CText(vec2) << vec[0] << ", " << vec[1] \

#define Vec3(vec) \
    CText(vec3) << vec[0] << ", " << vec[1] << ", " << vec[2]\

#define Vec2Log(vec) \
    TextLog(vec) LineSep \
    Vec2(vec)

#define Vec3Log(vec) \
    TextLog(vec) LineSep \
    Vec3(vec)

#define Vec2TextLog(text, vec) \
    TextLog(text) LineSep \
    Vec2(vec)

#define Vec3TextLog(text, vec) \
    TextLog(text) LineSep \
    Vec3(vec)

#endif // DELOG_H
