#include <fbjni/fbjni.h>

#include "DemoClassCppSide.h"
extern "C" JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved) {
  return facebook::jni::initialize(vm, [] {
    DemoClassCppSide::registerNatives();
  });
}