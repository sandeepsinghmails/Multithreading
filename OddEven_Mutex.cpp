// Print Odd & Even Numbers Using Mutex
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex

std::mutex mtx;

void print (int numb, char ch)
{
  for (int even=2, odd=1; even<=numb && odd<numb; )
  {
      if (ch == 'e')
      {
          mtx.lock();
          std::cout << even << std::endl;
          even += 2;
          mtx.unlock();
      }
      else if (ch == 'o')
      {
          mtx.lock();
          std::cout << odd << std::endl;
          odd += 2;
          mtx.unlock();
      }
  }
}

int main ()
{
  std::thread th1 (print,30,'o');
  std::thread th2 (print,30,'e');

  th1.join();
  th2.join();

  return 0;
}
