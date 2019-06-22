#ifndef DEFINE_H
#define DEFINE_H

#include <sstream>

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"


typedef std::string       GString;

typedef char              Gchar;
typedef unsigned char     Guchar;
typedef int               Gint;
typedef unsigned int      Guint;
typedef short             Gshort;
typedef unsigned short    Gushort;
typedef double            Gdouble;
typedef float             Gfloat;

typedef glm::mat4         Gmat4;

#ifdef WIN32
typedef wchar_t           Gwchar;
#endif

#endif // DEFINE_H
