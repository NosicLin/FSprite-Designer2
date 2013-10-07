#ifndef _SD_PROJECT_EXPLORE_MODEL_H_
#define _SD_PROJECT_EXPLORE_MODEL_H_

#include <QAbstractItemModel>
class SdProjectExploreModel:public QAbstractItemModel 
{
	Q_OBJECT
	public:
		SdProjectExploreModel();
		~SdProjectExploreModel();

	public:
		virtual QModelIndex index(int row,int column,
								const QModelIndex& parent=QModelIndex())const;
		virtual QModelIndex parent(const QModelIndex& child)const;
		virtual int rowCount(const QModelIndex& parent=QModelIndex())const;
		virtual int columnCount(const QModelIndex& parent=QModelIndex())const;
        virtual QVariant data(const  QModelIndex& index,
                              int role=Qt::DisplayRole) const;
    public:
        void refresh();
};
#endif /*_SD_PROJECT_EXPLORE_MODEL_H_*/



