class XMLValidator;   // forward declaration
class State;          // forward declaration

class ValidatorMemento
{
public:
    // narrow public interface
    virtual ~ValidatorMemento();

private:
    // private members accessbile only to the Originator
    friend class XMLValidator;
    ValidatorMemento();

    void SetState(State *state);
    State* GetState();

    State* state;
};