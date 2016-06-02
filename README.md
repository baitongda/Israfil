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

## 关于这个项目
IsrafilCore: (./IsrafilCore)C++11编写，提供音乐服务接口给IsrafilApp, **早期开发中**  
Israfil App: Qt, QML, Material Design, **超早期开发中**。  
_Israfil HTTP API: (./HttpAPI)独立子项目，Go语言编写，Go-Pie插件机制，适合部署到服务器端提供统一的API **目前完成了网易和qq的搜索与下载地址获取，短期不更新**_

## Israfil 进度  
| 项目        | 协议       | 已完成                       | 测试         | 完成时间   |
| :---:       | :---:      | :---:                        | :---:        | :---:      |
| IsrafilCore | HTTPClient | 自定义header发送GET/POST请求 | test-network | 2016-05-28 |
| IsrafilCore | QQ音乐     | 搜索歌曲获得下载链接         | test-qqmusic | 2016-06-02 |
| HTTPAPI     | 网易云音乐 | 搜索歌曲获得下载链接         | -            | 2016-04-15 |
| HTTPAPI     | QQ音乐     | 搜索歌曲获得下载链接         | -            | 2016-04-15 |

| 项目        | 协议       | 功能                                               | 完成情况 |
| :---:       | :---:      | :---:                                              | :---:    |
| IsrafilCore | 网易云音乐 | 搜索歌曲                                           | 30%      |
| IsrafilCore | 虾米音乐   | 协议研究                                           | 60%      |
| IsrafilAPP  | UI         | qml-material 初步界面demo 及 qml文件的资源打包     | 60%      |
| HTTPAPI     | Universal  | **已经可以搜索网易和QQ音乐的详细信息**             | 80%      |
| HTTPAPI     | 网易云音乐 | 通过歌曲ID获得各个清晰度的DFSID                    | 100%     |
| HTTPAPI     | 网易云音乐 | 通过歌曲ID获取歌手信息，头像，歌手ID               | 100%     |
| HTTPAPI     | 网易云音乐 | 通过歌曲ID，获取专辑信息，图片，ID                 | 100%     |
| HTTPAPI     | 网易云音乐 | **通过歌曲DFSID计算出各个清晰度MP3绝对链接地址**   | 100%     |
| HTTPAPI     | 网易云音乐 | 搜索歌曲，获得歌曲ID列表                           | 80%      |
| HTTPAPI     | QQ音乐     | 搜索歌曲，获得歌曲SID列表                          | 60 %     |
| HTTPAPI     | QQ音乐     | **通过SID计算音乐文件下载路径，包括无损Flac、APE** | 100%     |

## Israfil编译
### 准备环境
Windows: Qt官网(qt.io)下载Qt For Windows并安装  
Linux: sudo $包管理安装命令 qt5-default (如```sudo apt-get install qt5-default```, ```sudo pacman -S qt5```)  
OS X: ```brew install qt5``` (需要手动加入环境变量) 或者官网下载安装包安装  
### 编译
```
git clone https://github.com/LER0ever/Israfil
cd Israfil && mkdir build  
cd build && qmake ..
make
```
或者用Qt-Creator打开Israfil.pro，Release模式构建所有项目.  

## Contributions are always welcome
See [contribute.md](https://github.com/LER0ever/Israfil/blob/develop/doc/contribute.md)

## CI Status  
| Platform | Qt & Compiler       | Status                                                                                      |
| :---:    | :---:               | :---:                                                                                       |
| Linux    | 5.6 Clang & GCC     | ![traviscistatus](https://api.travis-ci.org/LER0ever/Israfil.svg)                           |
| OS X     | 5.6 Clang & GCC     | ![traviscistatus](https://api.travis-ci.org/LER0ever/Israfil.svg)                           |
| Windows  | 5.5 MinGW gcc       | ![appvayorstatus](https://ci.appveyor.com/api/projects/status/14ny9o50m4xb0c6g) |
| Android  | 5.5 gcc androideabi | ![shield](https://img.shields.io/badge/build-unknown-lightgrey.svg?style=flat-square)       |

## Copyright
| 3rd party            | License | Sub-Project | in source            |
| :---:                | :---:   | :---:       | :---:                |
| papyros/qml-material | LGPL2   | IsrafilApp  | Embedded in source   |
| Qt Project           | LGPL2   | IsrafilApp  | Universal Dependency |
| JosephP91/curlcpp    | MIT     | IsrafilCore | Embedded in source   |
| natefinch/pie        | MIT     | HttpAPI     | Embedded in source   |
| ddliu/go-httpclient  | MIT     | HttpAPI     | Need manual go get   |

网易云音乐API参考了[网易云音乐API分析](https://github.com/yanunon/NeteaseCloudMusic/wiki/%E7%BD%91%E6%98%93%E4%BA%91%E9%9F%B3%E4%B9%90API%E5%88%86%E6%9E%90)
网易云音乐新版API正在学习中...  

### LICENSE
GNU GENERAL PUBLIC LICENSE V3
