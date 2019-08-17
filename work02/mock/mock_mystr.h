#include "gmock/gmock.h"

class Mystr {
public:
Mystr(void){};
virtual ~Mystr(void){};
virtual int str_analyze(const char* str, int max) = 0;
};

class MockMystr : public Mystr {
 public:
  MockMystr(){}
  ~MockMystr(){}
  MOCK_METHOD2(str_analyze,
      int(const char* str, int max));

};

extern MockMystr* mystr_mock;

extern "C" int str_analyze(const char* str, int max)
{
    int ret = mystr_mock->str_analyze(str, max);
    return ret;
}


