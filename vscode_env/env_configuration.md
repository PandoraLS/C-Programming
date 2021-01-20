# vscode_env_c

vs code 配置C++ 环境

TODO 需要移动到github.io上

参考链接：
[官方配置链接](https://code.visualstudio.com/docs/cpp/config-mingw)

[整理：Visual Studio Code (vscode) 配置C、C++环境/编写运行C、C++（主要Windows、简要Linux）
](https://blog.csdn.net/bat67/article/details/76095813)


需要注意的地方：

- 下载安装
    - 安装mingw64的时候，在线安装使用的是外网，所以安装的过程会出现下载失败的情况，可以先下载，然后直接解压配置。

    - [官方下载地址](http://mingw-w64.org/doku.php/download)
    - [sourceforge](https://sourceforge.net/projects/mingw-w64/files/mingw-w64/mingw-w64-release/)

    - sourceforge翻到最下面可以下载不同版本的压缩包，不同版本格式说明见[知乎](https://zhuanlan.zhihu.com/p/105135431)

- 环境变量添加
    - 需要将解压的路径添加到系统环境变量中的Path中,比如在环境变量中添加`C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin`

- 配置`.vscode`
    - 配置  c_cpp_properties.json 参考
    ```json
    {
    "configurations": [
      {
        "name": "Win32",
        "includePath": [
            "${workspaceFolder}/**",
            "C:/software/mingw-w64/i686-8.1.0-release-posix-dwarf-rt_v6-rev0/mingw32/lib/gcc/i686-w64-mingw32/8.1.0/include",
            "C:/software/mingw-w64/i686-8.1.0-release-posix-dwarf-rt_v6-rev0/mingw32/lib/gcc/i686-w64-mingw32/8.1.0/include/c++",
            "C:/software/mingw-w64/i686-8.1.0-release-posix-dwarf-rt_v6-rev0/mingw32/lib/gcc/i686-w64-mingw32/8.1.0/include/c++/i686-w64-mingw32",
            "C:/software/mingw-w64/i686-8.1.0-release-posix-dwarf-rt_v6-rev0/mingw32/lib/gcc/i686-w64-mingw32/8.1.0/include/c++/backward",
            "C:/software/mingw-w64/i686-8.1.0-release-posix-dwarf-rt_v6-rev0/mingw32/include",
            "C:/software/mingw-w64/i686-8.1.0-release-posix-dwarf-rt_v6-rev0/mingw32/lib/gcc/i686-w64-mingw32/8.1.0/include-fixed"
        ],
        "defines": ["_DEBUG", "UNICODE", "_UNICODE"],
        "windowsSdkVersion": "10.0.18362.0",
        "compilerPath": "C:/software/mingw-w64/i686-8.1.0-release-posix-dwarf-rt_v6-rev0/mingw32/bin/gcc.exe",
        "cStandard": "c11",
        "cppStandard": "c++17",
        "intelliSenseMode": "gcc-x86",
        "browse": {
          "path": [
            "C:/software/mingw-w64/i686-8.1.0-release-posix-dwarf-rt_v6-rev0/mingw32/lib/gcc/i686-w64-mingw32/8.1.0/include",
            "C:/software/mingw-w64/i686-8.1.0-release-posix-dwarf-rt_v6-rev0/mingw32/lib/gcc/i686-w64-mingw32/8.1.0/include-fixed",
            "C:/software/mingw-w64/i686-8.1.0-release-posix-dwarf-rt_v6-rev0/mingw32/include/*"
          ]
        }
      }
    ],
    "version": 4
  }
    ```

  - 配置 launch.json 参考
  ```json
  {
    "version": "0.2.0",
    "configurations": [
      {
        "name": "g++.exe - Build and debug active file",
        "type": "cppdbg",
        "request": "launch",
        "program": "${workspaceFolder}/${fileBasenameNoExtension}.exe",// 将要进行调试的程序的路径 
        "args": [],
        "stopAtEntry": false,
        "cwd": "${workspaceFolder}",
        "environment": [],
        "externalConsole": true, // 调试时是否显示控制台窗口，一般设置为true显示控制台 
        "MIMode": "gdb",
        "miDebuggerPath": "C:\\software\\mingw-w64\\i686-8.1.0-release-posix-dwarf-rt_v6-rev0\\mingw32\\bin\\gdb.exe",
        "setupCommands": [
          {
            "description": "Enable pretty-printing for gdb",
            "text": "-enable-pretty-printing",
            "ignoreFailures": true
          }
        ],
        "preLaunchTask": "C/C++: g++.exe build active file"
      }
    ]
  }
  ```

  - 配置 task.json 参考
  ```json
  {
    "version": "2.0.0",
    "tasks": [
        {
            "type": "shell",
            "label": "C/C++: g++.exe build active file",
            "command": "C:\\software\\mingw-w64\\i686-8.1.0-release-posix-dwarf-rt_v6-rev0\\mingw32\\bin\\g++.exe",
            "args": ["-g", "${file}", "-o", "${fileDirname}\\${fileBasenameNoExtension}.exe"],
            "options": {
                "cwd": "C:\\software\\mingw-w64\\i686-8.1.0-release-posix-dwarf-rt_v6-rev0\\mingw32\\bin"
            },
            "problemMatcher": ["$gcc"],
            "group": {
            "kind": "build",
            "isDefault": true
            }
        }
    ]
  }
  ```

已经配置好的例子放在`.vscode/`中