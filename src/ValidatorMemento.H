class XMLValidator;   // forward declaration
class State;          // forward declaration

// Memento pattern - Memento
class ValidatorMemento
{
public:
    // narrow public interface
    virtual ~ValidatorMemento()
    {
        // Delete deep snapshot
        if (_state) {
            for (auto* vc : _state->schemaSnapshot) delete vc;
            delete _state;
        }
    }

private:
    // private members accessbile only to the Originator
    friend class XMLValidator;
    ValidatorMemento();

    void SetState(State *state) // Store configuration
    {
        this->_state = state;
    }

    State* GetState() const // Retrieve configuration, restore saved state
    {
        return _state;
    }

    State* _state;
};