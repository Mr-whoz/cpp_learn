#include <iostream>
#include <memory>
#include <string>

class Brid {
 public:
  virtual ~Brid() {}
  virtual void Cry(const double decibel) { std::cout << "cry as default decibel" << std::endl; }
};

class Duck : public Brid {
 public:
  ~Duck() override {}
  virtual void Cry(const int decibel) { std::cout << "cry as " << decibel << " decibel" << std::endl; }
};

int main() {
  std::unique_ptr<Brid> duck = std::make_unique<Duck>();
  duck->Cry(1);
  return 0;
}