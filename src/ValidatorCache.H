#include <vector>
#include "ValidatorMemento.H"

class ValidatorCache 
{
    public:
        ValidatorCache() {}
        ~ValidatorCache() {}

        void addMemento(ValidatorMemento* memento) {
            mementos.push_back(memento);
        }

        ValidatorMemento* getMemento(int index) {
            if (index < 0 || index >= mementos.size()) {
                return nullptr;
            }
            return mementos[index];
        }

    private:
        std::vector<ValidatorMemento*> mementos;

};