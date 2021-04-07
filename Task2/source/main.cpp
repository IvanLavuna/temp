//
// Created by ivan on 30.03.21.
//
#include "MainWindow.h"
/**

 Working plan:

 1) Implement indexing of mp4 files +
 2) Implement indexing of out of track path files in home/<user> path +
 3) Implement indexing in new thread
 4) Implement progress bar, and specific file management(play, stop, next)
 5) Implement displaying of file metadata
 6) Implement Search functionality

 **/



int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	MainWindow window;
	window.show();
	return QCoreApplication::exec();
}

