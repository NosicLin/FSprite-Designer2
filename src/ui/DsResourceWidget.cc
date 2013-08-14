#include <QDir>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStringList>
#include "ui/DsResourceWidget.h"
#include "core/DsProject.h"


DsResourceWidget::DsResourceWidget()
{
    init();
    layout();
}
DsResourceWidget::~DsResourceWidget()
{
	destroy();
}

void DsResourceWidget::setNameFilters(const QStringList& list)
{
    m_fileModel->setNameFilters(list);
}

void DsResourceWidget::slotCurProjectChange()
{
    //DsProject* proj=MdOperator::data()->getCurProject();
    DsProject* proj=NULL;

	if(proj==NULL)
	{
		m_resourceView->setModel(NULL);
	}
	else 
    {
		/*
        QModelIndex root=m_fileModel->setRootPath(proj->getDirName());
        m_resourceView->setModel(m_fileModel);
        m_resourceView->setRootIndex(root);
        m_resourceView->setColumnHidden(1,true);
        m_resourceView->setColumnHidden(2,true);
        m_resourceView->setColumnHidden(3,true);
		*/
        //FS_TRACE_WARN("cur_path=%s",proj->getDirName().toStdString().c_str());
    }
}
void DsResourceWidget::slotFileSelect(const QModelIndex& index)
{
    QFileInfo file_info=m_fileModel->fileInfo(index);
    if(file_info.isDir())
    {
        return ;
    }
    QString file_name=file_info.filePath();
    //QString file_relative_name=DsUtil::toProjectPath(file_name);
    //emit signalFileSelect(file_relative_name);

   // FS_TRACE_WARN("file_name=%s",file_relative_name.toStdString().c_str());
}

void DsResourceWidget::init()
{
    m_fileModel=new QFileSystemModel();
    m_fileModel->setReadOnly(true);
    m_fileModel->setFilter(QDir::AllDirs|QDir::Files|QDir::NoSymLinks|QDir::NoDotAndDotDot );
    m_fileModel->setNameFilterDisables(false);

    m_resourceView=new QTreeView(this);
    m_resourceView->setHeaderHidden(true);

    //connect(MdData::shareData(),SIGNAL(signalCurProjectChange()),this,SLOT(slotCurProjectChange()));
    //connect(m_resourceView,SIGNAL(clicked(const QModelIndex&)),this,SLOT(slotFileSelect(const QModelIndex&)));
}
void DsResourceWidget::layout()
{
    QVBoxLayout* vlayout=new QVBoxLayout;
    vlayout->addWidget(m_resourceView);
    //vlayout->addWidget(m_chunkView,1);
    setLayout(vlayout);
}

void DsResourceWidget::destroy()
{
    delete m_fileModel;
    delete m_resourceView;
}


