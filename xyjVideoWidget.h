#ifndef XYJVIDEOWIDGET_H
#define	XYJVIDEOWIDGET_H
#include<QVideoWidget >
#include<QMediaPlayer >
class xyjVideoWidget:public QVideoWidget
{
public:
	xyjVideoWidget(QWidget* parent=0,QMediaPlayer* mediaplayer=0);
	~xyjVideoWidget();
protected:
	void mouseDoubleClickEvent(QMouseEvent* event);
private:
	QMediaPlayer* _mediaPlayer;
};

#endif XYJVIDEOWIDGET_H