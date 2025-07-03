
import 'flutter_cash_drawer_platform_interface.dart';

class OpenDrawer {
  Future<String?> openDrawer({required String printerName}) {
    return OpenDrawerPlatform.instance.openDrawer(printerName: printerName);
  }

  Future<List<String>> getPrinterNames() {
    return OpenDrawerPlatform.instance.getPrinterNames( );
  }
}
