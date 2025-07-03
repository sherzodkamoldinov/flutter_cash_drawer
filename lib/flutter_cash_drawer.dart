
import 'flutter_cash_drawer_platform_interface.dart';

class FlutterCashDrawer {
  Future<String?> openDrawer({required String printerName}) {
    return FlutterCashDrawerPlatform.instance.openDrawer(printerName: printerName);
  }

  Future<List<String>> getPrinterNames() {
    return FlutterCashDrawerPlatform.instance.getPrinterNames( );
  }
}
