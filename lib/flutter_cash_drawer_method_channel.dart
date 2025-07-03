import 'package:flutter/foundation.dart';
import 'package:flutter/services.dart';

import 'flutter_cash_drawer_platform_interface.dart';

/// An implementation of [FlutterCashDrawerPlatform] that uses method channels.
class MethodChannelFlutterCashDrawer extends FlutterCashDrawerPlatform {
  /// The method channel used to interact with the native platform.
  @visibleForTesting
  final methodChannel = const MethodChannel('flutter_cash_drawer');

  @override
  Future<String?> openDrawer({required String printerName}) async {
    final result = await methodChannel.invokeMethod<String>('open_drawer', printerName);
    debugPrint("message: $result");
    return result;
  }

  @override
  Future<List<String>> getPrinterNames() async {
    final result = await methodChannel.invokeMethod('get_printers');
    debugPrint("list_of_printers: $result");
    return List<String>.from(result);
  }
}
