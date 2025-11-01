#include <string>
#include <fstream>
#include <ios>
#include <vector>
#include "ValidatorMemento.H"

#include "Element.H"

class ValidChildren;

// Memento pattern - Originator
class XMLValidator
{
private:
	std::vector<ValidChildren *>	schema;
	State*					_state;
public:
	XMLValidator(void)	{}
	~XMLValidator() { for (int i = 0; i < schema.size(); i++) delete schema[i]; }

	ValidatorMemento*			createMemento();
	void setMemento(ValidatorMemento* m);

	virtual ValidChildren *				addSchemaElement(std::string element);
	virtual std::vector<ValidChildren *>::iterator	findSchemaElement(std::string element);
};
