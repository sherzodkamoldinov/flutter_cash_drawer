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

MIT License

Copyright (c) 2025 Sherco

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

---

## 📲 Обратная связь / Автор

Автор: Sherco
GitHub: [github.com/sherzodkamoldinov](https://github.com/sherzodkamoldinov)

---

## 🎡 Советы по использованию

* Убедитесь, что ваш ESC-принтер установлен в Windows
* Проверьте имя принтера через `wmic printer get name`
* Обычные команды ESC работают почти на всех Xprinter, GPrinter, POS80 и т.д.
* Если не открывается — попробуйте изменить тайминги в байтах команды: `0x19, 0xFA` → `0x40, 0x50`
