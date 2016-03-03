#include "xyjVideoWidget.h"


xyjVideoWidget::xyjVideoWidget(QWidget* parent,QMediaPlayer* mediaplayer):QVideoWidget(parent)
{
	this->_mediaPlayer=mediaplayer;
}


xyjVideoWidget::~xyjVideoWidget()
{

}
void xyjVideoWidget::mouseDoubleClickEvent(QMouseEvent* event){
	//未播放时不能全屏
	//QWidget* parent=this->parentWidget();
	if(!this->_mediaPlayer->isVideoAvailable()) return;
	if(!this->isFullScreen()){
		this->setFullScreen(true);
	}else{
		//退出全屏，先调用setWindowFlags（Qt::SubWindow）；在调用showNormal()
		//this->setParent(parent);
		this->setWindowFlags(Qt::SubWindow);
		this->showNormal();
		this->setGeometry(QRect(0,30,800,300));
		//!出现遮挡问题，播放列表被遮挡
	}
	QVideoWidget::mouseDoubleClickEvent(event);
}