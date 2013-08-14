#ifndef _DS_RESOURCE_WIDGET_H_
#define _DS_RESOURCE_WIDGET_H_

#include <QWidget>
#include <QFileSystemModel>
#include <QTreeView>
#include <QListView>
#include <QStringListModel>
#include <QStringList>
#include <QModelIndex>


class DsResourceWidget:public QWidget
{
	Q_OBJECT
	public:
		DsResourceWidget();
        ~DsResourceWidget();
    public:
        void setNameFilters(const QStringList& list);

    signals:
        void signalFileSelect(const QString& file_name);

	public slots:
        void slotCurProjectChange();
        void slotFileSelect(const QModelIndex& index);

	protected:
		void init();
        void destroy();
        void layout();

	private:
		QFileSystemModel* m_fileModel;
		QTreeView* m_resourceView;
};

#endif /*_DS_RESOURCE_WIDGET_H_*/

