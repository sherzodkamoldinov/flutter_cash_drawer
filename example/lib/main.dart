import 'package:flutter/material.dart';
import 'dart:async';

import 'package:flutter/services.dart';
import 'package:flutter_cash_drawer/flutter_cash_drawer.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatefulWidget {
  const MyApp({super.key});

  @override
  State<MyApp> createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  List<String> printerNameList = [];
  bool isLoading = false;
  final _openDrawerPlugin = FlutterCashDrawer();

  @override
  void initState() {
    super.initState();
    _getPrinters();
  }

  /// get printer name list
  Future<void> _getPrinters() async {
    isLoading = true;
    try {
      /// get list from channel
      final List<String> printerList = await _openDrawerPlugin.getPrinterNames();

      /// here add and show list
      setState(() {
        printerNameList.addAll(printerList);
      });
    } on PlatformException {
      debugPrint('Failed to get platform version.');
    }
    isLoading = false;
  }

  Future<void> _openDrawer({required String printerName}) async {
    String message;
    try {
      message = await _openDrawerPlugin.openDrawer(printerName: printerName) ?? 'Unknown _openDrawer';
    } on PlatformException {
      message = 'Failed to _openDrawer';
    }
    debugPrint('message: $message');
  }

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: const Text('Printer List'),
        ),
        body: isLoading
          ? Center(child: CircularProgressIndicator(),)

        : CustomScrollView(
          slivers: [
            if(printerNameList.isNotEmpty)
            SliverList.builder(
              itemCount: printerNameList.length,
              itemBuilder: (context, index) {
                final printerName = printerNameList[index];
                return ListTile(
                  onTap: () {
                    _openDrawer(printerName: printerName);
                  },
                  title: Text(printerName),
                );
              },
            )

           else
             SliverFillRemaining(child: Column(
               children: [
                 Text('Printers not found'),
                 ElevatedButton(onPressed: (){_getPrinters();}, child: Text("Get Again"))
               ],
             ),)
          ],
        ),
      ),
    );
  }
}
