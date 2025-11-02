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
	State*				_state;
	
public:
	XMLValidator(void)	{}
	~XMLValidator() { for (int i = 0; i < schema.size(); i++) delete schema[i]; }

	virtual ValidChildren *				addSchemaElement(std::string element);
	virtual std::vector<ValidChildren *>::iterator	findSchemaElement(std::string element);

	ValidatorMemento*			createMemento() // should this be somewhere else?
	{
		ValidatorMemento* m = new ValidatorMemento();
		m->SetState(captureState());
		return m;
	}

	// Helper function to copy current state
	ValidChildren* copyValidChildren(ValidChildren* vc)
	{
		ValidChildren* copy = new ValidChildren(vc->getThisElement());

		// Added getter methods
		auto& children = vc->getValidChildren();
		auto& attributes    = vc->getChildIsAttribute();

		for (size_t i = 0; i < children.size(); i++) {
			copy->addValidChild(children[i], attributes[i]);
		}

		copy->setCanHaveText(vc->canHaveText());
		return copy;
	}

	State* captureState()
	{
		State* state = new State();

		for (auto vc : schema) {
			state->schemaSnapshot.push_back(copyValidChildren(vc));
		}

		return state;
	}

	void restoreFromMemento(ValidatorMemento* m)
	{
		// Delete old schema
		for (auto vc : schema) delete vc;
		schema.clear();

		State* saved = m->GetState();

		for (auto vc : saved->schemaSnapshot) {
			schema.push_back(copyValidChildren(vc));  
		}
	}
};
