#include "faceanomaly1plugin.h"
#include <QtCore>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <QDebug>
#include <QString>

Faceanomaly1Plugin::Faceanomaly1Plugin()
{

}

Faceanomaly1Plugin::~Faceanomaly1Plugin()
{

}

bool Faceanomaly1Plugin::procFrame( const cv::Mat &in, cv::Mat &out, ProcParams &params )
{

 cv::cvtColor(in, out, CV_BGR2GRAY);


    return true;
}

bool Faceanomaly1Plugin::init()
{
    return true;
}

bool Faceanomaly1Plugin::release()
{
    return true;
}


void Faceanomaly1Plugin::inputData(const PluginPassData& data){

//    QStringList arrived; =data.strList();
//    QString s=arrived.value(0);

//   // qDebug(s);
    QList <QStringList> list;


    foreach(QString str,data.strList()){
      // debugMsg("faces # : " + str);

       int i= str.split(" ")[0].toInt();
       if(!str.isEmpty() && i>=5){
           debugMsg("<FONT COLOR='#ff0000'>****5 faces detected !!");
       }
       i=0;
    }
}


PluginInfo Faceanomaly1Plugin::getPluginInfo() const
{
    PluginInfo pluginInfo(
        "Faceanomaly1 Plugin",
        0,
        1,
        "Plugin Description goes here",
        "Plugin Creator");
    return pluginInfo;
}
// see qt4 documentation for details on the macro (Qt Assistant app)
// Mandatory  macro for plugins in qt4. Made obsolete in qt5
#if QT_VERSION < 0x050000
    Q_EXPORT_PLUGIN2(Faceanomaly1Plugin, Faceanomaly1Plugin);
#endif
