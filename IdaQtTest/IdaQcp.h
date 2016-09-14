
//  ===============================================================================================
// QCustomPlot helper for IDA Pro by Sirmabus
// QCustomPlot is a Qt C++ widget for plotting and data visualization. By Emanuel Eichhammer
// http://www.qcustomplot.com/
//  ===============================================================================================
#pragma once

namespace idaqcp
{
	QWidget* _cdecl openForm(LPCTSTR titleString, void (CALLBACK *onOpen)(QWidget*, QLayout*, UINT), void (CALLBACK *onClose)(UINT), UINT user = 0, BOOL startOnTab = TRUE);
	void _cdecl closeForm(QWidget *form);

	// Tick IDA's Qt message pump to show msg() output
	inline void refreshUI(){ QApplication::processEvents(); };
};