#include "xyjvideoplayer.h"
#include<QtWidgets\qapplication.h>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	xyjVideoPlayer w;
	w.show();

	return a.exec();
}
