#ifndef ARMOR_H
#define ARMOR_H

#include "Item.h"

class Armor : public Item {
public:
  int resistance;

  // Constructor
  Armor(int resistance);
};

#endif
