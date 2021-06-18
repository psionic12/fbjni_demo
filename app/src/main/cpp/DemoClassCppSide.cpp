#include "DemoClassCppSide.h"

namespace fbjni = facebook::jni;

fbjni::local_ref<fbjni::HybridClass<DemoClassCppSide>::jhybriddata> DemoClassCppSide::initHybrid(
        fbjni::alias_ref<jclass>) {
    return makeCxxInstance();
}

void DemoClassCppSide::registerNatives() {
    registerHybrid({
                           makeNativeMethod("initHybrid", DemoClassCppSide::initHybrid),
                           makeNativeMethod("getString", DemoClassCppSide::stringFromCpp),
                           makeNativeMethod("getAndSetInt", DemoClassCppSide::getAndSetInt),
                           makeNativeMethod("getObjectFromCpp", DemoClassCppSide::createJavaObj),
                           makeNativeMethod("sendObjectToCpp", DemoClassCppSide::getIntFromJavaObj),
                   });
}

std::string DemoClassCppSide::stringFromCpp() {
    return "hello from c++";
}

DemoClassCppSide::~DemoClassCppSide() {
    __android_log_write(ANDROID_LOG_INFO, "fbjni_test", "~DemoClassCppSide");
}

int DemoClassCppSide::getAndSetInt(int i) {
    return i + 1;
}

fbjni::local_ref<NormalCppClass> DemoClassCppSide::createJavaObj() {
    return NormalCppClass::create(3);
}

int DemoClassCppSide::getIntFromJavaObj(fbjni::alias_ref<NormalCppClass> jobj) {
    return jobj->getI();
}
