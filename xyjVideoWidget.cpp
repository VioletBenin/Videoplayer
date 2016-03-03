#include "xyjVideoWidget.h"


xyjVideoWidget::xyjVideoWidget(QWidget* parent,QMediaPlayer* mediaplayer):QVideoWidget(parent)
{
	this->_mediaPlayer=mediaplayer;
}


xyjVideoWidget::~xyjVideoWidget()
{

}
void xyjVideoWidget::mouseDoubleClickEvent(QMouseEvent* event){
	//δ����ʱ����ȫ��
	//QWidget* parent=this->parentWidget();
	if(!this->_mediaPlayer->isVideoAvailable()) return;
	if(!this->isFullScreen()){
		this->setFullScreen(true);
	}else{
		//�˳�ȫ�����ȵ���setWindowFlags��Qt::SubWindow�����ڵ���showNormal()
		//this->setParent(parent);
		this->setWindowFlags(Qt::SubWindow);
		this->showNormal();
		this->setGeometry(QRect(0,30,800,300));
		//!�����ڵ����⣬�����б��ڵ�
	}
	QVideoWidget::mouseDoubleClickEvent(event);
}