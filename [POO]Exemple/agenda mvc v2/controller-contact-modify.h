#ifndef CONTROLLER_CONTACT_MODIFY_H
#define CONTROLLER_CONTACT_MODIFY_H
#include "model-contact.h" 
#include "edit-box-string.h"

using namespace std;

class ControllerContactModify
{
private:
	Contact *model;
	EditBoxString editBox;
public:
	ControllerContactModify(Contact *newModel)
	{
		model = newModel;
		
	}
public:
	void listen()
	{
		editBox.setLabel(string("Nume"));
		model->setName(editBox.getValue());
		editBox.setLabel(string("Numar telefon"));
		model->setPhoneNo(editBox.getValue());
	}
};

#endif 
