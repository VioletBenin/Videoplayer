#ifndef XYJVIDEOPLAYER_H
#define XYJVIDEOPLAYER_H

#include <QWidget>
#include<qapplication.h>
#include<QMediaplayer>
#include<QMediaPlaylist >
#include<QVideoWidget >
#include<QFileDialog >
#include<qheaderview.h>
#include<QTablewidget >
#include<qdatastream.h>
#include<qmenu.h>
#include<QDragEnterEvent>
#include<QDropEvent >
#include<QMouseEvent>
#include<qmimedata.h>
#include<QList >
#include<qslider.h>
#include<QLabel >
#include<QTime >
#include<qmediametadata.h>
#include<qdir.h>
#include<5.5.1\QtWidgets\private\qwidgetresizehandler_p.h>
#include<QDebug >
#include"xyjButton.h"
#include"xyjVideoWidget.h"
#include"NoFocusDelegate.h"
#include"xyjSlider.h"

#ifndef DELETE
#define DELETE(ptr) if(ptr){delete ptr;ptr=NULL;}
#endif
enum PLAYMODE{LISTCIRCLE,SINGLEREPEAT,RANDOM};
class xyjVideoPlayer : public QWidget
{
	Q_OBJECT
friend class xyjVideoWidget;
public:
	xyjVideoPlayer(QWidget *parent = 0);
	~xyjVideoPlayer();
	void init_ui();
	void raise_button();
	void init_videoPlayer();
	void init_connections();
	void init_table_menu();
private:
	//QHBoxLayout* _hblayout;
	QLayout* _layout;
	QMediaPlayer *_mediaPlayer;
	int _cur_volume;
	int _play_mode;
	QMediaPlaylist *_playList;
	QStringList _fileList;
	xyjVideoWidget *_videoWidget;
	QTableWidget *_playTable;
	QString _xyjPath;
	/**************************/
	xyjButton* _add_video_button;
	xyjButton* _play_button;
	xyjButton* _pause_button;
	xyjButton* _next_button;
	xyjButton* _previous_button;
	xyjButton* _play_table_button;
	xyjButton* _min_button;
	//xyjButton* _max_button;
	xyjButton* _close_button;
	xyjButton* _vol_yes_button;
	xyjButton* _vol_no_button;

	xyjButton* _single_repeat_button;
	xyjButton* _repeat_button;
	xyjButton* _random_button;
	xyjButton* _full_screen_button;

	QSlider *_vol_slider;
	xyjSlider *_play_process_slider;
	/*********************************/
	QMenu *_menu_on_table_text;
	QMenu *_menu_on_table_blank;
	QAction *_add_video_action;
	QAction *_add_dir_action;
	QAction *_remove_cur_action;
	QAction *_remove_all_action;
	
	/*********************************/
	QLabel* _current_time_label;
	QLabel* _total_time_label;
	/*********************************/
	int _select_row_index;
	qint64 _play_position;
	void paintEvent(QPaintEvent *event) override;
	void dragEnterEvent(QDragEnterEvent *event) override;
	void dropEvent(QDropEvent *event) override;
private slots:
	void update_duration(qint64 duration);
	void update_position(qint64 position);
	void set_media_play_position(int pos);
	qint64 get_media_play_positon();
	void slider_released_play();
	void slider_pressed_play();
	void open_video();
	void add_dir();
	void play_button_clicked();
	void vol_yes_button_clicked();
	void vol_no_button_clicked();
	void pause_button_clicked();
	void next_button_clicked();
	void pre_button_clicked();
	void close_button_clicked();
	void min_button_clicked();
	void play_table_button_clicked();
	void play_table_double_clicked(int row,int);
	void play_table_menu_requested(const QPoint& pos);
	void play_mode_button_clicked();
	void fullscreen_button_clicked();
	void mouse_enter_cell(int row,int col);
	void add_list(QStringList fileList);
	void remove_all_video();
	void remove_current_video();
	void save_list();
	void read_list();
	void paint_table();
};

#endif // XYJVIDEOPLAYER_H
