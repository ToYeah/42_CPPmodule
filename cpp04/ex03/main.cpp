#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main() {
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  ICharacter* me = new Character("me");
  AMateria* tmp;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);
  ICharacter* bob = new Character("bob");
  me->use(0, *bob);
  me->use(1, *bob);

  delete bob;
  delete me;
  delete src;

  std::cout << "\n////////////////////////////////\n" << std::endl;

  IMateriaSource* materiaSrc = new MateriaSource();
  materiaSrc->learnMateria(new Ice());
  materiaSrc->learnMateria(new Cure());
  Character* sephiroth = new Character("sephiroth");

  sephiroth->equip(materiaSrc->createMateria("ice"));
  sephiroth->equip(materiaSrc->createMateria("cure"));
  sephiroth->showMaterias();

  sephiroth->equip(materiaSrc->createMateria("ice"));
  sephiroth->equip(materiaSrc->createMateria("cure"));
  sephiroth->showMaterias();

  sephiroth->equip(materiaSrc->createMateria("cure"));
  sephiroth->showMaterias();

  return 0;
}