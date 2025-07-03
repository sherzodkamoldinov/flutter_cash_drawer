import 'package:plugin_platform_interface/plugin_platform_interface.dart';

import 'flutter_cash_drawer_method_channel.dart';

abstract class FlutterCashDrawerPlatform extends PlatformInterface {
  /// Constructs a OpenDrawerPlatform.
  FlutterCashDrawerPlatform() : super(token: _token);

  static final Object _token = Object();

  static FlutterCashDrawerPlatform _instance = MethodChannelFlutterCashDrawer();

  /// The default instance of [FlutterCashDrawerPlatform] to use.
  ///
  /// Defaults to [MethodChannelFlutterCashDrawer].
  static FlutterCashDrawerPlatform get instance => _instance;

  /// Platform-specific implementations should set this with their own
  /// platform-specific class that extends [FlutterCashDrawerPlatform] when
  /// they register themselves.
  static set instance(FlutterCashDrawerPlatform instance) {
    PlatformInterface.verifyToken(instance, _token);
    _instance = instance;
  }

  Future<String?> openDrawer({required String printerName}) {
    throw UnimplementedError('openDrawer() has not been implemented.');
  }

  Future<List<String>> getPrinterNames() {
    throw UnimplementedError('getPrinterNames() has not been implemented.');
  }
}
