#include <iostream>
#include <string>

std::string hello () {
      for (int i = 0; i < 10; ++i) {
            std::cout << "\e[" << i << ";3" << i << "mHello world!\e[m" << std::endl;
      }

      return "You shall not pass my google test!";
}

int fourer () {
      return 4;
}
