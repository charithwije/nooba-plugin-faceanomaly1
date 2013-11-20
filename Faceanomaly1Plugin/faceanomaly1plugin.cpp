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
    faceThresholdParameter ="face threashold";
    faceThresholdValue = "4";
    createStringParam(faceThresholdParameter,faceThresholdValue,true);

    return true;
}

bool Faceanomaly1Plugin::release()
{
    return true;
}

void Faceanomaly1Plugin::onStringParamChanged(const QString& varName, const QString& val){

    if(varName.compare(faceThresholdParameter)==0){

        threasholdFaceCount=val.split(" ")[0].toInt();

    }

}




void Faceanomaly1Plugin::inputData(const PluginPassData& data){


    QList <QStringList> list;
    int i;

    frameNum=data.strList().at(1);
    if (!data.strList().at(0).isEmpty())
        i= data.strList().at(0).split(" ")[0].toInt();

    if( i>=threasholdFaceCount){

        debugMsg(QString("<FONT COLOR='#ff0000'>%1 faces detected on frame %2 ").arg(threasholdFaceCount).arg(frameNum));
    }
    i=0;

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
