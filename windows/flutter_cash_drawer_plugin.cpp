#include "flutter_cash_drawer_plugin.h"

// Windows headers
#include <windows.h>
#include <winspool.h>
#include <VersionHelpers.h>

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>
#include <flutter/standard_method_codec.h>

#include <memory>
#include <string>

namespace flutter_cash_drawer {

// Регистрация плагина
    void OpenDrawerPlugin::RegisterWithRegistrar(
            flutter::PluginRegistrarWindows* registrar) {
        auto channel =
                std::make_unique<flutter::MethodChannel<flutter::EncodableValue>>(
                        registrar->messenger(), "flutter_cash_drawer",
                                &flutter::StandardMethodCodec::GetInstance());

        auto plugin = std::make_unique<OpenDrawerPlugin>();

        channel->SetMethodCallHandler(
                [plugin_pointer = plugin.get()](const auto& call, auto result) {
                    plugin_pointer->HandleMethodCall(call, std::move(result));
                });

        registrar->AddPlugin(std::move(plugin));
    }

    OpenDrawerPlugin::OpenDrawerPlugin() {}

    OpenDrawerPlugin::~OpenDrawerPlugin() {}

    void OpenDrawerPlugin::HandleMethodCall(
            const flutter::MethodCall<flutter::EncodableValue>& method_call,
            std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result) {


        if (method_call.method_name().compare("open_drawer") == 0) {

            // 🔐 Безопасно получаем аргумент (имя принтера)
            const auto* arguments = std::get_if<std::string>(method_call.arguments());
            if (!arguments) {
                result->Error("INVALID_ARGUMENT", "Printer name must be a string.");
                return;
            }
            std::string printerName = *arguments;


            // 📦 Логика открытия денежного ящика
            HANDLE hPrinter;
            DOC_INFO_1A docInfo;
            DWORD bytesWritten;

            if (!OpenPrinterA((LPSTR)printerName.c_str(), &hPrinter, NULL)) {
                result->Success(flutter::EncodableValue("not_success"));
                return;
            }

            docInfo.pDocName = (LPSTR)"OpenDrawer";
            docInfo.pOutputFile = NULL;
            docInfo.pDatatype = (LPSTR)"RAW";

            StartDocPrinterA(hPrinter, 1, (LPBYTE)&docInfo);
            StartPagePrinter(hPrinter);

            BYTE command[] = {0x1B, 0x70, 0x00, 0x19, 0xFA}; // ESC p 0 25 250
            WritePrinter(hPrinter, command, sizeof(command), &bytesWritten);

            EndPagePrinter(hPrinter);
            EndDocPrinter(hPrinter);
            ClosePrinter(hPrinter);

            result->Success(flutter::EncodableValue("success"));
        }
        else  if (method_call.method_name().compare("get_printers") == 0) {
            DWORD needed = 0, returned = 0;
            EnumPrintersA(PRINTER_ENUM_LOCAL | PRINTER_ENUM_CONNECTIONS, NULL, 1, NULL, 0, &needed, &returned);

            if (needed == 0) {
                result->Success(flutter::EncodableValue(std::vector<flutter::EncodableValue>{}));
                return;
            }

            std::vector<uint8_t> buffer(needed);
            if (!EnumPrintersA(PRINTER_ENUM_LOCAL | PRINTER_ENUM_CONNECTIONS, NULL, 1,
                               buffer.data(), needed, &needed, &returned)) {
                result->Error("PRINTER_ERROR", "Не удалось получить список принтеров.");
                return;
            }

            PRINTER_INFO_1A* printerInfo = reinterpret_cast<PRINTER_INFO_1A*>(buffer.data());
            std::vector<flutter::EncodableValue> printerNames;

            for (DWORD i = 0; i < returned; ++i) {
                printerNames.emplace_back(std::string(printerInfo[i].pName));
            }

            result->Success(flutter::EncodableValue(printerNames));
            return;
        }
        else {
            result->NotImplemented();
        }
    }

}  // namespace open_drawer