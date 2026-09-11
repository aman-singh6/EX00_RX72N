# Ex00_Rx72

RX72N (`R5F572NN`) 向けの、Renesas RX GCC と CMake を使用する講義用の最小プロジェクトです。`PORT9` の P95 と P96 を直接操作して LED を点滅させます。  
A minimal lecture project for the RX72N (`R5F572NN`) using Renesas RX GCC and CMake. It directly controls P95 and P96 on `PORT9` to blink LEDs.

## 構成 / Project layout

- `src/`: 講義で編集するアプリケーションコード / Application code edited during lectures
- `generate/`: RX72N 向けのスタートアップ、割り込みベクタ、レジスタ定義、リンカスクリプト / RX72N startup code, interrupt vectors, register definitions, and linker script
- `.vscode/launch.json`: E2/JTAG による VS Code 用ハードウェアデバッグ設定 / VS Code hardware-debug configuration for E2/JTAG
- `CMakeLists.txt`, `cross.cmake`: RX GCC 向けビルド設定 / RX GCC build configuration
- `build/`: CMake の生成物。Git 管理の対象外 / CMake output, excluded from Git

## 講義で編集する範囲 / Files to edit in lectures

通常の演習では `src/Ex00_Rx72.c` を編集します。レジスタを直接操作する記述は、RX の GPIO と周辺機能の理解を目的とした講義用の方針です。ドライバ層への抽象化は行いません。  
For normal exercises, edit `src/Ex00_Rx72.c`. Direct register access is intentional for learning RX GPIO and peripheral behavior; do not introduce a driver abstraction layer.

`generate/` は起動、例外・割り込みベクタ、デバイス定義を含むため、ベクタや起動処理を扱う回以外では変更しません。`generate/linker_script.ld` は、デバッグ時にオプション設定メモリ (OFS) をダウンロード対象から除外します。  
`generate/` contains startup, exception and interrupt vector, and device-definition files. Do not edit it except in lessons about vectors or startup. `generate/linker_script.ld` excludes option-setting memory (OFS) from debug downloads.

## 初回環境構築 / Initial setup

初回セットアップ時に、各講義用 PC へ次をインストールします。GCC for Renesas RX は `cross.cmake` が参照する既定の場所に導入します。  
During initial setup, install the following on every lecture PC. Install GCC for Renesas RX in the default location referenced by `cross.cmake`.

- VS Code と Renesas 拡張機能 / VS Code and the Renesas extension
- GCC for Renesas RX 8.3.0.202411-GNURX-ELF: `C:\ProgramData\GCC for Renesas RX 8.3.0.202411-GNURX-ELF`
- CMake と Ninja / CMake and Ninja
- Renesas E2 Emulator 用ドライバおよび Debug Support / Renesas E2 Emulator driver and Debug Support

この配置はツールチェーンのシステム導入に管理者権限を要する場合があります。一方、リポジトリの clone、ビルド生成物、Renesas 拡張機能のユーザー設定は、通常ユーザー権限でユーザーディレクトリ配下に保持できます。  
This installation location may require administrator rights for the toolchain installation. Repository clones, build outputs, and per-user Renesas extension settings can normally be kept under the user's profile without administrator rights.

## ビルドとデバッグ / Build and debug

リポジトリを任意の作業フォルダへ clone して VS Code で開き、`Build Project` を実行します。初回ビルド時に `build/` が生成されます。  
Clone the repository into any working folder, open it in VS Code, and run `Build Project`. The first build creates `build/`.

デバッグ構成 `Debug (E2 / JTAG)` はビルド後に `build/Ex00_Rx72.elf` を E2 経由で実行します。この構成は E2 からターゲットへ給電しないため、デバッグ前に対象基板を外部から給電してください。  
The `Debug (E2 / JTAG)` configuration builds and runs `build/Ex00_Rx72.elf` through the E2. It does not power the target from the E2, so externally power the target board before debugging.

## Git 管理対象 / Git scope

VS Code 運用では `.project`、`.cproject`、`.settings/`、`.metadata/`、`Ex00_Rx72 HardwareDebug.launch` は不要な e2 studio 用メタデータです。これらと `build/` は `.gitignore` で除外します。  
For the VS Code workflow, `.project`, `.cproject`, `.settings/`, `.metadata/`, and `Ex00_Rx72 HardwareDebug.launch` are unnecessary e2 studio metadata. These files and `build/` are excluded by `.gitignore`.