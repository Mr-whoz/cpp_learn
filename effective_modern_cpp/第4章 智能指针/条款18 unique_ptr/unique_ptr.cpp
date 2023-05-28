#include <iostream>
#include <memory>
/*
用处：

*/
int main() {
  std::shared_ptr<int> sp = std::make_shared<int>(2);
  std::cout << sp.use_count() << std::endl;  // 1
  std::shared_ptr<int> sp_copy = sp;
  std::cout << sp.use_count() << std::endl;  // 2
  std::weak_ptr<int> wp = sp;
  std::cout << sp.use_count() << std::endl;  // 2
  auto lock_p = wp.lock();                   // lock产生一个shared_ptr
  std::cout << sp.use_count() << std::endl;  // 3
  std::cout << wp.expired() << std::endl;    // 0
  sp.reset();
  sp_copy.reset();
  lock_p.reset();
  std::cout << wp.expired() << std::endl;  // 1
  auto lock_p2 = wp.lock();

  std::cout << (lock_p2 == nullptr) << std::endl;  // 1
  return 0;
}
