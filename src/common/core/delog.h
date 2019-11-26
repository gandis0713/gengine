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
    qDebug() \

#define LogBaseName \
    qDebug() << __FUNCTION__ \

#define TextLog(text) \
    LogBase CText(text)

#define TextLogName(text) \
    LogBaseName CText(text)

#define ValueLog(value) \
    TextLog(value) Value(value)

#define ValueLogName(value) \
    TextLogName(value) Value(value)

#define ValueTextLog(text, value) \
    TextLog(text) Value(value)

#define ValueTextLogName(text, value) \
    TextLogName(text) Value(value)

#define Vec2(vec) \
    CText(vec2) << vec[0] << ", " << vec[1] \

#define Vec3(vec) \
    CText(vec3) << vec[0] << ", " << vec[1] << ", " << vec[2]\

#define Vec2Log(vec) \
    TextLogName(vec) LineSep \
    Vec2(vec)

#define Vec3Log(vec) \
    TextLogName(vec) LineSep \
    Vec3(vec)

#define Vec2TextLog(text, vec) \
    TextLogName(text) LineSep \
    Vec2(vec)

#define Vec3TextLog(text, vec) \
    TextLogName(text) LineSep \
    Vec3(vec)

#endif // DELOG_H
