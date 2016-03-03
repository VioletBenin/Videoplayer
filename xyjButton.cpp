#include "xyjButton.h"


xyjButton::xyjButton(QWidget* parent):QPushButton(parent)
{
	QPushButton::setIcon(this->_normal);
}
xyjButton::~xyjButton()
{

}
void xyjButton::set_icons(const QIcon& normal,const QIcon& focus,const QIcon& pressed){
	this->_normal=normal;
	this->_focus=focus;
	this->_pressed=pressed;
	this->setIcon(_normal);
}

void xyjButton::enterEvent(QEvent* event){
	QPushButton::setIcon(this->_focus);
}
void xyjButton::leaveEvent(QEvent* event){
	QPushButton::setIcon(this->_normal);
}
void xyjButton::mousePressEvent(QMouseEvent* event){
	QPushButton::setIcon(this->_pressed);
	QPushButton::mousePressEvent(event);
}
void xyjButton::mouseReleaseEvent(QMouseEvent* event){
	QPushButton::setIcon(this->_focus);
	QPushButton::mouseReleaseEvent(event);
}