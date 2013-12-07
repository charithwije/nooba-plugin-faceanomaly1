
/*@file faceanomaly1.h
  @author  Charith Wijenayake <charithwije21@gmail.com>

  @section LICENSE
  Face Anomaly 1 PLugin API header file
  Copyright (C) 2013 Developed by Team Nooba

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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


};

#endif // FACEANOMALY1PLUGIN_H
