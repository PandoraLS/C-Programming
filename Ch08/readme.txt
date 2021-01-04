ch08_ex01.cpp编译的时候需要带上symbol_table.cpp和token.cpp，不然就会编译失败
对应的tasks.json如下：
"args": [
    "-g", 
    "${file}", "${workspaceFolder}\\token.cpp", "${workspaceFolder}\\symbol_table.cpp",
    "-o", 
    "${fileDirname}\\${fileBasenameNoExtension}.exe"
],
c_cpp_properities.json已经包含以下内容，所以不需要再次添加includePath了
"includePath": [
    "${workspaceFolder}/**"
],
编译链接其他程序的时候，多几个token.cpp和symbol_table.cpp这样的，其实并没有影响

