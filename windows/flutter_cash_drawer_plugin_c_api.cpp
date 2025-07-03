#include "include/flutter_cash_drawer/flutter_cash_drawer_plugin_c_api.h"

#include <flutter/plugin_registrar_windows.h>

#include "flutter_cash_drawer_plugin.h"

void FlutterCashDrawerPluginCApiRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar) {
    flutter_cash_drawer::FlutterCashDrawerPlugin::RegisterWithRegistrar(
      flutter::PluginRegistrarManager::GetInstance()
          ->GetRegistrar<flutter::PluginRegistrarWindows>(registrar));
}
