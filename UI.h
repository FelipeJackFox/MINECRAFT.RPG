#ifndef UI_H
#define UI_H

class UI {
public:
  //Attributes

  // Methods
  void displayMessage(const std::string& message);
  void displayStats(const Entity& entity);
  void displayInventory(const Inventory& inventory);
};

#endif