#include <vector>
#include "ValidatorMemento.H"

// Memento pattern - Caretaker
class ValidatorCache 
{
    private:
        std::vector<ValidatorMemento*> mementos;
        XMLValidator* originator;

    public:
        ValidatorCache(XMLValidator* originator) : originator(originator) {}
        ~ValidatorCache() {}

        void addMemento(ValidatorMemento* memento) {
            mementos.push_back(memento);
        }

        // Equivalent to SetMemento
        void SetMemento(ValidatorMemento* memento) { // todo
            if (!this->mementos.size()) {
                return;
            }

            // TODO - remove memento from cache
            mementos.erase(std::remove(mementos.begin(), mementos.end(), memento), mementos.end());

            // TODO - need to find memento in vector and remove from cache, shouldn't it not know about originator? Or can it but it just doesn't access info
            originator->restoreMemento(memento);

        }

};