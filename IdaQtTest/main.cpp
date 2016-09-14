#include "stdafx.h"
#include "IdaQcp.h"
#include "ExampleWidget.h"

static QWidget *idaForm = NULL;
static ExampleWidget *widget = NULL;
static const char *pluginName = "IdaQtTest";

void idaapi term() {}

void CALLBACK onOpen(QWidget *form, QLayout *layout, UINT user) {
	// On entry:
	// "form" is an IDA Pro dockable window "TForm"
	// "layout" is a new QHBoxLayout type layout with "form" being the parent
	// "user" is any 32bit user data passed via the idaqcp::openForm() below

	// Create a QCP widget
	if (widget = new ExampleWidget()) {
		widget->setObjectName("customWidget");
		form->resize(512, 512);
		layout->setContentsMargins(0, 0, 0, 0);
		layout->addWidget(widget);

		// Set the layout to the form and show it
		form->setLayout(layout);
		form->show();
	}
}

void CALLBACK onClose(UINT user) {
	if (widget) {
		delete widget;
		widget = NULL;
	}
	idaForm = NULL;
}

int idaapi init(void)
{
    return PLUGIN_OK;
}

void idaapi run(int)
{  
	if (!idaForm) {
		msg("Base QCP form open.\n");
		idaForm = idaqcp::openForm(pluginName, onOpen, onClose, 0, FALSE);
	} else {
		msg("Base QCP form close.\n");
		idaqcp::closeForm(idaForm);
		idaForm = NULL;
	}
}

plugin_t PLUGIN =
{
    IDP_INTERFACE_VERSION,
	PLUGIN_PROC,           // plugin flags
    init,                 // initialize
	term,                 // terminate. this pointer may be NULL.
    run,                  // invoke plugin
    NULL,                 // long comment about the plugin
    NULL,                 // multiline help about the plugin
	pluginName,     // the preferred short name of the plugin
    NULL                  // the preferred hotkey to run the plugin
};
