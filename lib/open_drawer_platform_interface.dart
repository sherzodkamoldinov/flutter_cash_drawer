import 'package:plugin_platform_interface/plugin_platform_interface.dart';

import 'open_drawer_method_channel.dart';

abstract class OpenDrawerPlatform extends PlatformInterface {
  /// Constructs a OpenDrawerPlatform.
  OpenDrawerPlatform() : super(token: _token);

  static final Object _token = Object();

  static OpenDrawerPlatform _instance = MethodChannelOpenDrawer();

  /// The default instance of [OpenDrawerPlatform] to use.
  ///
  /// Defaults to [MethodChannelOpenDrawer].
  static OpenDrawerPlatform get instance => _instance;

  /// Platform-specific implementations should set this with their own
  /// platform-specific class that extends [OpenDrawerPlatform] when
  /// they register themselves.
  static set instance(OpenDrawerPlatform instance) {
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
