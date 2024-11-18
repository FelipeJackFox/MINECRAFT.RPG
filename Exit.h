#ifndef EXIT_H
#define EXIT_H

class Exit {
private:
    bool isOpen;

public:
    Exit();

    // Getters and Setters
    bool getIsOpen() const;
    void setIsOpen(bool isOpen);
};

#endif // EXIT_H
