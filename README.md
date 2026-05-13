# TestPlugin - System Informer Plugin Template

[English](#english) | [Türkçe](#türkçe)

---

## English

This project is a minimal template designed for quickly developing new plugins for [System Informer](https://github.com/winsiderss/systeminformer).

### Features
- **Fast Start**: Plugin registration and basic configuration are ready.
- **Menu Integration**: Automatically adds an option to the "Tools" menu.
- **User Interface**: Includes an example dialog window that opens when clicked.

### How to Use?
1. **Copy Files**: Place this folder into the `plugins` directory of the System Informer source code.
2. **Include in Solution**: Open the `Plugins.sln` file with Visual Studio. (This template is already automatically included).
3. **Build**: Right-click the `TestPlugin` project in Visual Studio and select "Build".
4. **Test**: Run System Informer. You will see the `Test Plugin` option under the `Tools` menu.

### Project Structure
- `main.c`: Main entry point, menu registrations, and dialog procedures.
- `plugin.h`: Required header definitions.
- `resource.h` / `TestPlugin.rc`: UI resources and dialog design.
- `TestPlugin.def`: DLL export settings.
- `TestPlugin.vcxproj`: Visual Studio project file.

---

## Türkçe

Bu proje, [System Informer](https://github.com/winsiderss/systeminformer) için hızlıca yeni pluginler geliştirmeniz için hazırlanmış minimal bir şablondur.

### Özellikler
- **Hızlı Başlangıç**: Plugin kaydı ve temel yapılandırma hazır.
- **Menü Entegrasyonu**: "Tools" (Araçlar) menüsüne otomatik olarak bir seçenek ekler.
- **Kullanıcı Arayüzü**: Tıklandığında açılan örnek bir dialog penceresi içerir.

### Nasıl Kullanılır?
1. **Dosyaları Kopyalayın**: Bu klasörü System Informer kaynak kodundaki `plugins` dizinine yerleştirin.
2. **Çözüme Dahil Edin**: `Plugins.sln` dosyasını Visual Studio ile açın. (Bu şablon zaten otomatik olarak eklenmiştir).
3. **Derleyin (Build)**: Visual Studio üzerinden `TestPlugin` projesine sağ tıklayıp "Build" deyin.
4. **Test Edin**: System Informer'ı çalıştırın. `Tools` menüsünde `Test Plugin` seçeneğini göreceksiniz.

### Proje Yapısı
- `main.c`: Ana giriş noktası, menü kayıtları ve dialog işlemleri.
- `plugin.h`: Gerekli header tanımlamaları.
- `resource.h` / `TestPlugin.rc`: UI kaynakları ve dialog tasarımı.
- `TestPlugin.def`: DLL dışa aktarma (export) ayarları.
- `TestPlugin.vcxproj`: Visual Studio proje dosyası.

---
> [!NOTE]
> This plugin is already integrated into `Plugins.sln`. You just need to build it. / Bu plugin `Plugins.sln` dosyasına halihazırda entegre edilmiştir. Sadece derlemeniz yeterlidir.
