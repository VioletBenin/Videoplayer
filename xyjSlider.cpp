#include "xyjSlider.h"


xyjSlider::xyjSlider(Qt::Orientation Ori,QWidget* parent):QSlider(Ori,parent)
{
}


xyjSlider::~xyjSlider()
{
}
void xyjSlider::mousePressEvent(QMouseEvent* event){
	
	//todo
	QSlider::mousePressEvent(event);
}