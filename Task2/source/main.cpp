//
// Created by ivan on 30.03.21.
//
#include "AudioWindow.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	AudioWindow window;
	window.show();
	return QCoreApplication::exec();
}

