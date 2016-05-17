# Israfil
[![neutrino](https://img.shields.io/badge/Coded%20with-Neutrino%20IDE-brightgreen.svg?style=flat-square)](https://github.com/LER0ever/Neutrino)
![license](https://img.shields.io/badge/license-GPL%20V3-yellowgreen.svg?style=flat-square)
![israfil](https://img.shields.io/badge/LER0ever-Project%20Israfil-blue.svg?style=flat-square)
![AP](https://img.shields.io/badge/Angels-Parliament-ff69b4.svg?style=flat-square)

## LER0ever Project Israfil  
Provide Unified Music Service for users in China.  

由于版权问题，QQ音乐、网易云等音乐平台有部分歌曲无法播放。**Project Israfil通过实现各大音乐平台的API来提供统一的音乐服务，消除因版权导致的不方便.**

## IN EARLY DEVELOPMENT  
### 早期开发尚不可使用！
Project Israfil只是本人的练笔之作，为了熟悉一下Go语言和Qt的开发，研究音乐平台协议只是顺手 ;)  
如本项目有侵权行为，请和我联系，我会立刻删除Repo  
  
### About
Israfil Core API: Go语言编写，Go-Pie插件机制，适合部署到服务器端提供统一的API  
Israfil App: (不依赖Golang的CoreAPI) Qt, QML, Material Design, **早期开发中**。  

## Israfil 进度  
| 协议       | 功能                                               | 完成情况 |
| :---:      | :---:                                              | :---:    |
| 网易云音乐 | 通过歌曲ID获得各个清晰度的DFSID                    | 100%     |
| 网易云音乐 | 通过歌曲ID获取歌手信息，头像，歌手ID               | 100%     |
| 网易云音乐 | 通过歌曲ID，获取专辑信息，图片，ID                 | 100%     |
| 网易云音乐 | **通过歌曲DFSID计算出各个清晰度MP3绝对链接地址**   | 100%     |
| 网易云音乐 | 搜索歌曲，获得歌曲ID列表                           | 80%      |
| QQ音乐     | 搜索歌曲，获得歌曲SID列表                          | 60 %     |
| QQ音乐     | **通过SID计算音乐文件下载路径，包括无损Flac、APE** | 80%      |
| QQ音乐     | 协议研究                                           | 80%      |
| 虾米音乐   | 协议研究                                           | 60%      |
| 百度音乐   | 公开协议，播放限制                                 | 100%     |
| UI         | qml-material 初步界面demo 及 qml文件的资源打包     | 60%      |
| HTTPAPI    | 框架                                               | 40%      |
| HTTPAPI    | **已经可以搜索网易和QQ音乐的详细信息**             | 80%      |
| QtApp      | 基础代码                                           | 60%      |


## Israfil编译
### 准备环境
Windows: Qt官网(qt.io)下载Qt For Windows并安装  
Linux: sudo $包管理安装命令 qt5-default (如```sudo apt-get install qt5-default```, ```sudo pacman -S qt5-default```)  
OS X: ```brew install qt5``` (需要手动加入环境变量) 或者官网下载安装包安装  
### 编译
```
git clone https://github.com/LER0ever/Israfil
cd Israfil && mkdir build && cd build
qmake ..
make # or mingw32-make on Windows
```
或者用Qt-Creator打开Israfil.pro，Release模式构建所有项目.  

## Contributions are always welcome
See [contribute.md](https://github.com/LER0ever/Israfil/blob/develop/doc/contribute.md)

## CI Status  
| Platform | Qt & Compiler     | Status                                                                                        |
| :---:    | :---:             | :---:                                                                                         |
| Linux    | 5.6 Clang         | ![traviscistatus](https://api.travis-ci.org/LER0ever/Israfil.svg)                             |
| Linux    | 5.6 GCC           | ![traviscistatus](https://api.travis-ci.org/LER0ever/Israfil.svg)                             |
| OS X     | 5.6 Clang         | ![traviscistatus](https://api.travis-ci.org/LER0ever/Israfil.svg)                             |
| Windows  | 5.5 MinGW         | ![appvayorstatus](https://img.shields.io/badge/build-unknown-lightgrey.svg?style=flat-square) |
| Windows  | 5.5 MSVC 2013 x86 | ![shield](https://img.shields.io/badge/build-unknown-lightgrey.svg?style=flat-square)         |
| Windows  | 5.5 MSVC 2013 x64 | ![shield](https://img.shields.io/badge/build-unknown-lightgrey.svg?style=flat-square)         |
(CI脚本待修复)  

## Copyright
| 3rd party              | License | Sub-Project | in source            |
| :---:                  | :---:   | :---:       | :---:                |
| natefinch/pie          | MIT     | HttpAPI     | Embedded in source   |
| ddliu/go-httpclient    | MIT     | HttpAPI     | Need manual go get   |
| papyros/qml-material   | LGPL2   | IsrafilApp  | Embedded in source   |
| fengleyl/NetEase       | MIT     | IsrafilApp  | Uses Part of Code    |
| Qt Project             | LGPL2   | IsrafilApp  | Universal Dependency |
| bidstack/bidstack-http | UNKNOWN | IsrafilApp  | Embedded in source   |

网易云音乐API参考了[网易云音乐API分析](https://github.com/yanunon/NeteaseCloudMusic/wiki/%E7%BD%91%E6%98%93%E4%BA%91%E9%9F%B3%E4%B9%90API%E5%88%86%E6%9E%90)
网易云音乐新版API正在学习中...  

### LICENSE
GNU GENERAL PUBLIC LICENSE V3
