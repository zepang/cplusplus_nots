# cplusplus serious notes

First of all, it's important to find out why want to learn cplusplus.

In my point, I'm a front end developer, most of all language like Python, Java, Go and so on. Those languages are like Node.js in web development and I useing Node.js in my work frequently. So, I want to learn another language which is huge difference with Node.js.

Well, let's get start!

# ready you environment

system: Macos/Linux
tools: clang++
editor: VSCode

There are some preworks you must be do. Because VSCode is different with the ida visual studio. Visual studio have interg some usefull functionality, for example debug and build. On the VSCode, we must create related task and VSCode provide a friendly docs. For more information, look at under link:

- https://code.visualstudio.com/docs/editor/tasks
- https://code.visualstudio.com/docs/editor/tasks
- https://code.visualstudio.com/docs/editor/tasks

*tasks.json*:

```json
{
  "version": "2.0.0",
  "tasks": [
    {
      "type": "shell",
      "label": "Create debug output folder",
      "command": "if [ ! -d ${workspaceFolder}/debug/${relativeFileDirname} ]; then mkdir -p -m 777 ${workspaceFolder}/debug/${relativeFileDirname};fi"
    },
    {
      "type": "shell",
      "label": "C/C++: clang++ build active file",
      "command": "/usr/bin/clang++",
      "args": [
        "-std=c++17",
        "-stdlib=libc++",
        "-g",
        "${fileDirname}/*.cpp",
        "-o",
        "${workspaceFolder}/debug/${relativeFileDirname}/${fileBasenameNoExtension}",
        "-v"
      ],
      "options": {
        "cwd": "${fileDirname}"
      },
      "dependsOrder": "sequence",
      "dependsOn": ["Create debug output folder"],
      "problemMatcher": [
        "$gcc"
      ],
      "group": {
        "kind": "build",
        "isDefault": true
      }
    }
  ]
}
```

*launch.json*:

```json
{
  // Use IntelliSense to learn about possible attributes.
  // Hover to view descriptions of existing attributes.
  // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
  "version": "0.2.0",
  "configurations": [
    {
      "name": "clang++ - 生成和调试活动文件",
      "type": "cppdbg",
      "request": "launch",
      "program": "${workspaceFolder}/debug/${relativeFileDirname}/${fileBasenameNoExtension}",
      "args": [],
      "stopAtEntry": true,
      "cwd": "${fileDirname}",
      "environment": [],
      "externalConsole": false,
      "MIMode": "lldb",
      "preLaunchTask": "C/C++: clang++ build active file"
    }
  ]
}
```

