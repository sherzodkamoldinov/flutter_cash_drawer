# Flutter Cash Drawer

Плагин для Flutter (только Windows), который позволяет:

* Получать список установленных принтеров
* Открывать денежный ящик через ESC-команду по USB-принтеру

Полностью написан на C++ и использует платформенные каналы для работы напрямую с Windows API.

---

## ✨ Особенности

* ✅ Поддержка ESC/POS принтеров (например, Xprinter XP-F300)
* ✅ Работа напрямую с Windows через `winspool.drv`
* ✅ Управление ящиком без .exe-файлов и сторонних программ

---

## ⚖️ Поддерживаемые платформы

| Платформа | Поддержка |
| --------- | --------- |
| Windows   | ✅ Да      |
| MacOS     | ❌ Нет     |
| Linux     | ❌ Нет     |
| Web       | ❌ Нет     |
| Android   | ❌ Нет     |
| iOS       | ❌ Нет     |

---

## 📁 Установка

Добавьте в `pubspec.yaml`:

```yaml
dependencies:
  flutter_cash_drawer: ^1.0.0
```

---

## 🔧 Использование

### 1. Импортируйте:

```dart
import 'package:flutter_cash_drawer/flutter_cash_drawer.dart';
```

### 2. Получите список принтеров:

```dart
List<String> printers = await FlutterCashDrawer.getPrinterNames();
print("Принтеры: $printers");
```

### 3. Откройте денежный ящик:

```dart
await FlutterCashDrawer.openDrawer("Xprinter XP-F300");
```

---

## 🌐 Платформенная интеграция

На C++ стороне используется:

* `EnumPrintersA()` — чтобы получить список установленных принтеров
* `OpenPrinterA()` + `WritePrinter()` — чтобы отправить ESC команду `0x1B 0x70 0x00 0x19 0xFA`

---

## 📃 CHANGELOG

**v1.0.0**

* Первая версия: открытие ящика + список принтеров

---

## 🎓 Лицензия

MIT

---

## 📲 Обратная связь / Автор

Автор: Sherzod aka
GitHub: [github.com/sherzodaka](https://github.com/sherzodaka)

---

## 🎡 Советы по использованию

* Убедитесь, что ваш ESC-принтер установлен в Windows
* Проверьте имя принтера через `wmic printer get name`
* Обычные команды ESC работают почти на всех Xprinter, GPrinter, POS80 и т.д.
* Если не открывается — попробуйте изменить тайминги в байтах команды: `0x19, 0xFA` → `0x40, 0x50`
