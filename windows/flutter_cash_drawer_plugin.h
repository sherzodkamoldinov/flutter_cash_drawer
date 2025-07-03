#ifndef FLUTTER_PLUGIN_OPEN_DRAWER_PLUGIN_H_
#define FLUTTER_PLUGIN_OPEN_DRAWER_PLUGIN_H_

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>

#include <memory>

namespace flutter_cash_drawer {

class FlutterCashDrawerPlugin : public flutter::Plugin {
 public:
  static void RegisterWithRegistrar(flutter::PluginRegistrarWindows *registrar);

  FlutterCashDrawerPlugin();

  virtual ~FlutterCashDrawerPlugin();

  // Disallow copy and assign.
  FlutterCashDrawerPlugin(const FlutterCashDrawerPlugin&) = delete;
  FlutterCashDrawerPlugin& operator=(const FlutterCashDrawerPlugin&) = delete;

  // Called when a method is called on this plugin's channel from Dart.
  void HandleMethodCall(
      const flutter::MethodCall<flutter::EncodableValue> &method_call,
      std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result);
};

}  // namespace open_drawer

#endif  // FLUTTER_PLUGIN_OPEN_DRAWER_PLUGIN_H_
