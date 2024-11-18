#include "Exit.h"

Exit::Exit() : isOpen(false) {}

bool Exit::getIsOpen() const {
    return isOpen;
}

void Exit::setIsOpen(bool isOpen) {
    this->isOpen = isOpen;
}
