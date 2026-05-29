/// architecture.h

#ifndef ARCHITECTURE_H
#define ARCHITECTURE_H

#ifdef ARCHITECTURE_EXPORTS
#define CORE_API __declspec(dllexport)
#else
#define CORE_API __declspec(dllimport)
#endif

// INCLUDES
#include"vector4.h"
#include"matscreen.h"
#include"color4.h"
#include"shaderbasic.h"


#endif // ARCHITECTURE_H