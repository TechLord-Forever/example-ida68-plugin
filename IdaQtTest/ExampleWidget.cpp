#include "stdafx.h"
#include "ExampleWidget.h"

ExampleWidget::ExampleWidget() : QWidget() {
	mainLayout = new QVBoxLayout(this);
	QLabel *testText = new QLabel;
	testText->setText("Works inside :)");

	mainLayout->addWidget(testText);

	setLayout(mainLayout);
}