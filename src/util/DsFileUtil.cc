#include <QFileInfo>

#include "util/DsFileUtil.h"
#include "core/DsProject.h"
#include "core/DsData.h"
#include "DsGlobal.h"


QString DsFileUtil::dirName(const char* path)
{
 	QFileInfo file_info(path);

    /* dir_name */
    return file_info.path();

}

QString DsFileUtil::baseName(const char* path)
{
 	QFileInfo file_info(path);

    /* file_name*/
    return file_info.fileName();
}
QString DsFileUtil::toProjectPath(const char* name)
{
    QString proj_dir=DsGlobal::data()->getCurProject()->getProjectDir();
    return proj_dir+QString("/")+QString(name);
}
