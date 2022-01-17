#ifndef KAREN_HPP
#define KAREN_HPP

#include <iostream>
#include <string>

class Karen {
 public:
  Karen();
  ~Karen();

  void complain(std::string level);

 private:
  void debug(void);
  void info(void);
  void warning(void);
  void error(void);
  void nothing(void);
};

typedef void (Karen::*t_karen_func)(void);

#endif /* *********************************************************** KAREN_H \
        */