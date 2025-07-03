#include "include/open_drawer/open_drawer_plugin_c_api.h"

#include <flutter/plugin_registrar_windows.h>

#include "open_drawer_plugin.h"

void OpenDrawerPluginCApiRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar) {
  open_drawer::OpenDrawerPlugin::RegisterWithRegistrar(
      flutter::PluginRegistrarManager::GetInstance()
          ->GetRegistrar<flutter::PluginRegistrarWindows>(registrar));
}
