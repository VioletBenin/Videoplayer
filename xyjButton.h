#ifndef XYJBUTTON_H
#define XYJBUTTON_H
#include<QPushButton>
class xyjButton:public QPushButton
{
	Q_OBJECT
public:
	xyjButton(QWidget* parent=0);
	~xyjButton();

	void set_icons(const QIcon& normal=QIcon(),const QIcon& focus=QIcon(),const QIcon& pressed=QIcon());
protected:
	void enterEvent(QEvent* event) override;
	void leaveEvent(QEvent* event) override;

	void mousePressEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
private:
	QIcon _normal;
	QIcon _focus;
	QIcon _pressed;
};
#endif
