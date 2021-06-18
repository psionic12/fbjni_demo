#ifndef FBJNI_DEMO_APP_SRC_MAIN_CPP_DEMOCLASSCPPSIDE_H_
#define FBJNI_DEMO_APP_SRC_MAIN_CPP_DEMOCLASSCPPSIDE_H_
#include <fbjni/fbjni.h>
#include <android/log.h>
#include "NormalCppClass.h"

namespace fbjni = facebook::jni;

class DemoClassCppSide : public fbjni::HybridClass<DemoClassCppSide> {
 public:
  static constexpr auto kJavaDescriptor = "Lcom/example/fbjni_demo/DemoClassJavaSide;";
  static fbjni::local_ref<jhybriddata> initHybrid(fbjni::alias_ref<jclass>);
  static void registerNatives();
  ~DemoClassCppSide() override;
  std::string stringFromCpp();
  int getAndSetInt(int i);
  fbjni::local_ref<NormalCppClass> createJavaObj();
  int getIntFromJavaObj(fbjni::alias_ref<NormalCppClass> jobj);
};

#endif //FBJNI_DEMO_APP_SRC_MAIN_CPP_DEMOCLASSCPPSIDE_H_
