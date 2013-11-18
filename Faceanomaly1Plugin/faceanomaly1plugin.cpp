#include "faceanomaly1plugin.h"
#include <QtCore>
#include <opencv2/core/core.hpp>

Faceanomaly1Plugin::Faceanomaly1Plugin()
{

}

Faceanomaly1Plugin::~Faceanomaly1Plugin()
{

}

bool Faceanomaly1Plugin::procFrame( const cv::Mat &in, cv::Mat &out, ProcParams &params )
{

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
