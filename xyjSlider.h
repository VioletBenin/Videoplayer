#ifndef XYJSLIDER_H
#define XYJSLIDER_H
#include<QSlider >
class xyjSlider:public QSlider
{
public:
	xyjSlider(Qt::Orientation=Qt::Horizontal,QWidget* parent=0);
	~xyjSlider();
protected:
	void mousePressEvent(QMouseEvent *event) override;
};
#endif
