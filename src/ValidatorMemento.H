class XMLValidator;   // forward declaration
class State;          // forward declaration

// Memento pattern - Memento
class ValidatorMemento
{
public:
    // narrow public interface
    virtual ~ValidatorMemento();

private:
    // private members accessbile only to the Originator
    friend class XMLValidator;
    ValidatorMemento();

    void SetState(State *state) // Store configuration
    {
        this->_state = state;
    }
    State* GetState() // Retrieve configuration
    {
        return _state;
    }

    State* _state;
};