#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
 public:
  Brain();
  Brain(Brain const& src);
  ~Brain();

  Brain& operator=(Brain const& rhs);

  void showIdeas() const;
  void setIdea(std::string& idea);

 private:
  static const size_t k_idea_max_size = 100;

  size_t index;
  size_t idea_size;
  std::string ideas[k_idea_max_size];
};

#endif /* *********************************************************** BRAIN_H \
        */