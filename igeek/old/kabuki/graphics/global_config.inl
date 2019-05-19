typedef double FPN;
#define NANOVG_GLES2_IMPLEMENTATION
#include "nanovg_gl.h"

#ifdef __ANDROID__
#include <GLES/gl.h>
#elif __APPLE__
#include <OpenGLES/ES1/gl.h>
#endif
