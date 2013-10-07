#include "util/SdUtil.h"

namespace  SdUtil 
{
	/*
	QString toProjectPath(const QString& path)
	{
		MdProject* proj=MdOperator::data()->getCurProject();
		assert(proj);
		QString proj_dir=proj->getDirName()+"/";
        assert(path.startsWith(proj_dir));
        QString ret=path;
        ret.remove(0,proj_dir.size());
		return ret;
	}
	QString toRelativePath(const QString& root,const QString& path)
	{
		QString rel_root=root+"/";
		assert(path.startsWith(rel_root));
		QString ret=path;
		ret.remove(0,rel_root.size());
		return ret;
	}
	*/
}

