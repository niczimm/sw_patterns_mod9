#include <string>
#include <fstream>
#include <ios>
#include <vector>
#include "ValidatorMemento.H"

#include "Element.H"

class ValidChildren;

struct State
{
	std::string elementName;
	std::vector<ValidChildren *> schemaSnapshot;
};

// Memento pattern - Originator
class XMLValidator
{
private:
	std::vector<ValidChildren *>	schema;
	State*				_state;
	
public:
	XMLValidator(void)	{}
	~XMLValidator() { for (int i = 0; i < schema.size(); i++) delete schema[i]; }

	ValidatorMemento*			createMemento() // should this be somewhere else?
	{
		ValidatorMemento* m = new ValidatorMemento();
		m->SetState(_state);
		return m;
	}

	void getMemento(ValidatorMemento* m)
	{
		_state = m->GetState();
	}

	virtual ValidChildren *				addSchemaElement(std::string element);
	virtual std::vector<ValidChildren *>::iterator	findSchemaElement(std::string element);
};
