// Memento example - https://www.geeksforgeeks.org/system-design/memento-design-pattern-c-design-patterns/

#include <vector>
#include "ValidatorMemento.H"

// Memento pattern - Caretaker
class ValidatorCache 
{
    private:
        std::vector<ValidatorMemento*> mementos;

    public:
        ValidatorCache() {}
        ~ValidatorCache() {}

        void addMemento(ValidatorMemento* memento) {
            mementos.push_back(memento);
        }

        ValidatorMemento* GetMemento(int index) const {
            if (index >= 0 && index < mementos.size()) {
                return mementos[index];
            }
            throw std::out_of_range("Invalid Memento index");
        }

};