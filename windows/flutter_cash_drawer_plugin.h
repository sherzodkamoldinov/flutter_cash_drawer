#ifndef FLUTTER_PLUGIN_OPEN_DRAWER_PLUGIN_H_
#define FLUTTER_PLUGIN_OPEN_DRAWER_PLUGIN_H_

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>

#include <memory>

namespace flutter_cash_drawer {

class OpenDrawerPlugin : public flutter::Plugin {
 public:
  static void RegisterWithRegistrar(flutter::PluginRegistrarWindows *registrar);

  OpenDrawerPlugin();

  virtual ~OpenDrawerPlugin();

  // Disallow copy and assign.
  OpenDrawerPlugin(const OpenDrawerPlugin&) = delete;
  OpenDrawerPlugin& operator=(const OpenDrawerPlugin&) = delete;

  // Called when a method is called on this plugin's channel from Dart.
  void HandleMethodCall(
      const flutter::MethodCall<flutter::EncodableValue> &method_call,
      std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result);
};

}  // namespace open_drawer

#endif  // FLUTTER_PLUGIN_OPEN_DRAWER_PLUGIN_H_
