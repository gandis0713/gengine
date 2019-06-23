#ifndef DEFINE_H
#define DEFINE_H

#include <sstream>

typedef std::string       GString;

typedef char              Gchar;
typedef unsigned char     Guchar;
typedef int               Gint;
typedef unsigned int      Guint;
typedef short             Gshort;
typedef unsigned short    Gushort;
typedef double            Gdouble;
typedef float             Gfloat;
typedef bool              Gbool;

#ifdef WIN32
typedef wchar_t           Gwchar;
#endif

#endif // DEFINE_H
