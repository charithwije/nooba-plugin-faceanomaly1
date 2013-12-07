
/*@file faceanomaly1plugin.cpp
  @author  Charith Wijenayake <charithwije21@gmail.com>

  @section LICENSE
  Face Anomaly 1 API source file
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
    faceThresholdValue = "3";
    threasholdFaceCount =3;
    createStringParam(faceThresholdParameter,faceThresholdValue,true);

    createFrameViewer("Output");

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



void Faceanomaly1Plugin::inputData(const QStringList& strList, QList<QImage> imageList){

    int i;

    frameNum=strList.at(1);

    if (!strList.at(0).isEmpty())
        i= strList.at(0).split(" ")[0].toInt();

    if(!imageList.isEmpty()){

        imageList.at(0);
        updateFrameViewer("Output",imageList.at(0).copy());


    }

    if( i>=threasholdFaceCount){

        debugMsg(QString("<FONT COLOR='#ff0000'>%1 faces detected on frame %2 ").arg(threasholdFaceCount).arg(frameNum));
        generateAlert("Output","Too many people",nooba::RedAlert);
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
