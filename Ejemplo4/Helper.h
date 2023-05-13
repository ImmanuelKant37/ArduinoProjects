#ifndef Helper_h
#define Helper_h

#include <Arduino.h>

class Helper {
public:
  Helper();

  template <typename T>
  void print(const T& value) {
    Serial.println(value);
  }

  template <typename T>
  void print(const T* arr, size_t size) {
    for (size_t i = 0; i < size; ++i) {
      Serial.print(arr[i]);
      Serial.print(' ');
    }
    Serial.println();
  }

  void print(bool value) {
    Serial.println(value ? "true" : "false");
  }

  void print(const char* arr) {
    Serial.println(arr);
  }
};

#endif
