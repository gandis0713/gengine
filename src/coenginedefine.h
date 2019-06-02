#ifndef COENGINEDEFINE_H
#define COENGINEDEFINE_H

#include <QtCore/qglobal.h>

#if defined(GANDISENGINE_EXPORT)
#  define GANDISENGINE Q_DECL_EXPORT
#else
#  define GANDISENGINE Q_DECL_IMPORT
#endif

#endif // COENGINEDEFINE_H
