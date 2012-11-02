#pragma once

#include <stdint.h>
#include <QPushButton>
#include <QWidget>
#include <retroshare/rsflags.h>

class GroupFlagsWidget: public QWidget
{
	Q_OBJECT

	public:
		GroupFlagsWidget(QWidget *parent,FileStorageFlags flags) ;
		virtual ~GroupFlagsWidget() ;

		FileStorageFlags flags() const ;

	public slots:
		void updated() ;

	protected slots:
		void update_GN_button(bool) ;
		void update_GB_button(bool) ;
		void update_ON_button(bool) ;
		void update_OB_button(bool) ;

	signals:
		void flagsChanged(FileStorageFlags) const ;

	private:
		void update_button_state(bool b,int id) ;

		QPushButton *_buttons[4] ;

		QLayout *_layout ;
		QIcon *_icons[6] ;
		FileStorageFlags _flags[4] ;

		static QString _tooltips_on[4] ;
		static QString _tooltips_off[4] ;
};
