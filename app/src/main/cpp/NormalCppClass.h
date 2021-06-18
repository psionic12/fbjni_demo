#ifndef FBJNI_DEMO_APP_SRC_MAIN_CPP_NORMALCPPCLASS_H_
#define FBJNI_DEMO_APP_SRC_MAIN_CPP_NORMALCPPCLASS_H_
#include <fbjni/fbjni.h>
namespace fbjni = facebook::jni;
class NormalCppClass : public fbjni::JavaClass<NormalCppClass> {
 public:
  static constexpr auto kJavaDescriptor = "Lcom/example/fbjni_demo/NormalJavaClass;";
  static fbjni::local_ref<NormalCppClass> create(int i) {
    // Constructor is looked up by argument types at *runtime*.
    return newInstance(i);
  }
  int getI() {
    static auto method = getClass()->getMethod<int()>("getI");
    return method(self());
  }
};

#endif //FBJNI_DEMO_APP_SRC_MAIN_CPP_NORMALCPPCLASS_H_
