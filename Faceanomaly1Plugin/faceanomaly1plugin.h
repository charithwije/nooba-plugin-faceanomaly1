#ifndef FACEANOMALY1PLUGIN_H
#define FACEANOMALY1PLUGIN_H

#include "faceanomaly1plugin_global.h"
#include "noobapluginapi.h"



#include <QObject>

class FACEANOMALY1PLUGIN_EXPORT Faceanomaly1Plugin: public NoobaPluginAPI
{
    Q_OBJECT
    Q_INTERFACES(NoobaPluginAPI)
#if QT_VERSION >= 0x050000
    Q_PLUGIN_METADATA(IID "nooba.plugins.qt5.faceanomaly1-plugin" FILE "faceanomaly1Plugin.json")
#endif

public:
    Faceanomaly1Plugin();
    ~Faceanomaly1Plugin();

    bool procFrame(const cv::Mat &in, cv::Mat &out, ProcParams &params);
    bool init();
    bool release();
    PluginInfo getPluginInfo() const;

private :
    QString faceThresholdParameter;
    QString faceThresholdValue;
     QString frameNum;
    int threasholdFaceCount;

private slots:

       void onStringParamChanged(const QString& varName, const QString& val);



public slots:

     void inputData(const QStringList& strList, QList<QImage> imageList);


    /**
     * These functions will be called when the parameters are changed by the
     * user.
     */
//    void onIntParamChanged(const QString& varName, int val);
//    void onDoubleParamChanged(const QString& varName, double val);
//    void onStringParamChanged(const QString& varName, const QString& val);
//    void onMultiValParamChanged(const QString& varName, const QString& val);


};

#endif // FACEANOMALY1PLUGIN_H
