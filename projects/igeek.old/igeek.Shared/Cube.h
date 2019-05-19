#ifndef __HelloCubeNative__main__
#define __HelloCubeNative__main__

#include <stdio.h>
#ifdef __ANDROID__
#include <GLES/gl.h>
#elif __APPLE__
#include <OpenGLES/ES1/gl.h>
#endif

#include <graphics/nanovg.h>

void Cube_setupGL(FPN width, FPN height);
void Cube_tearDownGL();
void Cube_update();
void Cube_prepare();
void Cube_draw();

#endif /* defined(__HelloCubeNative__main__) */
